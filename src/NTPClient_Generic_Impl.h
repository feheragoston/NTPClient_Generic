/****************************************************************************************************************************
  NTPClient_Generic_Impl.h
 
  For AVR, ESP8266/ESP32, SAMD21/SAMD51, nRF52, STM32, SAM DUE, WT32_ETH01, RTL8720DN boards using 
  a) Ethernet W5x00, ENC28J60, LAN8742A
  b) WiFiNINA
  c) ESP8266/ESP32 WiFi
  d) ESP8266/ESP32-AT-command WiFi
  e) WT32_ETH01 (ESP32 + LAN8720)
  f) RTL8720DN
  g) Portenta_H7

  Based on and modified from Arduino NTPClient Library (https://github.com/arduino-libraries/NTPClient)
  to support other boards such as ESP8266/ESP32, SAMD21, SAMD51, Adafruit's nRF52 boards, SAM DUE, RTL8720DN, etc.
  and Ethernet/WiFi/WiFiNINA shields
  
  Copyright (C) 2015 by Fabrice Weinberg and licensed under MIT License (MIT)

  Built by Khoi Hoang https://github.com/khoih-prog/NTPClient_Generic
  Licensed under MIT license
  
  Version: 3.7.4

  Version Modified By  Date      Comments
  ------- -----------  ---------- -----------
  3.2.1   K Hoang      27/10/2020 Initial porting to support SAM DUE, SAMD21, SAMD51, nRF52, ESP32/ESP8266, STM32, etc. boards 
                                  using Ethernet/WiFi/WiFiNINA shields. Add more features and functions.
  3.2.2   K Hoang      28/10/2020 Add examples to use STM32 Built-In RTC.
  3.3.0   K Hoang      04/06/2021 Add support to RP2040-based boards. Add packet validity checks, version string and debug
  3.4.0   K Hoang      16/07/2021 Add support to WT32_ETH01 (ESP32 + LAN8720)
  3.5.0   K Hoang      10/08/2021 Add support to Ameba Realtek RTL8720DN, RTL8722DM and RTL8722CSM
  3.5.1   K Hoang      12/10/2021 Update `platform.ini` and `library.json`
  3.5.2   K Hoang      01/12/2021 Auto detect ESP32 core version. Fix bug in examples for WT32_ETH01
  3.6.0   K Hoang      08/01/2022 Fix `multiple-definitions` linker error. Add support to Portenta_H7
  3.7.0   K Hoang      20/01/2022 Make compatible to old code
  3.7.1   K Hoang      20/01/2022 Fix getUTCEpochMillis() bug
  3.7.2   K Hoang      23/02/2022 Add setUDP() function to enable auto-switching between WiFi and Ethernet UDP
  3.7.3   K Hoang      05/04/2022 Use Ethernet_Generic library as default. Support SPI1/SPI2 for RP2040/ESP32
  3.7.4   K Hoang      27/04/2022 Sync with NTPClient releases v3.2.1
 *****************************************************************************************************************************/

#pragma once

// Reintroduce to prevent duplication compile error, pragma once can't prevent
#ifndef NTPCLIENT_GENERIC_IMPL_H
#define NTPCLIENT_GENERIC_IMPL_H

/////////////////////////////

NTPClient::NTPClient(const long& timeOffset)
{
  this->_timeOffset     = timeOffset;
}

/////////////////////////////

NTPClient::NTPClient(UDP& udp, const long& timeOffset)
{
  this->_udp            = &udp;
  this->_timeOffset     = timeOffset;
}

/////////////////////////////

NTPClient::NTPClient(UDP& udp, const char* poolServerName, const long& timeOffset, const unsigned long& updateInterval)
{
  this->_udp            = &udp;
  this->_timeOffset     = timeOffset;
  this->_poolServerName = poolServerName;
  this->_updateInterval = updateInterval;
}

/////////////////////////////

