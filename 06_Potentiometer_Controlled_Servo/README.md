# [ENGLISH] Project 6: Potentiometer Controlled Servo
***Please note that some parts in this project are not available in Internet of Things Maker Kit. You can found them in [Arduino Maker Kit](https://github.com/userdw/Arduino_Maker_Kit).***

If we need to control an output which have more states than on/off, we will have some difficulties if we use switch as an input to control it. That's because the switch itself only has two states. For example, something that have more states than on/off is the speed of a motor, the brightness of a LED, the speed of running text, etc. In this project, you will be introduced to potentiometer and its usage as an input to control servo movement.

<img src="/images/06_potentiometer_controlled_servo.png" height="400">

### In this project you will need:
* ESP8266 IoT v2.0 (1),
* ESP8266 Expansion Shield (1),
* Rotation Sensor (1),
* Micro Servo (1).

### Assemble the modules following these steps:
1. Plug the ESP8266 Expansion Shield to the top of ESP8266 IoT v2.0,
2. Plug the Rotation Sensor to the header on the ESP8266 Expansion Shield labelled **ADC**,
3. Plug the Micro Servo to the header on the ESP8266 Expansion Shield labelled **PWM**,
4. Upload the [Potentiometer_Controlled_Servo](/06_Potentiometer_Controlled_Servo/Potentiometer_Controlled_Servo) code into ESP8266 IoT v2.0.

If there are no mistakes, Micro Servo movement will be determined by the rotation of Rotation Sensor.

# [BAHASA INDONESIA] Proyek 6: Potentiometer Controlled Servo
***Beberapa peralatan yang digunakan pada proyek ini tidak tersedia pada Internet of Things Maker Kit. Peralatan-peralatan tersebut dapat ditemukan pada [Arduino Maker Kit](https://github.com/userdw/Arduino_Maker_Kit).***

Apabila kita hendak mengendalikan suatu output yang memiliki beberapa keadaan selain on/off, maka kita akan mengalami kesulitan apabila menggunakan switch sebagai input, karena switch sendiri hanya memiliki dua kondisi saja. Beberapa contoh sederhana adalah pengaturan kecepatan suatu motor, pengaturan intensitas cahaya suatu lampu, pengaturan kecepatan gerak dari sebuah running text, dll.
Pada proyek ini akan dikenalkan penggunaan potensiometer sebagai perangkat input, dimana dengan potensiometer tersebut kita akan mengendalikan sudut dari sebuah motor servo.

<img src="/images/06_potentiometer_controlled_servo.png" height="400">

### Modul-modul yang dibutuhkan pada proyek ini:
* ESP8266 IoT v2.0 (1),
* ESP8266 Expansion Shield (1),
* Rotation Sensor (1),
* Micro Servo (1).

### Hubungkan modul-modul di atas mengikuti langkah-langkah di bawah ini:
1. Pasang ESP8266 Expansion Shield di atas ESP8266 IoT v2.0,
2. Hubungkan Rotation Sensor ke header ESP8266 Expansion Shield yang berlabel **ADC**,
3. Hubungkan Micro Servo ke header ESP8266 Expansion Shield yang berlabel **PWM**,
4. Upload kode program [Potentiometer_Controlled_Servo](/06_Potentiometer_Controlled_Servo/Potentiometer_Controlled_Servo) ke ESP8266 IoT v2.0.

Apabila tidak terdapat kesalahan, gerakan Micro Servo akan ditentukan dari putaran yang diberikan ke Rotation Sensor.
