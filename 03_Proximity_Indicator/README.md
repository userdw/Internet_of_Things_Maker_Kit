# [ENGLISH] Project 3: Proximity Indicator
***Please note that some parts in this project are not available in Internet of Things Maker Kit. You can found them in [Arduino Maker Kit](https://github.com/userdw/Arduino_Maker_Kit).***

Measuring distance can be done through a lot of methods. One of the most common method to be used is using the reflection of light. In this project you will learn how to use phototransistor to detect an object and get the rough estimation of object's distance. The system in this project will detect the presence of an object. If the object is getting closer, LED will blink faster. On the contrary, if the object is getting further, LED will blink slower.

<img src="/images/03_proximity_indicator.png" height="400">

### In this project you will need:
* ESP8266 IoT v2.0 (1),
* ESP8266 Expansion Shield (1),
* LED Module (1),
* IR Sensor (1).

### Assemble the modules following these steps:
1. Plug the ESP8266 Expansion Shield to the top of ESP8266 IoT v2.0,
2. Plug the LED Module to the header on the ESP8266 Expansion Shield labelled **7**,
3. Plug the IR Sensor to the header on the ESP8266 Expansion Shield labelled **ADC**,
4. Upload the [Proximity_Indicator](/03_Proximity_Indicator/Proximity_Indicator) code into ESP8266 IoT v2.0.

Once you turn on the ESP8266 IoT v2.0, it will enter calibration mode for about 3 seconds. Cover the IR Sensor with the desired object which will be tracked to determine the highest brightness, and uncover the IR Sensor to determine the lowest brightness.
If there are no mistakes, LED Module should blink faster as the object gets near. On the contrary, LED Module should blink slower as the objects gets further.

# [BAHASA INDONESIA] Proyek 3: Proximity Indicator
***Beberapa peralatan yang digunakan pada proyek ini tidak tersedia pada Internet of Things Maker Kit. Peralatan-peralatan tersebut dapat ditemukan pada [Arduino Maker Kit](https://github.com/userdw/Arduino_Maker_Kit).***

Pengukuran jarak dapat dilakukan dengan banyak cara, dimana salah satu metode yang digunakan adalah memanfaatkan sifat pantulan cahaya. Proyek ini bertujuan untuk mendemonstrasikan penggunaan sensor cahaya, yaitu phototransistor dengan ESP8266. Sistem pada proyek ini akan mendeteksi keberadaan dari suatu obyek. Apabila obyek semakin mendekat maka LED akan berkedip semakin cepat. Sebaliknya, apabila obyek semakin menjauh, maka kedipan LED akan semakin lambat.

<img src="/images/03_proximity_indicator.png" height="400">

### Modul-modul yang dibutuhkan pada proyek ini:
* ESP8266 IoT v2.0 (1),
* ESP8266 Expansion Shield (1),
* LED Module (1),
* IR Sensor (1).

### Hubungkan modul-modul di atas mengikuti langkah-langkah di bawah ini:
1. Pasang ESP8266 Expansion Shield di atas ESP8266 IoT v2.0,
2. Hubungkan LED Module ke header ESP8266 Expansion Shield yang berlabel **7**,
3. Hubungkan IR Sensor ke header ESP8266 Expansion Shield yang berlabel **ADC**,
4. Upload kode program [Proximity_Indicator](/03_Proximity_Indicator/Proximity_Indicator) ke ESP8266.

Pada saat ESP8266 IoT v2.0 dinyalakan, ESP8266 IoT v2.0 akan memasuki proses kalibrasi selama kurang lebih 3 detik. Tutupi IR Sensor dengan obyek yang hendak dideteksi untuk mendapatkan nilai kecerahan tertinggi, dan hilangkan halangan dari IR Sensor untuk mendapatkan nilai kecerahan terendah.
Apabila tidak terdapat kesalahan, maka LED Module akan berkedip semakin cepat saat obyek yang dideteksi semakin mendekat. Sebaliknya, LED Module akan berkedip semakin lambat saat obyek yang dideteksi semakin menjauh.
