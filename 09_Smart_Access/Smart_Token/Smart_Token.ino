/*
   -------------------------------------------------
               MFRC522      Arduino       ESP8266
               Reader/PCD   Uno/101       IoT
   Signal      Pin          Pin           Pin
   -------------------------------------------------
   RST/Reset   RST          9             5
   SPI SS      SDA(SS)      10            15
   SPI MOSI    MOSI         11            13
   SPI MISO    MISO         12            12
   SPI SCK     SCK          13            SCL
*/

#include <MFRC522.h>//include the RFID reader library
#include <SPI.h>
#define SS_PIN 15                             //slave select pin
#define RST_PIN 5                             //reset pin
MFRC522 mfrc522(SS_PIN, RST_PIN);             // instatiate a MFRC522 reader object.
MFRC522::MIFARE_Key key;                      //create a MIFARE_Key struct named 'key', which will hold the card information

String stored_value, jumlahStr;
int block = 62, size_value, jumlah ;;         //this is the block number we will write into and then read. Do not write into 'sector trailer' block, since this can make the block unusable.
byte readbackblock[18];                       //This array is used for reading out a block. The MIFARE_Read method requires a buffer that is at least 18 bytes to hold the 16 bytes of a block.
byte clear_blockcontent[16] = {0, 0, 0, 0,    //This Array for clear the block content
                               0, 0, 0, 0,
                               0, 0, 0, 0,
                               0, 0, 0, 0
                              };
char charBuf[9];
byte data[16] = {charBuf[0], charBuf[1],      //This Array used for save value as buffer
                 charBuf[2], charBuf[3],
                 charBuf[4], charBuf[5],
                 charBuf[6], charBuf[7]
                };
byte blockcontent[16] = {data[0], data[1],    //This Array used for save data before execute the writeblock method
                         data[2], data[3],
                         data[4], data[5],
                         data[6], data[7]
                        };
void setup() {
  Serial.begin(9600);        // Initialize serial communications with the PC
  SPI.begin();
  mfrc522.PCD_Init();        // Init MFRC522 card (in case you wonder what PCD means: proximity coupling device)
  Serial.println("Scan a MIFARE Classic card");

  // Prepare the security key for the read and write functions
  // Since the cards in the kit are new and the keys were never defined, they are 0xFF

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;//keyByte is defined in the "MIFARE_Key" 'struct' definition in the .h file of the library
  }
}