NTPClient::NTPClient(UDP& udp, const IPAddress& poolServerIP, const long& timeOffset, const unsigned long& updateInterval)
{
  this->_udp            = &udp;
  this->_timeOffset     = timeOffset;
  this->_poolServerIP   = poolServerIP;
  this->_poolServerName = NULL;
  this->_updateInterval = updateInterval;
}

/////////////////////////////

void NTPClient::begin(int port)
{
  this->_port = port;

  this->_udp->begin(this->_port);

  this->_udpSetup = true;
}

/////////////////////////////

// Perform some validity checks on the packet
//  https://datatracker.ietf.org/doc/html/rfc4330#section-4
// Check length before calling
static bool isValid(byte const *ntpPacket)
{
  unsigned long highWord = word(ntpPacket[16], ntpPacket[17]);
  unsigned long lowWord  = word(ntpPacket[18], ntpPacket[19]);
  unsigned long refTimeInt  = highWord << 16 | lowWord;
  highWord = word(ntpPacket[20], ntpPacket[21]);
  lowWord  = word(ntpPacket[22], ntpPacket[23]);
  unsigned long refTimeFrac = highWord << 16 | lowWord;

  byte leapIndicator = ((ntpPacket[0] & 0b11000000) >> 6);
  byte version       = ((ntpPacket[0] & 0b00111000) >> 3);
  byte stratum       =   ntpPacket[1];
  
  NTP_LOGDEBUG3("isValid: leapIndicator (!=3) =", leapIndicator, ", version (>=1) =", version);
  NTP_LOGDEBUG3("stratum (1 <= stratum <= 15) =", stratum, ", refTimeInt (!= 0) =", refTimeInt);
  NTP_LOGDEBUG1("refTimeFrac (!= 0) =", refTimeFrac);
  
  return
  (
    (leapIndicator !=  3) && // LI != UNSYNC
    (version       >=  1) &&
    (stratum       >=  1) &&
    (stratum       <= 15) &&
    ((refTimeInt != 0) || (refTimeFrac != 0))
  );
}

/////////////////////////////

bool NTPClient::checkResponse()
{
  if (this->_udp->parsePacket())
  {
    this->_lastRequest = 0; // no outstanding request
    int numBytesRead = this->_udp->read(this->_packetBuffer, NTP_PACKET_SIZE);
    
    NTP_LOGDEBUG1("numBytesRead (48) =", numBytesRead);

    if ((numBytesRead == NTP_PACKET_SIZE) && isValid(this->_packetBuffer))
    {
      this->_lastUpdate = millis();

      unsigned long highWord = word(this->_packetBuffer[40], this->_packetBuffer[41]);
      unsigned long lowWord = word(this->_packetBuffer[42], this->_packetBuffer[43]);

      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;

      this->_currentEpoc = secsSince1900 - SEVENTYYEARS;

      highWord = word(this->_packetBuffer[44], this->_packetBuffer[45]);
      lowWord = word(this->_packetBuffer[46], this->_packetBuffer[47]);
      this->_currentFraction = highWord << 16 | lowWord;

      // if the user has set a callback function for when the time is updated, call it
      if (_updateCallback)
      {
        _updateCallback(this);
      }

      return true;
    }
  }

  return false;
}

/////////////////////////////

bool NTPClient::forceUpdate()
{
  NTP_LOGDEBUG("forceUpdate from NTP Server");

  // flush any existing packets
  while (this->_udp->parsePacket() != 0)
  {
    this->_udp->flush();
  }

  this->sendNTPPacket();

  // Wait till data is there or timeout...
  byte timeout  = 0;
  bool  cb      = false;

  do
  {
    delay ( 10 );
    cb = this->checkResponse();

    if (timeout > 100)
      return false; // timeout after 1000 ms

    timeout++;
  } while (cb == false);

  return true;
}

/////////////////////////////

