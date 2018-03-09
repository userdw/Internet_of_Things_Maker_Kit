# [ENGLISH] Project 2: Click Counter
***Please note that some parts in this project are not available in Internet of Things Maker Kit. They are available in [Arduino Maker Kit](https://github.com/userdw/Arduino_Maker_Kit).***

On the last project we learned how to control output pin on ESP8266 by uploading a program that blinks a LED and changing LED's brightness. In this project we will learn how to count a click (reading an input pin) on a button using ESP8266 IoT v2.0. This project will use LED Module which will blink as many as the number of clicks the Digital Push Button gets. Also, in this project we will utilize the built in Arduino function called **millis()** to debouce the Digital Push Button.

### In this project you will need:
* ESP8266 IoT v2.0 (1),
* ESP8266 Expansion Shield (1),
* LED Module (1),
* Digital Push Button (1).

<img src="/images/02_click_counter.png" height="400">

### Assemble the modules following these steps:
1. Plug the ESP8266 Expansion Shield to the top of ESP8266 IoT v2.0,
2. Plug the LED Module to the header on the ESP8266 Expansion Shield labelled **4**,
3. Plug the Digital Push Button to the header on the ESP8266 Expansion Shield labelled **3**,
4. Upload the [Click_Counter](/02_Click_Counter/Click_Counter) code into ESP8266 IoT v2.0.

If there are no mistakes, LED Module should blink according to the number of clicks given to the Digital Push Button.

# [BAHASA INDONESIA] Proyek 2: Click Counter
***Beberapa peralatan yang digunakan pada proyek ini tidak tersedia pada Internet of Things Maker Kit. Peralatan-peralatan tersebut terdapat pada [Arduino Maker Kit](https://github.com/userdw/Arduino_Maker_Kit).***

Pada proyek sebelumnya, kita telah belajar bagaimana mengendalikan pin output pada ESP8266 dengan cara meng-upload kode program yang mengedipkan LED serta mengubah tingkat kecerahan LED. Pada proyek ini akan dibahas bagaimana kita menghitung klik (membaca pin input) pada sebuah tombol menggunakan ESP8266 IoT v2.0. Proyek ini menggunakan LED Module yang akan berkedip sebanyak penekanan yang kita berikan pada Digital Push Button. Proyek ini juga menggunakan fungsi internal dari Arduino yaitu **millis()** untuk mengimplementasikan fitur debounce.

### Modul-modul yang dibutuhkan pada proyek ini:
* ESP8266 IoT v2.0 (1),
* ESP8266 Expansion Shield (1),
* LED Module (1),
* Digital Push Button (1).

<img src="/images/02_click_counter.png" height="400">

### Hubungkan modul-modul di atas mengikuti langkah-langkah di bawah ini:
1. Pasang ESP8266 Expansion Shield di atas ESP8266 IoT v2.0,
2. Hubungkan LED Module ke header ESP8266 Expansion Shield yang berlabel **4**,
3. Hubungkan Digital Push Button ke header ESP8266 Expansion Shield yang berlabel **3**,
4. Upload kode program [Click_Counter](/02_Click_Counter/Click_Counter) ke ESP8266 IoT v2.0.

Apabila tidak terdapat kesalahan, maka LED Module akan berkedip sesuai dengan jumlah penekanan yang diberikan pada Digital Push Button.

