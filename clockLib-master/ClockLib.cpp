#include <Wire.h>
#include <Arduino.h>
#include <ClockLib.h>
#define DS1307 0x68

static uint8_t bcdToDec (uint8_t val) { return ((val/16*10) + (val%16)); }
static uint8_t decToBcd (uint8_t val) { return ((val/10*16) + (val%10)); }

void Clock::setTime(int h, int m, int s) {
    // The following codes transmits the data to the RTC
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0));
    Wire.write(decToBcd(s));
    Wire.write(decToBcd(m));
    Wire.write(decToBcd(h));
    Wire.write(byte(0));
    Wire.endTransmission();
    // Ends transmission of data
}

int Clock::getSec() {
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0));
    Wire.endTransmission();
    Wire.requestFrom(DS1307, 1);
    return bcdToDec(Wire.read());
    
}

int Clock::getMin() {
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0));
    Wire.endTransmission();
    Wire.requestFrom(DS1307, 2);
    Wire.read();
    return bcdToDec(Wire.read());
}

int Clock::getHour(){
    Wire.beginTransmission(DS1307);
    Wire.write(byte(0));
    Wire.endTransmission();
    Wire.requestFrom(DS1307, 3);
    Wire.read();
    Wire.read();
    return bcdToDec(Wire.read());
}