bool NTPClient::update()
{
  bool updated = false;
  unsigned long now = millis();
  
  NTP_LOGDEBUG("Update from NTP Server");

  if ( ((_lastRequest == 0) && (_lastUpdate == 0))                              // Never requested or updated
       || ((_lastRequest == 0) && ((now - _lastUpdate) >= _updateInterval))     // Update after _updateInterval
       || ((_lastRequest != 0) && ((now - _lastRequest) > _retryInterval)) )    // Update if there was no response to the request
  {
    // setup the UDP client if needed
    if (!this->_udpSetup) 
    {
      this->begin();
    }

    // flush any existing packets
    while (this->_udp->parsePacket() != 0)
    {
      this->_udp->flush();
    }

    this->sendNTPPacket();
  }

  if (_lastRequest) 
  {
    updated = checkResponse();
  }

  return updated;
}

/////////////////////////////

unsigned long long NTPClient::getUTCEpochMillis() 
{
  unsigned long long epoch;

  epoch  = (unsigned long long)this->_currentEpoc * 1000;       // last time returned via server in millis
  epoch += this->_currentFraction / FRACTIONSPERMILLI;          // add the fraction from the server
  epoch += millis() - this->_lastUpdate;                        // add the millis that have passed since the last update

  return epoch;
}

/////////////////////////////

unsigned long long NTPClient::getEpochMillis() 
{
  unsigned long long epoch;
  
  epoch = (this->_timeOffset * 1000) + getUTCEpochMillis();

  return epoch;
}

/////////////////////////////

String NTPClient::createFormattedTime(const unsigned long& rawTime) const 
{
  unsigned long tempo   = hour(rawTime);
  String hoursStr       = tempo < 10 ? "0" + String(tempo) : String(tempo);

  tempo   = minute(rawTime);
  String minuteStr      = tempo < 10 ? "0" + String(tempo) : String(tempo);

  tempo   = second(rawTime);
  String secondStr      = tempo < 10 ? "0" + String(tempo) : String(tempo);

  return hoursStr + ":" + minuteStr + ":" + secondStr;
}

/////////////////////////////

String NTPClient::getFormattedTime() const 
{
  return createFormattedTime(this->getEpochTime());
}

/////////////////////////////

String NTPClient::getFormattedUTCTime() const 
{
  return createFormattedTime(this->getUTCEpochTime());
}

/////////////////////////////

String NTPClient::getFormattedDateTime() const 
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
   
  time_t t = this->getEpochTime();
  
  memset(buf, 0, sizeof(buf));
  memset(m, 0, sizeof(m));
  
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%2d:%2d:%2d %s %2d %s %d", hour(t), minute(t), second(t), 
                                    dayShortStr(weekday(t)), day(t), m, year(t));
  
  return String(buf);
}

/////////////////////////////

String NTPClient::getFormattedUTCDateTime() const 
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
    
  time_t t = this->getEpochTime() - _timeOffset;
  
  memset(buf, 0, sizeof(buf));
  memset(m, 0, sizeof(m));
  
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%2d:%2d:%2d %s %2d %s %d", hour(t), minute(t), second(t), 
                                    dayShortStr(weekday(t)), day(t), m, year(t));
  
  return String(buf);
}

/////////////////////////////

void NTPClient::sendNTPPacket() 
{
  // set all bytes in the buffer to 0
  memset(this->_packetBuffer, 0, NTP_PACKET_SIZE);
  
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  this->_packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  this->_packetBuffer[1] = 0;     // Stratum, or type of clock
  this->_packetBuffer[2] = 6;     // Polling Interval
  this->_packetBuffer[3] = 0xEC;  // Peer Clock Precision
  
  // 8 bytes of zero for Root Delay & Root Dispersion
  this->_packetBuffer[12]  = 49;
  this->_packetBuffer[13]  = 0x4E;
  this->_packetBuffer[14]  = 49;
  this->_packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  if  (this->_poolServerName) 
  {
    this->_udp->beginPacket(this->_poolServerName, NTP_SEVER_PORT);
  } 
  else 
  {
    this->_udp->beginPacket(this->_poolServerIP, NTP_SEVER_PORT);
  }
  
  this->_udp->write(this->_packetBuffer, NTP_PACKET_SIZE);
  this->_udp->endPacket();

  this->_lastRequest = millis();
}

#endif    // NTPCLIENT_GENERIC_IMPL_H
