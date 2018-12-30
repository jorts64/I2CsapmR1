//
//    FILE: I2CsapmR1.cpp
//  AUTHOR: Jordi Orts
//    DATE: 30-12-2018
// VERSION: 0.2.0
// PURPOSE: I2C slave arduino pro micro
//     URL: http://github.com/jorts64/I2CsapmR1
//
// HISTORY:
// 0.2.00 initial version for kit D1 mini
//

#include "I2CsapmR1.h"

#include <Wire.h>

I2CsapmR1::I2CsapmR1(const uint8_t deviceAddress)
{
    _address = deviceAddress;
    _dataIn = 0;
    _dataOut = 0xFF;
}

void I2CsapmR1::begin()
{
  Wire.begin();
}

int16_t I2CsapmR1::read(const uint8_t reg)
{
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.endTransmission();
  Wire.beginTransmission(_address);
  Wire.requestFrom(_address,(uint8_t)2);
  _dataIn = Wire.read()<<8 | Wire.read();
  Wire.endTransmission();
  return(_dataIn);
}

void I2CsapmR1::write(const uint8_t reg, const uint8_t dat)
{
  Wire.beginTransmission(_address);
  Wire.write(reg);
  Wire.write(dat);
  Wire.endTransmission();
}


//
// END OF FILE
//