void loop()
{

  /*****************************************establishing contact with a tag/card**********************************************************************/
  // Look for new cards (in case you wonder what PICC means: proximity integrated circuit card)
  if ( ! mfrc522.PICC_IsNewCardPresent()) {//if PICC_IsNewCardPresent returns 1, a new card has been found and we continue
    return;//if it did not find a new card is returns a '0' and we return to the start of the loop
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {//if PICC_ReadCardSerial returns 1, the "uid" struct (see MFRC522.h lines 238-45)) contains the ID of the read card.
    return;//if it returns a '0' something went wrong and we return to the start of the loop
  }
  Serial.println("Card selected");
  /*****************************************writing and reading a block on the card**********************************************************************/

  readBlock(block, readbackblock);//read the block back
  Serial.print("Read money: ");
  stored_value = "";
  for (int j = 0 ; j < 16 ; j++)            //print the block contents
  {
    Serial.write (readbackblock[j]);        //Serial.write() transmits the ASCII numbers as human readable characters to serial monitor
    stored_value = stored_value +
                   char(readbackblock[j]);  //Convert value from array into character
  }
  size_value = sizeof(stored_value);
  jumlah = stored_value.toInt() - 1000;     // 1000 is amount to substract with amount that has been read
  Serial.println(" ");
  jumlahStr = String(jumlah);
  jumlahStr.toCharArray(charBuf, 9);
  Serial.print("Last Amount : ");
  Serial.println(charBuf);
  if (jumlah <= 0) {
    jumlah = 0;
    writeBlock(block, clear_blockcontent);
    Serial.println("Your Amount : 0");
    Serial.println("Please refill your amount first");
  }
  //  Execute when value > 99.999
  else if (jumlah < 99999 && jumlah != 0) {
    if (data[5] == 0 || data[6] == 0) {
      byte data_custom[16] = {charBuf[0], charBuf[1], charBuf[2],
                              charBuf[3], charBuf[4], 0, 0, 0
                             };
      writeBlock(block, data_custom);
    } else {
      read_amount();
    }
  }
  //  Execute when 999.999 < value > 99.999
  else if (jumlah < 999999 && jumlah > 99999) {
    if (data[6] == 0 || data[7] == 0) {
      byte data_custom[16] = {charBuf[0], charBuf[1], charBuf[2],
                              charBuf[3], charBuf[4], charBuf[5],
                              0, 0
                             };
      writeBlock(block, data_custom);
    } else {
      read_amount();
    }
  }
  else  {
    if (data[8] == 0) {
      byte data_custom[16] = {charBuf[0], charBuf[1], charBuf[2], charBuf[3],
                              charBuf[4], charBuf[5], charBuf[6], charBuf[7]
                             };
      writeBlock(block, data_custom);
    } else {
      writeBlock(block, blockcontent);
      read_amount();
    }
  }
  ESP.wdtDisable();
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); //uncomment this if you want to see the entire 1k memory with the block written into it.
  ESP.wdtEnable(1000);

  // Halt PICC
  mfrc522.PICC_HaltA();

  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();
  Serial.println("");
}
void read_amount() {
  readBlock(block, readbackblock);//read the block back
  for (int j = 0 ; j < 16 ; j++) //print the block contents
  {
    Serial.write (readbackblock[j]);//Serial.write() transmits the ASCII numbers as human readable characters to serial monitor
  }
  Serial.println("");
}

int writeBlock(int blockNumber, byte arrayAddress[])
{
  //this makes sure that we only write into data blocks. Every 4th block is a trailer block for the access/security info.
  int largestModulo4Number = blockNumber / 4 * 4;
  int trailerBlock = largestModulo4Number + 3; //determine trailer block for the sector
  if (blockNumber > 2 && (blockNumber + 1) % 4 == 0) {
    Serial.print(blockNumber);//block number is a trailer block (modulo 4); quit and send error code 2
    Serial.println(" is a trailer block: ");
    return 2;
  }
  Serial.print(blockNumber);
  Serial.println(" is a data block: ");

  /*****************************************authentication of the desired block for access***********************************************************/
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("PCD_Authenticate() failed: ");
    return 3;//return "3" as error message
  }

  /*****************************************writing the block***********************************************************/

  status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);//valueBlockA is the block number, MIFARE_Write(block number (0-15), byte array containing 16 values, number of bytes in block (=16))
  if (status != MFRC522::STATUS_OK) {
    Serial.print("MIFARE_Write() failed: ");
    return 4;//return "4" as error message
  }
  Serial.println("Block was written");
}


int readBlock(int blockNumber, byte arrayAddress[])
{
  int largestModulo4Number = blockNumber / 4 * 4;
  int trailerBlock = largestModulo4Number + 3; //determine trailer block for the sector

  /*****************************************authentication of the desired block for access***********************************************************/
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("PCD_Authenticate() failed (read): ");
    return 3;//return "3" as error message
  }

  /*****************************************reading a block***********************************************************/

  byte buffersize = 18;//we need to define a variable with the read buffer size, since the MIFARE_Read method below needs a pointer to the variable that contains the size...
  status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);//&buffersize is a pointer to the buffersize variable; MIFARE_Read requires a pointer instead of just a number
  if (status != MFRC522::STATUS_OK) {
    Serial.print("MIFARE_read() failed: ");
    return 4;//return "4" as error message
  }
  Serial.println("Block was read");
}
