# [ENGLISH] Project 09: Smart Access
Radio Frequency Identification (RFID) technology is an automated data capture technology that identifies labeled or tagged objects wirelessly. The system consists of an RFID tag and an RFID tag reader that relays the information on the tag, in digital form, to a computer system. Unlike bar-code labels, which can only function if the bar-code is oriented towards the scanner and the scanner “sees” the bar-code.  while RFID tags can  work within multiple feet distance of a querying reader (depending on type from the tag), and multiple tags can be read at once. In this project we will show how to build a simple Smart Access System and Smart Token System . The system in this project will utilize the [MFRC522](https://www.nxp.com/docs/en/data-sheet/MF1S50YYX_V1.pdf) and display it to serial monitor from Arduino IDE. There is 4 project inside of Smart Access below :

* **Read Card**		  : describe about how to read rfid tag(card and key)
* **Write Card**	  : describe about how to write data into rfid tag.
* **Smart Access**	  : describe about how to read rfid tag and stored it to registered user device
* **Smart Token**	  : describe about how to make a simple system like e-Money

<img src="/images/09_smart_access_2.png" height="400">

First if you want to develop some application using MIFARE 1K tag, you must read the [datasheet](/09_Smart_Access/Datasheet) especially on page 7-10 on chapter 8. You will find the image below :

<img src="/images/memory_organization_mifare1k.PNG" height="600">

The image shown above describe about the memory structure of mifare 1k tag, it will help you to knows the memory address which available to use in case write data to it. Mifare 1K tag have 16 sector, 4 block each sector and 16 byte number in each block. Some of block are used by trailer block, key block (key A & B) and NUID block. The data can be write outside of trailer block,key block, and NUID block.

### In this project you will need:
* ESP8266 IoT V2.0 (1),
* RFID Reader Module (1).

# [BAHASA INDONESIA] Proyek 09: Smart Access
Teknologi identifikasi frekuensi radio (RFID)  adalah teknologi menangkap data otomatis yang mengidentifikasi objek label atau sebuah tagged nirkabel. Sistem ini terdiri dari sebuah RFID tag dan tag RFID reader yang me-relay informasi pada tag, dalam bentuk digital, ke sebuah sistem komputer. Tidak seperti label **Barcode**, yang hanya dapat berfungsi jika kode bar ini berorientasi ke scanner dan scanner "membaca" kode bar tersebut. Sementara RFID tag dapat melakukan pembacaan data dalam jarak beberapa kaki dari RFID reader tag (tergantung jenis dari tag), dan dapat membaca beberapa tag sekaligus. Dalam proyek ini kita akan menunjukkan bagaimana membangun sistem akses pintar dan sistem . Sistem dalam proyek ini akan menggunakan [MFRC522](https://www.nxp.com/docs/en/data-sheet/MF1S50YYX_V1.pdf) dan menampilkannya ke serial monitor dari Arduino IDE. Terdapat 4 file projek untuk Smart Access yaitu :

* **Read Card**		  : menjelaskan tentang cara membaca rfid tag.
* **Write Card**	  : menjelaskan tentang bagaimana menuliskan data ke dalam rfid tag.
* **Smart Access**	: menjelaskan tentang cara membaca dan menyimpan data rfid tag sebagai perangkat pengguna yang terdaftar.
* **Smart Token**	  : menjelaskan tentang cara membuat sistem e-Money sederhana.


<img src="/images/09_smart_access_2.png" height="400">

Pertama jika Anda ingin mengembangkan beberapa aplikasi dengan menggunakan tag MIFARE 1K, Anda harus membaca [datasheet](/09_Smart_Access/Datasheet) terutama di halaman 7-10 pada bab 8. Anda akan menemukan gambar di bawah ini:

<img src = "/images/memory_organization_mifare1k.PNG" height = "600">

Gambar yang ditunjukkan di atas menjelaskan tentang struktur memori dari tag mifare 1k, ini akan membantu Anda mengetahui alamat memori yang tersedia untuk digunakan untuk menulis data ke dalamnya. Tag Mifare 1K memiliki 16 sektor, 4 blok masing-masing sektor dan 16 byte di setiap blok. Beberapa blok digunakan oleh blok trailer, blok kunci(kunci A & B) dan blok NUID. Data bisa ditulis di luar blok trailer, blok kunci, dan blok NUID.

### Modul-modul yang dibutuhkan pada proyek ini:
* ESP8266 IoT V2.0 (1),
* RFID Reader Module (1).
