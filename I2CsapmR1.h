//
//    FILE: I2CsapmR1.H
//  AUTHOR: Jordi Orts
//    DATE: 31-12-2018
// VERSION: 1.0.0
// PURPOSE: I2C slave arduino pro micro
//     URL: http://github.com/jorts64/I2CsapmR1
//
// HISTORY:
// see I2CsapmR1.cpp file
//

#ifndef _I2CsapmR1_H
#define _I2CsapmR1_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define I2CsapmR1_LIB_VERSION "0.2.0"

#define I2CsapmR1_A0   0
#define I2CsapmR1_A1   1
#define I2CsapmR1_A2   2
#define I2CsapmR1_A3   3
#define I2CsapmR1_A6   4
#define I2CsapmR1_A7   5
#define I2CsapmR1_D2   6
#define I2CsapmR1_D3   7
#define I2CsapmR1_D4   8
#define I2CsapmR1_D5   9
#define I2CsapmR1_D6  10
#define I2CsapmR1_D7  11
#define I2CsapmR1_D8  12
#define I2CsapmR1_D9  13
#define I2CsapmR1_D10 14
#define I2CsapmR1_D11 15
#define I2CsapmR1_D12 16
#define I2CsapmR1_D13 17
#define I2CsapmR1_M2  18
#define I2CsapmR1_M3  19
#define I2CsapmR1_M4  20
#define I2CsapmR1_M5  21
#define I2CsapmR1_M6  22
#define I2CsapmR1_M7  23
#define I2CsapmR1_M8  24
#define I2CsapmR1_M9  25
#define I2CsapmR1_M10 26
#define I2CsapmR1_M11 27
#define I2CsapmR1_M12 28
#define I2CsapmR1_M13 29


class I2CsapmR1
{
public:
    explicit I2CsapmR1(const uint8_t deviceAddress);

    void begin();

    int16_t read(uint8_t reg);
    void write(const uint8_t reg, const uint8_t dat);

private:
    uint8_t _address;
    int16_t _dataIn;
    uint8_t _dataOut;
};

#endif
//
// END OF FILE
//

