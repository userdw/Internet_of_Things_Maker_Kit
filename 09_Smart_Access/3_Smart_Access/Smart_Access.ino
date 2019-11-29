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

#include <MFRC522.h>

constexpr uint8_t RST_PIN = 5;          // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = 15;          // Configurable, see typical pin layout above

byte knownTag[4] = {128, 217, 221, 26}; // Known NUID tag from Last Scan3
byte knownTag2[4] = {165, 8, 226, 82}; // Known NUID tag from Last Scan3

MFRC522 rfid(SS_PIN, RST_PIN);          // Instance of the class

MFRC522::MIFARE_Key key;

// Init array that will store new NUID
byte nuidPICC[4];

void setup() {
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  digitalWrite(4, HIGH);
  Serial.println(F("This code scan the MIFARE Classsic NUID."));
  Serial.print(F("Using the following key:"));
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
}

void loop() {

  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  if (rfid.uid.uidByte[0] != nuidPICC[0] ||
      rfid.uid.uidByte[1] != nuidPICC[1] ||
      rfid.uid.uidByte[2] != nuidPICC[2] ||
      rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("A new card has been detected."));
    Serial.println(F("The NUID tag is:"));
    Serial.print(F("In hex: "));
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    Serial.print(F("In dec: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
      if ((knownTag[i] == nuidPICC[i])) {
        Serial.println("WELCOME HOME SIR! :) HAVE A GOOD REST");
      }
      else if ((knownTag2[i] == nuidPICC[i])) {
        Serial.println("WELCOME HOME SIR! :)");
      }
      else {
        Serial.println("ARE YOU STRANGER ?");
      }
    }
  }
  else Serial.println(F("Card read previously."));

  //  ESP.wdtDisable();
  //  rfid.PICC_DumpToSerial(&(rfid.uid)); //uncomment this if you want to see the entire 1k memory with the block written into it.
  //  ESP.wdtEnable(1000);

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}


/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
   Helper routine to dump a byte array as dec values to Serial.
*/
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
