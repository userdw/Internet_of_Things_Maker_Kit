# [ENGLISH] Project 09: Smart Access -> Smart Token
This project will guide you to make a simple smart token system, in real life we can meet an application like smart token system using rfid like e-Money. For simply we have one card with money value inside of it, then each time we attach it into the rfid reader the amount of balance will decrease. In this project we will utilize the [MFRC522](https://www.nxp.com/docs/en/data-sheet/MF1S50YYX_V1.pdf).

<img src="/images/09_smart_access.png" height="250">

The system in this project will display it to serial monitor from Arduino IDE like picture shown below.

<img src="/images/smart_token.PNG" height="400">

### In this project you will need:
* ESP8266 IoT V2.0 (1),
* RFID Reader Module (1).

### Assemble the modules following these steps:
1. Connecting the jumper cable from RFID reader to ESP8266 IoT V2.0 like the image shown above.
2. Upload the [Write Card](/09_Smart_Access/2_Write_card) code into ESP8266 IoT V2.0, then ESP8266 board is act like a machine to write a balance into it.
3. Upload the [Smart Token](/09_Smart_Access/Smart_Token) code into ESP8266 IoT V2.0.

If there are no mistakes, system will start to read your tag. 

# [BAHASA INDONESIA] Proyek 09: Smart Access -> Smart Token
Proyek ini akan memandu anda untuk membuat sistem token cerdas yang sederhana, dalam kehidupan nyata kita bisa menjumpai aplikasi seperti smart token system menggunakan RFID seperti e-Money. Karena hanya ada satu kartu dengan nilai uang di dalamnya, maka setiap kali kita memasukkannya ke pembaca rfid maka jumlah saldo akan berkurang. Dalam proyek ini, kita akan menggunakan [MFRC522](https://www.nxp.com/docs/en/data-sheet/MF1S50YYX_V1.pdf).

<img src="/images/09_smart_access.png" height="250">

Sistem dalam proyek ini akan menampilkan pembacaan data ke serial monitor dari Arduino IDE.

<img src="/images/smart_token.PNG" height="400">

### Modul-modul yang dibutuhkan pada proyek ini:
* ESP8266 IoT V2.0 (1),
* RFID Reader Module (1).

### Hubungkan modul-modul di atas mengikuti langkah-langkah di bawah ini:
1. Menghubungkan kabel jumper dari pembaca RFID ke ESP8266 IoT V2.0 seperti gambar di atas.
2. Upload kode [Write card] (/09_Smart_Access/2_Write_card) ke ESP8266 IoT V2.0, maka ESP8266 bertindak seperti mesin yang menuliskan sejumlah saldo didalamnya.
3. Upload kode [Smart Token] (/09_Smart_Access/Smart_Token) ke dalam ESP8266 IoT V2.0.



