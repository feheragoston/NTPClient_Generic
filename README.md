## NTPClient_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/NTPClient_Generic.svg?)](https://www.ardu-badge.com/NTPClient_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/NTPClient_Generic.svg)](https://github.com/khoih-prog/NTPClient_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/NTPClient_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/NTPClient_Generic.svg)](http://github.com/khoih-prog/NTPClient_Generic/issues)

---
---

## Table of Contents

* [Why do we need this NTPClient_Generic library](#why-do-we-need-this-ntpclient_generic-library)
  * [Features](#features)
  * [Currently supported Boards](#currently-supported-boards)
  * [Currently supported WiFi shields/modules](#currently-supported-wifi-shieldsmodules)
  * [Currently supported Ethernet shields/modules](#currently-supported-ethernet-shieldsmodules)
* [Changelog](#changelog)
  * [Releases v3.5.0](#releases-v350)
  * [Releases v3.4.1](#releases-v341)
  * [Releases v3.4.0](#releases-v340)
  * [Releases v3.3.0](#releases-v330)
  * [Releases v3.2.2](#releases-v322)
  * [Releases v3.2.1](#releases-v321)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For RTL8720DN boards using AmebaD core](#9-for-rtl8720dn-boards-using-amebad-core)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
  * [8. For fixing ESP8266 compile error](#8-for-fixing-esp8266-compile-error)
* [HOWTO Fix `Multiple Definitions` Linker Error](#howto-fix-multiple-definitions-linker-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Important Notes](#important-notes)
* [Examples](#examples)
  * [ESP32/ESP8266 Boards](#esp32esp8266-boards)
  * [Generic Boards with Ethernet](#generic-boards-with-ethernet)
  * [STM32F/L/H/G/WB/MP1 Boards with Ethernet](#stm32flhgwbmp1-boards-with-ethernet)
  * [Generic Boards with WiFiNINA](#generic-boards-with-wifinina)
  * [WT32_ETH01 Boards](#wt32_eth01-boards)
  * [RTL8720DN Boards](#rtl8720dn-boards)
* [Example RTC_Ethernet_NTPClient](#example-rtc_ethernet_ntpclient)
  * [ 1. File RTC_Ethernet_NTPClient.ino](#1-file-rtc_ethernet_ntpclientino)
  * [ 2. File defines.h](#2-file-definesh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [ 1. Ethernet_NTPClient_Advanced on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library](#1-ethernet_ntpclient_advanced-on-adafruit-nrf52840_feather_express-with-enc28J60-using-ethernetenc-library)
  * [ 2. NINA_NTPClient_Advanced on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library](#2-nina_ntpclient_advanced-on-arduino-samd21-samd_nano_33_iot-with-wifinina-using-wifinina_generic-library)
  * [ 3. TZ_NTP_WorldClock_Ethernet on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet2 Library](#3-tz_ntp_worldclock_ethernet-on-adafruit-nrf52840_feather_express-with-w5500-using-ethernet2-library)
  * [ 4. TZ_NTP_WorldClock_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library](#4-tz_ntp_worldclock_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a-using-stm32ethernet-library)
  * [ 5. RTC_Ethernet_NTPClient on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library](#5-rtc_ethernet_ntpclient-on-adafruit-nrf52840_feather_express-with-enc28J60-using-ethernetenc-library)
  * [ 6. RTC_Ethernet_NTPClient_STM32 on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library](#6-rtc_ethernet_ntpclient_stm32-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a-using-stm32ethernet-library)
  * [ 7. ESP_NTPClient_Advanced on ESP8266_NODEMCU_ESP12E](#7-esp_ntpclient_advanced-on-esp8266_nodemcu_esp12e)
  * [ 8. ESP_NTPClient_Advanced on ESP32_DEV](#8-esp_ntpclient_advanced-on-esp32_dev)
  * [ 9. Ethernet_NTPClient_Advanced on SAM DUE with W5100 using EthernetLarge Library](#9-ethernet_ntpclient_advanced-on-sam-due-with-w5100-using-ethernetlarge-library)
  * [10. BI_RTC_Ethernet_NTPClient_STM32 on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library](#10-bi_rtc_ethernet_ntpclient_stm32-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a-using-stm32ethernet-library)
  * [11. BI_RTC_Ethernet_NTPClient_STM32 on STM32F7 Nucleo-144 NUCLEO_F767ZI with ENC28J60 using EthernetENC Library](#11-bi_rtc_ethernet_ntpclient_stm32-on-stm32f7-nucleo-144-nucleo_f767zi-with-enc28J60-using-ethernetenc-library)
  * [12. BI_RTC_Alarm_Ethernet_NTPClient_STM32 on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library](#12-bi_rtc_alarm_ethernet_ntpclient_stm32-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a-using-stm32ethernet-library)
  * [13. NINA_NTPClient_Basic on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library](#13-nina_ntpclient_basic-on-mbed-nano_rp2040_connect-with-wifinina-using-wifinina_generic-library)
  * [14. Ethernet_NTPClient_Advanced on RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library](#14-ethernet_ntpclient_advanced-on-raspberry_pi_pico-with-w5x00-using-ethernet2-library)
  * [15. Ethernet_NTPClient_Advanced on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library](#15-ethernet_ntpclient_advanced-on-mbed-raspberry_pi_pico-with-w5x00-using-ethernet2-library)
  * [16. NINA_TZ_NTP_WorldClock on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library](#16-nina_tz_ntp_worldclock-on-mbed-nano_rp2040_connect-with-wifinina-using-wifinina_generic-library)
  * [17. WT32_ETH01_TZ_NTP_WorldClock on ESP32_DEV with ETH_PHY_LAN8720](#17-wt32_eth01_tz_ntp_worldclock-on-esp32_dev-with-eth_phy_lan8720)
  * [18. WT32_ETH01_NTPClient_Advanced on ESP32_DEV with ETH_PHY_LAN8720](#18-wt32_eth01_ntpclient_advanced-on-esp32_dev-with-eth_phy_lan8720)
  * [19. RTL8720DN_TZ_NTP_WorldClock on Rtlduino RTL8720DN](#19-rtl8720dn_tz_ntp_worldclock-on-rtlduino-rtl8720dn)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Releases](#releases)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [NTPClient_Generic library](https://github.com/khoih-prog/NTPClient_Generic)

#### Features

The [**NTPClient_Generic library**](https://github.com/khoih-prog/NTPClient_Generic) is designed to work in conjunction with the [**Arduino Time library**](https://github.com/PaulStoffregen/Time), which must also be installed on your system. This documentation assumes some familiarity with the Time library.

The primary goal of the [**NTPClient_Generic library**](https://github.com/khoih-prog/NTPClient_Generic) is to enable the creation of an NTPClient to connect to NTP time-servers to get time and keep local time in sync. For **ESP8266/ESP32, WT32_ETH01 (ESP32 + LAN8720), nRF52, SAMD21/SAMD51, STM32F/L/H/G/WB/MP1, Teensy, RP2040-based boards (Nano_RP2040_Connect, RASPBERRY_PI_PICO), etc. besides AVR, using ESP WiFi, WiFiNINA, Ethernet W5x00, ENC28J60, LAN8742A, ESP8266/ESP32 AT-command WiFi**. But whether hardware RTC or another time-keeping source is present is not mandatory, since the [**Time library**](https://github.com/PaulStoffregen/Time) library can function as a software RTC without additional hardware (although its accuracy is dependent on the accuracy of the microcontroller's system clock.)

The examples will demonstrate how to get the UTC time from NTP server, then update the DS3231 RTC or local clock to make sure the time is perfectly correct.

In the examples, the interval to get perfect time from the NTP server to update RTC and/or local clock is configurable to ensure the RTC and/or local clock accuracy.

This [**NTPClient_Generic library**](https://github.com/khoih-prog/NTPClient_Generic) is based on and modified from [**Fabrice Weinberg's NTPClient Library**](https://github.com/arduino-libraries/NTPClient) to add functions, features and as well as support to many boards and shields.

---

#### Currently supported Boards

This [**NTPClient_Generic** library](https://github.com/khoih-prog/NTPClient_Generic) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 
 2. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino:  LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 3. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 4. **SAM DUE** 
 5. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0)**
 6. **STM32F/L/H/G/WB/MP1 boards (with 32+K Flash)**
  - Nucleo-144
  - Nucleo-64
  - Discovery
  - Generic STM32F0, STM32F1, STM32F2, STM32F3, STM32F4, STM32F7 (with 64+K Flash): x8 and up
  - STM32L0, STM32L1, STM32L4
  - STM32G0, STM32G4
  - STM32H7
  - STM32WB
  - STM32MP1
  - LoRa boards
  - 3-D printer boards
  - Generic Flight Controllers
  - Midatronics boards

 7. **ESP32**
 8. **ESP8266**
 9. **AVR Mega1280, 2560, ADK.**
  
10. RP2040-based boards, such as **Nano_RP2040_Connect**, using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).

11. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).

12. **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet

13. **RTL8720DN, RTL8722DM, RTL8722CSM, etc. boards**

---

#### Currently supported WiFi shields/modules

1. WiFiNINA using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
2. WiFi101 using [`WiFi101 library v0.16.1+`](https://github.com/arduino-libraries/WiFi101)
3. U-Blox W101, W102 using [`WiFiNINA_Generic library`](https://github.com/khoih-prog/WiFiNINA_Generic)
4. ESP826-AT command using [`WiFiEspAT library v1.3.0+`](https://github.com/jandrassy/WiFiEspAT)
5. ESP8266/ESP32-AT command using [`ESP_AT_Lib library`](https://github.com/khoih-prog/ESP_AT_Lib) and [`ESP8266_AT_WebServer`](ESP8266_AT_WebServer)
6. ESP32 and ESP8266 WiFi
7. **RTL8720DN, RTL8722DM, RTL8722CSM**

#### Currently supported Ethernet shields/modules

1. W5x00 using [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge), [`Ethernet2`](https://github.com/adafruit/Ethernet2) or [`Ethernet3`](https://github.com/sstaub/Ethernet3) library
2. ENC28J60 using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
3. Teensy 4.1 built-in NativeEthernet using [NativeEthernet Library](https://github.com/vjmuzik/NativeEthernet)
4. LAN8742A using [`STM32Ethernet`](https://github.com/stm32duino/STM32Ethernet) / [STM32 LwIP](https://github.com/stm32duino/LwIP) libraries.
5. LAN8720A in WT32-ETH01 using [`WebServer_WT32_ETH01`](https://github.com/khoih-prog/WebServer_WT32_ETH01).

---
---

## Changelog

### Releases v3.5.0

1. Add support to RTL8720DN, RTL8722DM, RTL8722CSM, etc. boards
2. Add examples with new features

### Releases v3.4.1

1. Fix typo in `library.json`

### Releases v3.4.0

1. Add support to WT32_ETH01 (ESP32 + LAN8720) boards
2. Add examples with new features

### Releases v3.3.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).
3. Add packet validity checks
4. Add version string
5. Improve and add more debugging codes

### Releases v3.2.2

1. Add examples to use **STM32 Built-In RTC.**

### Releases v3.2.1

1. Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
2. Add support to **SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1 with WiFiNINA, W5x00, ENC28J60, LAN8742A Ethernet modules/shields.**
3. Add functions.
4. Completely new examples using NTP time to update DS3231 RTC and/or local clock.

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.15+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`ESP32 Core 1.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 3. [`ESP8266 Core 3.0.1+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS. 
 4. [`Arduino AVR core 1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 5. [`Teensy core v1.54+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards.
 6. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 7. [`Arduino SAMD core 1.8.11+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 8. [`Adafruit SAMD core 1.7.2+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 9. [`Seeeduino SAMD core 1.8.1+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 
10. [`Adafruit nRF52 v0.24.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)

  **Warnings** : Use [`Adafruit nRF52 v0.22.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/tag/0.22.0) will create **compiler errors** to some boards. If so, please use the [`Adafruit nRF52 v0.21.0`](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/tag/0.21.0) until the issue fixed.
  
11. [`Arduino Core for STM32 v2.0.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
12. [`Arduino mbed_rp2040 core 2.3.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
13. [`Earle Philhower's arduino-pico core v1.9.3+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
14. [`Arduino AmebaD core 3.0.8+`](https://github.com/ambiot/ambd_arduino) for Realtek RTL8720DN, RTL8722DM and RTL8722CSM. [![GitHub release](https://img.shields.io/github/release/ambiot/ambd_arduino.svg)](https://github.com/ambiot/ambd_arduino/releases/latest)

15. [`Time v1.6.1+`](https://github.com/PaulStoffregen/Time). [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/Time.svg)](https://github.com/PaulStoffregen/Time/releases/latest)
16. For built-in LAN8742A Ethernet:
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest)
   - [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest)
17. For W5x00 Ethernet:
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
18. For ENC28J60 Ethernet:
   - [`EthernetENC library v2.0.1+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.10+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
19. [`WiFiNINA_Generic library v1.8.13+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc.
20. [`WiFiWebServer library v1.2.0+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
21. [`EthernetWebServer library v1.5.0+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
22. [`EthernetWebServer_STM32 library v1.2.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32).
23. [`ESP8266_AT_WebServer library v1.3.0+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer)
24. [`DS323x_Generic library v1.2.1+`](https://github.com/khoih-prog/DS323x_Generic) to use examples using DS323x RTC modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/DS323x_Generic.svg?)](https://www.ardu-badge.com/DS323x_Generic)
25. [`Timezone_Generic library v1.7.0+`](https://github.com/khoih-prog/Timezone_Generic) to use examples using Timezone. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic)
26. [`STM32RTC library v1.1.0+`](https://github.com/stm32duino/STM32RTC) to use STM32 examples using built-in STM32 RTC. [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32RTC.svg)](https://github.com/stm32duino/STM32RTC/releases/latest).
27. [`WebServer_WT32_ETH01 library v1.2.0+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) to use WT32_ETH01 (ESP32 + LAN8720). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_WT32_ETH01.svg?)](https://www.ardu-badge.com/WebServer_WT32_ETH01).
28. [`WiFiWebServer_RTL8720 library v1.0.1+`](https://github.com/khoih-prog/WiFiWebServer_RTL8720) to use Realtek RTL8720DN, etc. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer_RTL8720.svg?)](https://www.ardu-badge.com/WiFiWebServer_RTL8720).

---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**NTPClient_Generic**](https://github.com/khoih-prog/NTPClient_Generic), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/NTPClient_Generic.svg?)](https://www.ardu-badge.com/NTPClient_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**NTPClient_Generic**](https://github.com/khoih-prog/NTPClient_Generic) page.
2. Download the latest release `NTPClient_Generic-master.zip`.
3. Extract the zip file to `NTPClient_Generic-master` directory 
4. Copy whole `NTPClient_Generic-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**NTPClient_Generic** library](https://platformio.org/lib/show/11354/NTPClient_Generic) by using [Library Manager](https://platformio.org/lib/show/11354/NTPClient_Generic/installation). Search for **NTPClient_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**Don't use v0.22.0+ yet because of compiler error. To be fixed.**

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 0.21.0](Packages_Patches/adafruit/hardware/nrf52/0.21.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0). 

Supposing the Adafruit nRF52 version is 0.21.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.13/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.13. These files must be copied into the directory:

- `./arduino-1.8.13/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.13/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD cores 1.8.11](Packages_Patches/arduino/hardware/samd/1.8.11) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.11).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.11. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.11/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.7.1) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.1). 

Supposing the Adafruit SAMD core version is 1.7.1. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.1/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.8.1) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.1). 

Supposing the Seeeduino SAMD core version is 1.8.1. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.1/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/1.9.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).

#### 9. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.0.8/cores/arduino/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.0.8/cores/arduino/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.0.8. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.0.8/cores/arduino/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/arduino/avr/pgmspace.h`

---
---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.13/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For fixing ESP8266 compile error

To fix `ESP8266 compile error` such as

```
error: 'class EthernetClass' has no member named 'init'
Ethernet.init (USE_THIS_SS_PIN);
```

just rename the following file in ./arduino-1.8.13/hardware/esp8266com/esp8266/libraries/Ethernet directory

- From `Ethernet.h` to `Ethernet_ESP8266.h`

---
---

### HOWTO Fix `Multiple Definitions` Linker Error

The current library implementation, using **xyz-Impl.h instead of standard xyz.cpp**, possibly creates certain `Multiple Definitions` Linker error in certain use cases. Although it's simple to just modify several lines of code, either in the library or in the application, the library is adding 2 more source directories

1. **scr_h** for new h-only files
2. **src_cpp** for standard h/cpp files

besides the standard **src** directory.

To use the **old standard cpp** way, locate this library' directory, then just 

1. **Delete the all the files in src directory.**
2. **Copy all the files in src_cpp directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.

To re-use the **new h-only** way, just 

1. **Delete the all the files in src directory.**
2. **Copy the files in src_h directory into src.**
3. Close then reopen the application code in Arduino IDE, etc. to recompile from scratch.


---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

### Important Notes

1. Code is restructured to provide flexibility to make it easy to support many more **WiFi/Ethernet** modules/shields in the future. Please delete the *.cpp files, replaced by *.hpp files, in the src directory, if *.cpp files still exist after installing new version.

2. For **Adafruit nRF52**, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = MO(SI)
  - SPI_MISO  = MI(SO)
  - SPI_SCK   = SCK

3. For **Adafruit SAMD21/SAMD51**, use the SPI's CS/SS pin as follows:

  - Itsy-Bitsy M0/M4, Feather M0 (Express), Hallowing M0 Express, Zero, Metro M0 => use CS = 16 = pin A2
  - Feather M4 (SAMD51)   => use SS/CS = 9
  - Grand Central M4      => use SS/CS = 53
  - Hallowing M4          => use SS/CS = 10
  - Metro M4 AirLift      => use SS/CS = 36

To know the default CS/SS pins of not listed boards, check the related `variant.h` files in 

`~/.arduino15/packages/adafruit/hardware/samd/x.y.zz/variants/board_name/variant.h`

4. For **Arduino SAM DUE**, use the SPI's  pin as follows:

  - SS/CS     = 10
  - SPI_MOSI  = 75 ( pin 4 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_MISO  = 74 ( pin 1 @ [ICSP connector](pics/ICSP_connector.jpg) )
  - SPI_SCK   = 76 ( pin 3 @ [ICSP connector](pics/ICSP_connector.jpg) )
  
<p align="center">
    <img src="https://github.com/khoih-prog/NTPClient_Generic/blob/main/pics/ICSP_connector.jpg">
</p>
  
  
---
---

## Examples

### ESP32/ESP8266 Boards

 1. [ESP_NTPClient_Advanced](examples/ESP/ESP_NTPClient_Advanced)
 2. [ESP_NTPClient_Basic](examples/ESP/ESP_NTPClient_Basic)
 
### Generic Boards with Ethernet

 1. [Ethernet_NTPClient_Advanced](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced)
 2. [Ethernet_NTPClient_Basic](examples/Generic/Ethernet/Ethernet_NTPClient_Basic)
 3. [RTC_Ethernet_NTPClient](examples/Generic/Ethernet/RTC_Ethernet_NTPClient)
 4. [TZ_NTP_Clock_Ethernet](examples/Generic/Ethernet/TZ_NTP_Clock_Ethernet) 
 5. [TZ_NTP_WorldClock_Ethernet](examples/Generic/Ethernet/TZ_NTP_WorldClock_Ethernet)

### STM32F/L/H/G/WB/MP1 Boards with Ethernet

 1. [BI_RTC_Alarm_Ethernet_NTPClient_STM32](examples/Generic/Ethernet/BI_RTC_Alarm_Ethernet_NTPClient_STM32) 
 2. [BI_RTC_Ethernet_NTPClient_STM32](examples/Generic/Ethernet/BI_RTC_Ethernet_NTPClient_STM32) 
 3. [Ethernet_NTPClient_Advanced_STM32](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced_STM32) 
 4. [Ethernet_NTPClient_Basic_STM32](examples/Generic/Ethernet/Ethernet_NTPClient_Basic_STM32)
 5. [RTC_Ethernet_NTPClient_STM32](examples/Generic/Ethernet/RTC_Ethernet_NTPClient_STM32)
 6. [TZ_NTP_Clock_STM32_Ethernet](examples/Generic/Ethernet/TZ_NTP_Clock_STM32_Ethernet) 
 7. [TZ_NTP_WorldClock_STM32_Ethernet](examples/Generic/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet)
 
### Generic Boards with WiFiNINA 
 
 1. [NINA_NTPClient_Advanced](examples/Generic/WiFiNINA/NINA_NTPClient_Advanced) 
 2. [NINA_NTPClient_Basic](examples/Generic/WiFiNINA/NINA_NTPClient_Basic)
 3. [NINA_TZ_NTP_Clock](examples/Generic/WiFiNINA/NINA_TZ_NTP_Clock)
 4. [NINA_TZ_NTP_WorldClock](examples/Generic/WiFiNINA/NINA_TZ_NTP_WorldClock)

### RTL8720DN Boards
 
 1. [RTL8720DN_NTPClient_Advanced](examples/RTL8720DN/RTL8720DN_NTPClient_Advanced) 
 2. [RTL8720DN_NTPClient_Basic](examples/RTL8720DN/RTL8720DN_NTPClient_Basic)
 3. [RTL8720DN_TZ_NTP_Clock](examples/RTL8720DN/RTL8720DN_TZ_NTP_Clock)
 4. [RTL8720DN_TZ_NTP_WorldClock](examples/RTL8720DN/RTL8720DN_TZ_NTP_WorldClock)
 
 

---
---

### Example [RTC_Ethernet_NTPClient](examples/Generic/Ethernet/RTC_Ethernet_NTPClient)

#### 1. File [RTC_Ethernet_NTPClient.ino](examples/Generic/Ethernet/RTC_Ethernet_NTPClient/RTC_Ethernet_NTPClient.ino)

```cpp

#include "defines.h"

#include <Timezone_Generic.h>             // https://github.com/khoih-prog/Timezone_Generic

#include <DS323x_Generic.h>               // https://github.com/khoih-prog/DS323x_Generic

DS323x rtc;

//////////////////////////////////////////

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    //Daylight time = UTC - 4 hours
TimeChangeRule mySTD = {"EST", First, Sun, Nov, 2, -300};     //Standard time = UTC - 5 hours
Timezone myTZ(myDST, mySTD);

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

//////////////////////////////////////////

#include <NTPClient_Generic.h>

// A UDP instance to let us send and receive packets over UDP
EthernetUDP ntpUDP;

// NTP server
//World
//char timeServer[] = "time.nist.gov";
// Canada
char timeServer[] = "0.ca.pool.ntp.org";
//char timeServer[] = "1.ca.pool.ntp.org";
//char timeServer[] = "2.ca.pool.ntp.org";
//char timeServer[] = "3.ca.pool.ntp.org";
// Europe
//char timeServer[] = ""europe.pool.ntp.org";

#define TIME_ZONE_OFFSET_HRS            (-4)
#define NTP_UPDATE_INTERVAL_MS          60000L

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, timeServer, (3600 * TIME_ZONE_OFFSET_HRS), NTP_UPDATE_INTERVAL_MS);

static bool gotCurrentTime = false;

// format and print a time_t value, with a time zone appended.
void printDateTime(time_t t, const char *tz)
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%.2d:%.2d:%.2d %s %.2d %s %d %s",
          hour(t), minute(t), second(t), dayShortStr(weekday(t)), day(t), m, year(t), tz);
  Serial.println(buf);
}

void update_RTC(void)
{
  // Just get the correct time once
  if (timeClient.updated())
  {
    Serial.println("********UPDATED********");
    rtc.now( DateTime(timeClient.getUTCEpochTime()) );
    gotCurrentTime = true;
  }
}

void displayRTC()
{
  // Display time from RTC
  DateTime now = rtc.now();

  Serial.println("============================");

  time_t utc = now.get_time_t();
  time_t local = myTZ.toLocal(utc, &tcr);
  
  printDateTime(utc, "UTC");
  printDateTime(local, tcr -> abbrev);
}

void check_status(void)
{
  // Update first time after 5s
  static ulong checkstatus_timeout  = 5000L;
  static ulong RTCDisplay_timeout   = 0;

  static ulong current_millis;

// Display every 10s
#define RTC_DISPLAY_INTERVAL        (10000L)

// Update RTC every hour if got correct time from NTP
#define RTC_UPDATE_INTERVAL         (3600 * 1000L)

// Retry updating RTC every 5s if haven't got correct time from NTP
#define RTC_RETRY_INTERVAL          (3 * 1000L)

  current_millis = millis();

  if ((current_millis > RTCDisplay_timeout) || (RTCDisplay_timeout == 0))
  {
    if (gotCurrentTime)
      displayRTC();
      
    RTCDisplay_timeout = current_millis + RTC_DISPLAY_INTERVAL;
  }
  
  // Update RTC every RTC_UPDATE_INTERVAL (3600) seconds.
  if ((current_millis > checkstatus_timeout))
  {
    update_RTC();
    
    if (gotCurrentTime)
    {
      Serial.println("RTC updated. Next update in seconds : " + String(RTC_UPDATE_INTERVAL/1000, DEC));
      checkstatus_timeout = current_millis + RTC_UPDATE_INTERVAL;
    }
    else
    {
      Serial.println("Retry RTC update in seconds : " + String(RTC_RETRY_INTERVAL/1000, DEC));
      checkstatus_timeout = current_millis + RTC_RETRY_INTERVAL;
    }   
  }
}

//////////////////////////////////////////

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart RTC_Ethernet_NTPClient on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

  Wire.begin();

#if USE_ETHERNET_WRAPPER

  EthernetInit();

#else

#if USE_ETHERNET
  ET_LOGWARN(F("=========== USE_ETHERNET ==========="));
#elif USE_ETHERNET2
  ET_LOGWARN(F("=========== USE_ETHERNET2 ==========="));
#elif USE_ETHERNET3
  ET_LOGWARN(F("=========== USE_ETHERNET3 ==========="));
#elif USE_ETHERNET_LARGE
  ET_LOGWARN(F("=========== USE_ETHERNET_LARGE ==========="));
#elif USE_ETHERNET_ESP8266
  ET_LOGWARN(F("=========== USE_ETHERNET_ESP8266 ==========="));
#else
  ET_LOGWARN(F("========================="));
#endif

  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));

#if defined(ESP8266)
  // For ESP8266, change for other boards if necessary
#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   D2    // For ESP8266
#endif

  ET_LOGWARN1(F("ESP8266 setCsPin:"), USE_THIS_SS_PIN);

#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
  // For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  // Must use library patch for Ethernet, EthernetLarge libraries
  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
#ifndef ETHERNET3_MAX_SOCK_NUM
#define ETHERNET3_MAX_SOCK_NUM      4
#endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN);

#endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#elif defined(ESP32)

  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   22    // For ESP32
#endif

  ET_LOGWARN1(F("ESP32 setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, EthernetLarge libraries
  // ESP32 => GPIO2,4,5,13,15,21,22 OK with Ethernet, Ethernet2, EthernetLarge
  // ESP32 => GPIO2,4,5,15,21,22 OK with Ethernet3

  //Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
#ifndef ETHERNET3_MAX_SOCK_NUM
#define ETHERNET3_MAX_SOCK_NUM      4
#endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN);

#endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#else   //defined(ESP8266)
  // unknown board, do nothing, use default SS = 10
#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   10    // For other boards
#endif

  ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2  || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries

  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
#ifndef ETHERNET3_MAX_SOCK_NUM
#define ETHERNET3_MAX_SOCK_NUM      4
#endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN);

#endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#endif    //defined(ESP8266)


#endif  //USE_ETHERNET_WRAPPER


  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  // Just info to know how to connect correctly
  Serial.println(F("========================="));
  Serial.println(F("Currently Used SPI pinout:"));
  Serial.print(F("MOSI:"));
  Serial.println(MOSI);
  Serial.print(F("MISO:"));
  Serial.println(MISO);
  Serial.print(F("SCK:"));
  Serial.println(SCK);
  Serial.print(F("SS:"));
  Serial.println(SS);
#if USE_ETHERNET3
  Serial.print(F("SPI_CS:"));
  Serial.println(SPI_CS);
#endif
  Serial.println(F("========================="));

  Serial.print(F("Using mac index = "));
  Serial.println(index);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

  timeClient.begin();

  rtc.attach(Wire);
}

void loop()
{
  timeClient.update();
  
  check_status();
}
```

---

#### 2. File [defines.h](examples/Generic/Ethernet/RTC_Ethernet_NTPClient/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       3

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD      true
#endif

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
#if defined(ETHERNET_USE_NRF528XX)
#undef ETHERNET_USE_NRF528XX
#endif
#define ETHERNET_USE_NRF528XX      true
#endif

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(ETHERNET_USE_SAM_DUE)
#undef ETHERNET_USE_SAM_DUE
#endif
#define ETHERNET_USE_SAM_DUE      true
#endif

#if defined(ETHERNET_USE_SAMD)
// For SAMD
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if ( defined(ARDUINO_SAMD_ZERO) && !defined(SEEED_XIAO_M0) )
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
#elif defined(ADAFRUIT_METRO_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
#elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
#elif defined(ADAFRUIT_GEMMA_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
#elif defined(ADAFRUIT_TRINKET_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
#elif defined(ADAFRUIT_ITSYBITSY_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
#elif defined(ARDUINO_SAMD_HALLOWING_M0)
#define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
#elif defined(ADAFRUIT_METRO_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
#elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
#elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
#elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
#define USE_THIS_SS_PIN       10
#elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
#elif defined(ADAFRUIT_PYPORTAL)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
#elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
#elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
#elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
#elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
#elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
#elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
#elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
#elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
#elif defined(SEEED_WIO_TERMINAL)
#define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
#elif defined(SEEED_FEMTO_M0)
#define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
#elif defined(SEEED_XIAO_M0)
#define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
#ifdef USE_THIS_SS_PIN
#undef USE_THIS_SS_PIN
#endif
#define USE_THIS_SS_PIN       A1
#warning define SEEED_XIAO_M0 USE_THIS_SS_PIN == A1
#elif defined(Wio_Lite_MG126)
#define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
#elif defined(WIO_GPS_BOARD)
#define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
#elif defined(SEEEDUINO_ZERO)
#define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
#elif defined(SEEEDUINO_LORAWAN)
#define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
#elif defined(SEEED_GROVE_UI_WIRELESS)
#define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
#elif defined(__SAMD21E18A__)
#define BOARD_TYPE      "SAMD21E18A"
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19A"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAM3X8E__)
#define BOARD_TYPE      "SAM3X8E"
#elif defined(__CPU_ARC__)
#define BOARD_TYPE      "CPU_ARC"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif

#elif (ETHERNET_USE_SAM_DUE)
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10
#define BOARD_TYPE      "SAM DUE"

#elif (ETHERNET_USE_NRF528XX)
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if defined(NRF52840_FEATHER)
#define BOARD_TYPE      "NRF52840_FEATHER"
#elif defined(NRF52832_FEATHER)
#define BOARD_TYPE      "NRF52832_FEATHER"
#elif defined(NRF52840_FEATHER_SENSE)
#define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
#elif defined(NRF52840_ITSYBITSY)
#define BOARD_TYPE      "NRF52840_ITSYBITSY"
#define USE_THIS_SS_PIN   10    // For other boards
#elif defined(NRF52840_CIRCUITPLAY)
#define BOARD_TYPE      "NRF52840_CIRCUITPLAY"
#elif defined(NRF52840_CLUE)
#define BOARD_TYPE      "NRF52840_CLUE"
#elif defined(NRF52840_METRO)
#define BOARD_TYPE      "NRF52840_METRO"
#elif defined(NRF52840_PCA10056)
#define BOARD_TYPE      "NRF52840_PCA10056"
#elif defined(NINA_B302_ublox)
#define BOARD_TYPE      "NINA_B302_ublox"
#elif defined(NINA_B112_ublox)
#define BOARD_TYPE      "NINA_B112_ublox"
#elif defined(PARTICLE_XENON)
#define BOARD_TYPE      "PARTICLE_XENON"
#elif defined(ARDUINO_NRF52_ADAFRUIT)
#define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
#else
#define BOARD_TYPE      "nRF52 Unknown"
#endif

#elif ( defined(CORE_TEENSY) )
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if defined(__IMXRT1062__)
// For Teensy 4.1/4.0
#define BOARD_TYPE      "TEENSY 4.1/4.0"
#elif defined(__MK66FX1M0__)
#define BOARD_TYPE "Teensy 3.6"
#elif defined(__MK64FX512__)
#define BOARD_TYPE "Teensy 3.5"
#elif defined(__MKL26Z64__)
#define BOARD_TYPE "Teensy LC"
#elif defined(__MK20DX256__)
#define BOARD_TYPE "Teensy 3.2" // and Teensy 3.1 (obsolete)
#elif defined(__MK20DX128__)
#define BOARD_TYPE "Teensy 3.0"
#elif defined(__AVR_AT90USB1286__)
#error Teensy 2.0++ not supported yet
#elif defined(__AVR_ATmega32U4__)
#error Teensy 2.0 not supported yet
#else
// For Other Boards
#define BOARD_TYPE      "Unknown Teensy Board"
#endif

#elif ( defined(ESP8266) )
// For ESP8266
#warning Use ESP8266 architecture
#include <ESP8266mDNS.h>
#define ETHERNET_USE_ESP8266
#define BOARD_TYPE      "ESP8266"

#elif ( defined(ESP32) )
// For ESP32
#warning Use ESP32 architecture
#define ETHERNET_USE_ESP32
#define BOARD_TYPE      "ESP32"

#define W5500_RST_PORT   21

#else
// For Mega
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10
#define BOARD_TYPE            "AVR Mega"
#endif

#ifndef BOARD_NAME
#define BOARD_NAME    BOARD_TYPE
#endif

#include <SPI.h>

//#define USE_ETHERNET_WRAPPER    true
#define USE_ETHERNET_WRAPPER    false

// Use true  for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
// Use false for W5x00 and Ethernetx library      (https://www.arduino.cc/en/Reference/Ethernet)

//#define USE_UIP_ETHERNET   true
#define USE_UIP_ETHERNET   false

//#define USE_CUSTOM_ETHERNET     true

// Note: To rename ESP628266 Ethernet lib files to Ethernet_ESP8266.h and Ethernet_ESP8266.cpp
// In order to USE_ETHERNET_ESP8266
#if ( !defined(USE_UIP_ETHERNET) || !USE_UIP_ETHERNET )

// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
// Check @ defined(SEEED_XIAO_M0)
//#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15

// Only one of the following to be true
#define USE_ETHERNET          false
#define USE_ETHERNET2         true
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    false
#define USE_ETHERNET_ESP8266  false
#define USE_ETHERNET_ENC      false
#define USE_CUSTOM_ETHERNET   false

#if !USE_ETHERNET_WRAPPER

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )
#ifdef USE_CUSTOM_ETHERNET
#undef USE_CUSTOM_ETHERNET
#endif
#define USE_CUSTOM_ETHERNET   false //true
#endif

#if USE_ETHERNET3
#include "Ethernet3.h"
#warning Using Ethernet3 lib
#define SHIELD_TYPE           "W5x00 using Ethernet3 Library"
#elif USE_ETHERNET2
#include "Ethernet2.h"
#warning Using Ethernet2 lib
#define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
#elif USE_ETHERNET_LARGE
#include "EthernetLarge.h"
#warning Using EthernetLarge lib
#define SHIELD_TYPE           "W5x00 using EthernetLarge Library"
#elif USE_ETHERNET_ESP8266
#include "Ethernet_ESP8266.h"
#warning Using Ethernet_ESP8266 lib
#define SHIELD_TYPE           "W5x00 using Ethernet_ESP8266 Library"
#elif USE_ETHERNET_ENC
#include "EthernetENC.h"
#warning Using EthernetENC lib
#define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
#elif USE_CUSTOM_ETHERNET
//#include "Ethernet_XYZ.h"
#include "EthernetENC.h"
#warning Using Custom Ethernet library. You must include a library and initialize.
#define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
#else
#define USE_ETHERNET          true
#include "Ethernet.h"
#warning Using Ethernet lib
#define SHIELD_TYPE           "W5x00 using Ethernet Library"
#endif

// Ethernet_Shield_W5200, EtherCard, EtherSia not supported
// Select just 1 of the following #include if uncomment #define USE_CUSTOM_ETHERNET
// Otherwise, standard Ethernet library will be used for W5x00

#endif    //  USE_ETHERNET_WRAPPER
#elif USE_UIP_ETHERNET
#include "UIPEthernet.h"
#warning Using UIPEthernet library
#define SHIELD_TYPE           "ENC28J60 using UIPEthernet Library"
#endif      // #if !USE_UIP_ETHERNET

#include <EthernetWebServer.h>

#ifndef SHIELD_TYPE
#define SHIELD_TYPE     "Unknown Ethernet shield/library"
#endif

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
};

// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 222);

#endif    //defines_h
```

---
---

### Debug Terminal Output Samples

#### 1. [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

Following is the debug terminal output when running example [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

```
Starting Ethernet_NTPClient_Advanced on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 3
You're connected to the network, IP = 192.168.2.79
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:05
UTC : 00:00:05 Thu 01 Jan 1970
LOC : 02:28:21
LOC : 02:28:21 Sun 07 Feb 2106
UTC EPOCH : 5
LOC EPOCH : 4294952901
UTC : 0:0:5 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:05 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:21 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:21 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 18:55:26
UTC : 18:55:26 Mon 26 Oct 2020
LOC : 14:55:26
LOC : 14:55:26 Mon 26 Oct 2020
UTC EPOCH : 1603738526
LOC EPOCH : 1603724126
UTC : 18:55:26 Mon 26/10/2020 or 26 Oct 2020
UTC : 18:55:26 Mon 26/10/2020 or 26 Oct 2020
LOC : 14:55:26 Mon 26/10/2020 or 26 Oct 2020
LOC : 14:55:26 Mon 26/10/2020 or 26 Oct 2020
```

---

#### 2. [**NINA_NTPClient_Advanced**](examples/Generic/WiFiNINA/NINA_NTPClient_Advanced) on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

Following is the debug terminal output when running example [**NINA_NTPClient_Advanced**](examples/Generic/WiFiNINA/NINA_NTPClient_Advanced) on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Starting NINA_NTPClient_Advanced on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
NTPClient_Generic v3.5.0
Connecting to: HueNet1

NTPClient_Advanced started @ IP address: 192.168.2.98
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:05
UTC : 00:00:05 Thu 01 Jan 1970
LOC : 02:28:21
LOC : 02:28:21 Sun 07 Feb 2106
UTC EPOCH : 5
LOC EPOCH : 4294952901
UTC : 0:0:5 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:05 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:21 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:21 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 22:52:08
UTC : 22:52:08 Mon 26 Oct 2020
LOC : 18:52:08
LOC : 18:52:08 Mon 26 Oct 2020
UTC EPOCH : 1603752728
LOC EPOCH : 1603738328
UTC : 22:52:8 Mon 26/10/2020 or 26 Oct 2020
UTC : 22:52:08 Mon 26/10/2020 or 26 Oct 2020
LOC : 18:52:8 Mon 26/10/2020 or 26 Oct 2020
LOC : 18:52:08 Mon 26/10/2020 or 26 Oct 2020
```

---

#### 3. [**TZ_NTP_WorldClock_Ethernet**](examples/Generic/Ethernet/TZ_NTP_WorldClock_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet2 Library

Following is the debug terminal output when running example [**TZ_NTP_WorldClock_Ethernet**](examples/Generic/Ethernet/TZ_NTP_WorldClock_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet2 Library

```
Start TZ_NTP_WorldClock_Ethernet on NRF52840_FEATHER with W5x00 using Ethernet2 Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET2 ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 17
You're connected to the network, IP = 192.168.2.80
********UPDATED********
Time updated. Next update in seconds : 3600

13:21:59 Tue 27 Oct 2020 AEDT Sydney
05:21:59 Tue 27 Oct 2020 MSK  Moscow
03:21:59 Tue 27 Oct 2020 CET  Paris
02:21:59 Tue 27 Oct 2020 GMT  London
02:21:59 Tue 27 Oct 2020 UTC  Universal Coordinated Time
22:21:59 Mon 26 Oct 2020 EDT  New York
21:21:59 Mon 26 Oct 2020 CDT  Chicago
20:21:59 Mon 26 Oct 2020 MDT  Denver
19:21:59 Mon 26 Oct 2020 MST  Phoenix
19:21:59 Mon 26 Oct 2020 PDT  Los Angeles

13:22:09 Tue 27 Oct 2020 AEDT Sydney
05:22:09 Tue 27 Oct 2020 MSK  Moscow
03:22:09 Tue 27 Oct 2020 CET  Paris
02:22:09 Tue 27 Oct 2020 GMT  London
02:22:09 Tue 27 Oct 2020 UTC  Universal Coordinated Time
22:22:09 Mon 26 Oct 2020 EDT  New York
21:22:09 Mon 26 Oct 2020 CDT  Chicago
20:22:09 Mon 26 Oct 2020 MDT  Denver
19:22:09 Mon 26 Oct 2020 MST  Phoenix
19:22:09 Mon 26 Oct 2020 PDT  Los Angeles
```

---

#### 4. [**TZ_NTP_WorldClock_STM32_Ethernet**](examples/Generic/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

Following is the debug terminal output when running example [**TZ_NTP_WorldClock_STM32_Ethernet**](examples/Generic/Ethernet/TZ_NTP_WorldClock_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start TZ_NTP_WorldClock_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.96
Retry Time update in seconds : 3
********UPDATED********
Time updated. Next update in seconds : 3600

13:37:40 Tue 27 Oct 2020 AEDT Sydney
05:37:40 Tue 27 Oct 2020 MSK  Moscow
03:37:40 Tue 27 Oct 2020 CET  Paris
02:37:40 Tue 27 Oct 2020 GMT  London
02:37:40 Tue 27 Oct 2020 UTC  Universal Coordinated Time
22:37:40 Mon 26 Oct 2020 EDT  New York
21:37:40 Mon 26 Oct 2020 CDT  Chicago
20:37:40 Mon 26 Oct 2020 MDT  Denver
19:37:40 Mon 26 Oct 2020 MST  Phoenix
19:37:40 Mon 26 Oct 2020 PDT  Los Angeles

13:37:50 Tue 27 Oct 2020 AEDT Sydney
05:37:50 Tue 27 Oct 2020 MSK  Moscow
03:37:50 Tue 27 Oct 2020 CET  Paris
02:37:50 Tue 27 Oct 2020 GMT  London
02:37:50 Tue 27 Oct 2020 UTC  Universal Coordinated Time
22:37:50 Mon 26 Oct 2020 EDT  New York
21:37:50 Mon 26 Oct 2020 CDT  Chicago
20:37:50 Mon 26 Oct 2020 MDT  Denver
19:37:50 Mon 26 Oct 2020 MST  Phoenix
19:37:50 Mon 26 Oct 2020 PDT  Los Angeles
```


---

#### 5. [**RTC_Ethernet_NTPClient**](examples/Generic/Ethernet/RTC_Ethernet_NTPClient) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

Following is the debug terminal output when running example [**RTC_Ethernet_NTPClient**](examples/Generic/Ethernet/RTC_Ethernet_NTPClient) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

```
Start RTC_Ethernet_NTPClient on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 0
You're connected to the network, IP = 192.168.2.94
============================
01:15:38 Tue 27 Oct 2020 UTC
21:15:38 Mon 26 Oct 2020 EDT
********UPDATED********
RTC updated. Next update in seconds : 3600
============================
01:15:48 Tue 27 Oct 2020 UTC
21:15:48 Mon 26 Oct 2020 EDT
============================
01:15:58 Tue 27 Oct 2020 UTC
21:15:58 Mon 26 Oct 2020 EDT
============================
```

---

#### 6. [**RTC_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/RTC_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

Following is the debug terminal output when running example [**RTC_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/RTC_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start RTC_Ethernet_NTPClient_STM32 on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.105
Retry RTC update in seconds : 3
********UPDATED********
RTC updated. Next update in seconds : 3600
============================
01:39:18 Tue 27 Oct 2020 UTC
21:39:18 Mon 26 Oct 2020 EDT
============================
01:39:28 Tue 27 Oct 2020 UTC
21:39:28 Mon 26 Oct 2020 EDT
```

---

#### 7. [**ESP_NTPClient_Advanced**](examples/ESP/ESP_NTPClient_Advanced) on ESP8266_NODEMCU_ESP12E

Following is the debug terminal output when running example [**ESP_NTPClient_Advanced**](examples/ESP/ESP_NTPClient_Advanced) on ESP8266_NODEMCU_ESP12E.

```
Starting ESP_NTPClient_Advanced on ESP8266_NODEMCU_ESP12E
NTPClient_Generic v3.5.0
Connecting to: HueNet1
....
ESP_NTPClient_Advanced started @ IP address: 192.168.2.69
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:02
UTC : 00:00:02 Thu 01 Jan 1970
LOC : 02:28:18
LOC : 02:28:18 Sun 07 Feb 2106
UTC EPOCH : 2
LOC EPOCH : 4294952898
UTC : 0:0:2 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:02 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:18 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:18 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 00:04:50
UTC : 00:04:50 Tue 27 Oct 2020
LOC : 20:04:50
LOC : 20:04:50 Mon 26 Oct 2020
UTC EPOCH : 1603757090
LOC EPOCH : 1603742690
UTC : 0:4:50 Tue 27/10/2020 or 27 Oct 2020
UTC : 00:04:50 Tue 27/10/2020 or 27 Oct 2020
LOC : 20:4:50 Mon 26/10/2020 or 26 Oct 2020
LOC : 20:04:50 Mon 26/10/2020 or 26 Oct 2020
```

---

#### 8. [**ESP_NTPClient_Advanced**](examples/ESP/ESP_NTPClient_Advanced) on ESP32_DEV

Following is the debug terminal output when running example [**ESP_NTPClient_Advanced**](examples/ESP/ESP_NTPClient_Advanced) on ESP32_DEV.

```
Starting ESP_NTPClient_Advanced on ESP32_DEV
NTPClient_Generic v3.5.0
Connecting to: HueNet1
....
ESP_NTPClient_Advanced started @ IP address: 192.168.2.101
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:02
UTC : 00:00:02 Thu 01 Jan 1970
LOC : 02:28:18
LOC : 02:28:18 Sun 07 Feb 2106
UTC EPOCH : 2
LOC EPOCH : 4294952898
UTC : 0:0:2 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:02 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:18 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:18 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 00:11:37
UTC : 00:11:37 Tue 27 Oct 2020
LOC : 20:11:37
LOC : 20:11:37 Mon 26 Oct 2020
UTC EPOCH : 1603757497
LOC EPOCH : 1603743097
UTC : 0:11:37 Tue 27/10/2020 or 27 Oct 2020
UTC : 00:11:37 Tue 27/10/2020 or 27 Oct 2020
LOC : 20:11:37 Mon 26/10/2020 or 26 Oct 2020
LOC : 20:11:37 Mon 26/10/2020 or 26 Oct 2020
```

---

#### 9. [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on SAM DUE with W5100 using EthernetLarge Library

Following is the debug terminal output when running example [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on SAM DUE with W5100 using EthernetLarge Library

```
Starting Ethernet_NTPClient_Advanced on SAM DUE with W5x00 using EthernetLarge Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_LARGE ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 75
[ETHERNET_WEBSERVER] MISO: 74
[ETHERNET_WEBSERVER] SCK: 76
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : SAM DUE , setCsPin: 10
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096
=========================
Currently Used SPI pinout:
MOSI:75
MISO:74
SCK:76
SS:10
=========================
Using mac index = 6
You're connected to the network, IP = 192.168.2.71
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:04
UTC : 00:00:04 Thu 01 Jan 1970
LOC : 02:28:20
LOC : 02:28:20 Sun 07 Feb 2106
UTC EPOCH : 4
LOC EPOCH : 4294952900
UTC : 0:0:4 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:04 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:20 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:20 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 20:29:47
UTC : 20:29:47 Mon 26 Oct 2020
LOC : 16:29:47
LOC : 16:29:47 Mon 26 Oct 2020
UTC EPOCH : 1603744187
LOC EPOCH : 1603729787
UTC : 20:29:47 Mon 26/10/2020 or 26 Oct 2020
UTC : 20:29:47 Mon 26/10/2020 or 26 Oct 2020
LOC : 16:29:47 Mon 26/10/2020 or 26 Oct 2020
LOC : 16:29:47 Mon 26/10/2020 or 26 Oct 2020
```

---

#### 10. [**BI_RTC_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/BI_RTC_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

Following is the debug terminal output when running example [**BI_RTC_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/BI_RTC_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library to demonstrate the usage of STM32 built-in RTC

```
Start BI_RTC_Ethernet_NTPClient_STM32 on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.96
Retry RTC update in seconds : 3

Updating Time for STM32 RTC
********UPDATED********
RTC updated. Next update in seconds : 3600
============================
20:35:36 Wed 28 Oct 2020 UTC
16:35:36 Wed 28 Oct 2020 EDT
============================
20:35:45 Wed 28 Oct 2020 UTC
16:35:45 Wed 28 Oct 2020 EDT
```

---

#### 11. [**BI_RTC_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/BI_RTC_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with ENC28J60 using EthernetENC Library

Following is the debug terminal output when running example [**BI_RTC_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/BI_RTC_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with ENC28J60 using EthernetENC Library to demonstrate the usage of STM32 built-in RTC

```
Start BI_RTC_Ethernet_NTPClient_STM32 on NUCLEO_F767ZI, using ENC28J60 & EthernetENC Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
BYou're connected to the network, IP = 192.168.2.97

Updating Time for STM32 RTC
********UPDATED********
RTC updated. Next update in seconds : 3600
============================
20:40:14 Wed 28 Oct 2020 UTC
16:40:14 Wed 28 Oct 2020 EDT
============================
20:40:24 Wed 28 Oct 2020 UTC
16:40:24 Wed 28 Oct 2020 EDT
```

---

#### 12. [**BI_RTC_Alarm_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/BI_RTC_Alarm_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

Following is the debug terminal output when running example [**BI_RTC_Alarm_Ethernet_NTPClient_STM32**](examples/Generic/Ethernet/BI_RTC_Alarm_Ethernet_NTPClient_STM32) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library to demonstrate the usage of STM32 built-in RTC Alarm function

```
Start BI_RTC_Alarm_Ethernet_NTPClient_STM32 on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
NTPClient_Generic v3.5.0
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.111
Retry RTC update in seconds : 3

Updating Time for STM32 RTC
********UPDATED********
=======RTC ALARM SET========
20:47:55 Wed 28 Oct 2020 UTC
16:47:55 Wed 28 Oct 2020 EDT
============================
RTC updated. Next update in seconds : 3600
============================
20:47:31 Wed 28 Oct 2020 UTC
16:47:31 Wed 28 Oct 2020 EDT
============================
20:47:40 Wed 28 Oct 2020 UTC
16:47:40 Wed 28 Oct 2020 EDT
============================
20:47:50 Wed 28 Oct 2020 UTC
16:47:50 Wed 28 Oct 2020 EDT
*****RTC ALARM ACTIVATED*****
*****RTC ALARM ACTIVATED*****
============================
20:47:59 Wed 28 Oct 2020 UTC
16:47:59 Wed 28 Oct 2020 EDT
============================
20:48:08 Wed 28 Oct 2020 UTC
16:48:08 Wed 28 Oct 2020 EDT
```

---

#### 13. [**NINA_NTPClient_Basic**](examples/Generic/WiFiNINA/NINA_NTPClient_Basic) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

Following is the debug terminal output when running example [**NINA_NTPClient_Basic**](examples/Generic/WiFiNINA/NINA_NTPClient_Basic) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Starting NINA_NTPClient_Basic on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
NTPClient_Generic v3.5.0
Connecting to: HueNet1

NINA_NTPClient_Basic started @ IP address: 192.168.2.153
Using NTP Server pool.ntp.org
******NOT UPDATED******
UTC : 00:00:05
UTC : 00:00:05 Thu 01 Jan 1970
LOC : 02:28:21
LOC : 02:28:21 Sun 07 Feb 2106
UTC EPOCH : 5
LOC EPOCH : 4294952901
UTC : 0:0:5 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:05 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:21 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:21 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 04:44:54
UTC : 04:44:54 Fri 04 Jun 2021
LOC : 00:44:54
LOC : 00:44:54 Fri 04 Jun 2021
UTC EPOCH : 1622781894
LOC EPOCH : 1622767494
UTC : 4:44:54 Fri 4/6/2021 or 4 Jun 2021
UTC : 04:44:54 Fri 4/6/2021 or 4 Jun 2021
LOC : 0:44:54 Fri 4/6/2021 or 4 Jun 2021
LOC : 00:44:54 Fri 4/6/2021 or 4 Jun 2021
********UPDATED********
UTC : 04:45:04
UTC : 04:45:04 Fri 04 Jun 2021
LOC : 00:45:04
LOC : 00:45:04 Fri 04 Jun 2021
UTC EPOCH : 1622781904
LOC EPOCH : 1622767504
UTC : 4:45:4 Fri 4/6/2021 or 4 Jun 2021
UTC : 04:45:04 Fri 4/6/2021 or 4 Jun 2021
LOC : 0:45:4 Fri 4/6/2021 or 4 Jun 2021
LOC : 00:45:04 Fri 4/6/2021 or 4 Jun 2021
```

---

#### 14. [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library

Following is the debug terminal output when running example [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library

```
Starting Ethernet_NTPClient_Advanced on RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library
NTPClient_Generic v3.5.0
[EWS] =========== USE_ETHERNET2 ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] RPIPICO setCsPin: 17
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 10
You're connected to the network, IP = 192.168.2.94
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:02
UTC : 00:00:02 Thu 01 Jan 1970
LOC : 02:28:18
LOC : 02:28:18 Sun 07 Feb 2106
UTC EPOCH : 2
LOC EPOCH : 4294952898
UTC : 0:0:2 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:02 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:18 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:18 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 03:43:51
UTC : 03:43:51 Sat 05 Jun 2021
LOC : 23:43:51
LOC : 23:43:51 Fri 04 Jun 2021
UTC EPOCH : 1622864631
LOC EPOCH : 1622850231
UTC : 3:43:51 Sat 5/6/2021 or 5 Jun 2021
UTC : 03:43:51 Sat 5/6/2021 or 5 Jun 2021
LOC : 23:43:51 Fri 4/6/2021 or 4 Jun 2021
LOC : 23:43:51 Fri 4/6/2021 or 4 Jun 2021
********UPDATED********
UTC : 03:44:01
UTC : 03:44:01 Sat 05 Jun 2021
LOC : 23:44:01
LOC : 23:44:01 Fri 04 Jun 2021
UTC EPOCH : 1622864641
LOC EPOCH : 1622850241
UTC : 3:44:1 Sat 5/6/2021 or 5 Jun 2021
UTC : 03:44:01 Sat 5/6/2021 or 5 Jun 2021
LOC : 23:44:1 Fri 4/6/2021 or 4 Jun 2021
LOC : 23:44:01 Fri 4/6/2021 or 4 Jun 2021
```

---

#### 15. [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library

Following is the debug terminal output when running example [**Ethernet_NTPClient_Advanced**](examples/Generic/Ethernet/Ethernet_NTPClient_Advanced) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library

```
Starting Ethernet_NTPClient_Advanced on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet2 Library
NTPClient_Generic v3.5.0
[EWS] =========== USE_ETHERNET2 ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 3
[EWS] MISO: 4
[EWS] SCK: 2
[EWS] SS: 5
[EWS] =========================
[EWS] RPIPICO setCsPin: 5
=========================
Currently Used SPI pinout:
MOSI:3
MISO:4
SCK:2
SS:5
=========================
Using mac index = 5
You're connected to the network, IP = 192.168.2.123
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:02
UTC : 00:00:02 Thu 01 Jan 1970
LOC : 02:28:18
LOC : 02:28:18 Sun 07 Feb 2106
UTC EPOCH : 2
LOC EPOCH : 4294952898
UTC : 0:0:2 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:02 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:18 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:18 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 03:50:11
UTC : 03:50:11 Sat 05 Jun 2021
LOC : 23:50:11
LOC : 23:50:11 Fri 04 Jun 2021
UTC EPOCH : 1622865011
LOC EPOCH : 1622850611
UTC : 3:50:11 Sat 5/6/2021 or 5 Jun 2021
UTC : 03:50:11 Sat 5/6/2021 or 5 Jun 2021
LOC : 23:50:11 Fri 4/6/2021 or 4 Jun 2021
LOC : 23:50:11 Fri 4/6/2021 or 4 Jun 2021
```

---

#### 16. [**NINA_TZ_NTP_WorldClock**](examples/Generic/WiFiNINA/NINA_TZ_NTP_WorldClock) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

Following is the debug terminal output when running example [**NINA_TZ_NTP_WorldClock**](examples/Generic/WiFiNINA/NINA_TZ_NTP_WorldClock) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Starting NINA_TZ_NTP_WorldClock on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
NTPClient_Generic v3.5.0
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
********UPDATED********
Time updated. Next update in seconds : 3600

14:38:12 Sat 05 Jun 2021 AEST Sydney
07:38:12 Sat 05 Jun 2021 MSK  Moscow
06:38:12 Sat 05 Jun 2021 CEST Paris
05:38:12 Sat 05 Jun 2021 BST  London
04:38:12 Sat 05 Jun 2021 UTC  Universal Coordinated Time
00:38:12 Sat 05 Jun 2021 EDT  New York
23:38:12 Fri 04 Jun 2021 CDT  Chicago
22:38:12 Fri 04 Jun 2021 MDT  Denver
21:38:12 Fri 04 Jun 2021 MST  Phoenix
21:38:12 Fri 04 Jun 2021 PDT  Los Angeles

14:38:22 Sat 05 Jun 2021 AEST Sydney
07:38:22 Sat 05 Jun 2021 MSK  Moscow
06:38:22 Sat 05 Jun 2021 CEST Paris
05:38:22 Sat 05 Jun 2021 BST  London
04:38:22 Sat 05 Jun 2021 UTC  Universal Coordinated Time
00:38:22 Sat 05 Jun 2021 EDT  New York
23:38:22 Fri 04 Jun 2021 CDT  Chicago
22:38:22 Fri 04 Jun 2021 MDT  Denver
21:38:22 Fri 04 Jun 2021 MST  Phoenix
21:38:22 Fri 04 Jun 2021 PDT  Los Angeles
```

---

#### 17. [**WT32_ETH01_TZ_NTP_WorldClock**](examples/WT32_ETH01/WT32_ETH01_TZ_NTP_WorldClock) on ESP32_DEV with ETH_PHY_LAN8720

Following is the debug terminal output when running example [**WT32_ETH01_TZ_NTP_WorldClock**](examples/WT32_ETH01/WT32_ETH01_TZ_NTP_WorldClock) on ESP32_DEV with ETH_PHY_LAN8720

```
Starting WT32_ETH01_TZ_NTP_WorldClock on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.2.0
NTPClient_Generic v3.5.0
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232
FULL_DUPLEX, 100Mbps
WT32_ETH01_TZ_NTP_WorldClock started @ IP address: 192.168.2.232
********UPDATED********
Time updated. Next update in seconds : 3600

02:52:08 Sat 17 Jul 2021 AEST Sydney
19:52:08 Fri 16 Jul 2021 MSK  Moscow
18:52:08 Fri 16 Jul 2021 CEST Paris
17:52:08 Fri 16 Jul 2021 BST  London
16:52:08 Fri 16 Jul 2021 UTC  Universal Coordinated Time
12:52:08 Fri 16 Jul 2021 EDT  New York
11:52:08 Fri 16 Jul 2021 CDT  Chicago
10:52:08 Fri 16 Jul 2021 MDT  Denver
09:52:08 Fri 16 Jul 2021 MST  Phoenix
09:52:08 Fri 16 Jul 2021 PDT  Los Angeles

02:52:18 Sat 17 Jul 2021 AEST Sydney
19:52:18 Fri 16 Jul 2021 MSK  Moscow
18:52:18 Fri 16 Jul 2021 CEST Paris
17:52:18 Fri 16 Jul 2021 BST  London
16:52:18 Fri 16 Jul 2021 UTC  Universal Coordinated Time
12:52:18 Fri 16 Jul 2021 EDT  New York
11:52:18 Fri 16 Jul 2021 CDT  Chicago
10:52:18 Fri 16 Jul 2021 MDT  Denver
09:52:18 Fri 16 Jul 2021 MST  Phoenix
09:52:18 Fri 16 Jul 2021 PDT  Los Angeles
```

---

#### 18. [**WT32_ETH01_NTPClient_Advanced**](examples/WT32_ETH01/WT32_ETH01_NTPClient_Advanced) on ESP32_DEV with ETH_PHY_LAN8720

Following is the debug terminal output when running example [**WT32_ETH01_NTPClient_Advanced**](examples/WT32_ETH01/WT32_ETH01_NTPClient_Advanced) on ESP32_DEV with ETH_PHY_LAN8720

```
Starting WT32_ETH01_NTPClient_Advanced on ESP32_DEV with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.2.0
NTPClient_Generic v3.5.0
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232
FULL_DUPLEX, 100Mbps
WT32_ETH01_NTPClient_Advanced started @ IP address: 192.168.2.232
Using NTP Server 0.ca.pool.ntp.org
******NOT UPDATED******
UTC : 00:00:04
UTC : 00:00:04 Thu 01 Jan 1970
LOC : 02:28:20
LOC : 02:28:20 Sun 07 Feb 2106
UTC EPOCH : 4
LOC EPOCH : 4294952900
UTC : 0:0:4 Thu 1/1/1970 or 1 Jan 1970
UTC : 00:00:04 Thu 1/1/1970 or 1 Jan 1970
LOC : 2:28:20 Sun 7/2/2106 or 7 Feb 2106
LOC : 02:28:20 Sun 7/2/2106 or 7 Feb 2106
********UPDATED********
UTC : 16:02:19
UTC : 16:02:19 Fri 16 Jul 2021
LOC : 12:02:19
LOC : 12:02:19 Fri 16 Jul 2021
UTC EPOCH : 1626451339
LOC EPOCH : 1626436939
UTC : 16:2:19 Fri 16/7/2021 or 16 Jul 2021
UTC : 16:02:19 Fri 16/7/2021 or 16 Jul 2021
LOC : 12:2:19 Fri 16/7/2021 or 16 Jul 2021
LOC : 12:02:19 Fri 16/7/2021 or 16 Jul 2021
********UPDATED********
UTC : 16:02:29
UTC : 16:02:29 Fri 16 Jul 2021
LOC : 12:02:29
LOC : 12:02:29 Fri 16 Jul 2021
UTC EPOCH : 1626451349
LOC EPOCH : 1626436949
UTC : 16:2:29 Fri 16/7/2021 or 16 Jul 2021
UTC : 16:02:29 Fri 16/7/2021 or 16 Jul 2021
LOC : 12:2:29 Fri 16/7/2021 or 16 Jul 2021
LOC : 12:02:29 Fri 16/7/2021 or 16 Jul 2021
```


---

#### 19. [**RTL8720DN_TZ_NTP_WorldClock**](examples/RTL8720DN/RTL8720DN_TZ_NTP_WorldClock) on Rtlduino RTL8720DN

Following is the debug terminal output when running example [**RTL8720DN_TZ_NTP_WorldClock**](examples/RTL8720DN/RTL8720DN_TZ_NTP_WorldClock) on Rtlduino RTL8720DN

```
Starting RTL8720DN_TZ_NTP_WorldClock on Rtlduino RTL8720DN
WiFiWebServer_RTL8720 v1.0.1
NTPClient_Generic v3.5.0
Current Firmware Version = 1.0.0
Attempting to connect to SSID: HueNet_5G
TZ_NTP_Clock_RTL8720DN started @ IP address: 192.168.2.111
Retry Time update in seconds : 3
********UPDATED********
Time updated. Next update in seconds : 3600

14:21:42 Tue 10 Aug 2021 AEST Sydney
07:21:42 Tue 10 Aug 2021 MSK  Moscow
06:21:42 Tue 10 Aug 2021 CEST Paris
05:21:42 Tue 10 Aug 2021 BST  London
04:21:42 Tue 10 Aug 2021 UTC  Universal Coordinated Time
00:21:42 Tue 10 Aug 2021 EDT  New York
23:21:42 Mon 09 Aug 2021 CDT  Chicago
22:21:42 Mon 09 Aug 2021 MDT  Denver
21:21:42 Mon 09 Aug 2021 MST  Phoenix
21:21:42 Mon 09 Aug 2021 PDT  Los Angeles

14:21:52 Tue 10 Aug 2021 AEST Sydney
07:21:52 Tue 10 Aug 2021 MSK  Moscow
06:21:52 Tue 10 Aug 2021 CEST Paris
05:21:52 Tue 10 Aug 2021 BST  London
04:21:52 Tue 10 Aug 2021 UTC  Universal Coordinated Time
00:21:52 Tue 10 Aug 2021 EDT  New York
23:21:52 Mon 09 Aug 2021 CDT  Chicago
22:21:52 Mon 09 Aug 2021 MDT  Denver
21:21:52 Mon 09 Aug 2021 MST  Phoenix
21:21:52 Mon 09 Aug 2021 PDT  Los Angeles
```
---
---

### Debug

Debug is enabled by default on Serial. To disable, add at the beginning of sketch

```cpp
/* Comment this out to disable prints and save space */
#define NTP_DBG_PORT                Serial

// Debug Level from 0 to 4
#define _NTP_LOGLEVEL_              0
```

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the board's core, dependent libraries or this library version.

Sometimes, the library will only work if you update the core to the newer or older version because some function compatibility.

---
---

## Releases

### Releases v3.5.0

1. Add support to RTL8720DN, RTL8722DM, RTL8722CSM, etc. boards
2. Add examples with new features

### Releases v3.4.1

1. Fix typo in `library.json`

### Releases v3.4.0

1. Add support to WT32_ETH01 (ESP32 + LAN8720) boards
2. Add examples with new features

### Releases v3.3.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
2. Add support to RP2040-based boards, such as **Nano_RP2040_Connect, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).
3. Add packet validity checks
4. Add version string
5. Improve and add more debugging codes

### Releases v3.2.2

1. Add examples to use **STM32 Built-In RTC.**

### Releases v3.2.1

1. Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
2. Add support to **SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1 with WiFiNINA, W5x00, ENC28J60, LAN8742A Ethernet modules/shields.**
3. Add functions.
4. Completely new examples using NTP time to update DS3231 RTC and/or local clock.

---
---

### Issues

Submit issues to: [NTPClient_Generic issues](https://github.com/khoih-prog/NTPClient_Generic/issues)

---
---

### TO DO

1. Bug Searching and Killing
2. Add more examples

---

### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.) and FlashStorage**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.) and FlashStorage**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.) and FlashStorage**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc. annd LittleFS**.
 5. Add support to **SAM DUE**.
 6. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/adafruit/Ethernet2), or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 7. Add support to Ethernet ENC28J60, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
 8. Add support to Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless and FlashStorage.
 9. Add support to [`EthernetENC`](https://github.com/jandrassy/EthernetENC)
10. Add support to **AVR Mega, UNO, Nano**.
11. Add support to **Arduino Nano_RP2040_Connect** using [**Arduino mbed OS for Nano boards**](https://github.com/arduino/ArduinoCore-mbed).
12. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico).
13. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed)
14. Add Version String and Table-of-Contents 
15. Add support to **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
16. Add support to **RTL8720DN, RTL8722DM, RTL8722CSM, etc. boards**

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [**Fabrice Weinberg's NTPClient Library**](https://github.com/arduino-libraries/NTPClient).
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing.
3. Thanks to [bmcdonnell](https://github.com/bmcdonnell) to make pull request in [Add packet validity checks #4](https://github.com/khoih-prog/NTPClient_Generic/pull/4) leading to v3.3.0

<table>
  <tr>
    <td align="center"><a href="https://github.com/FWeinb"><img src="https://github.com/FWeinb.png" width="100px;" alt="FWeinb"/><br /><sub><b>⭐️ Fabrice Weinberg</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/sandeepmistry"><img src="https://github.com/sandeepmistry.png" width="100px;" alt="sandeepmistry"/><br /><sub><b> Sandeep Mistry</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/bmcdonnell"><img src="https://github.com/bmcdonnell.png" width="100px;" alt="bmcdonnell"/><br /><sub><b>bmcdonnell</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/NTPClient_Generic/blob/main/LICENSE)

---

## Copyright

- Copyright 2015- Fabrice Weinberg

- Copyright 2020- Khoi Hoang


