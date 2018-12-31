#include "I2CsapmR1.h"
#include <Wire.h>

I2CsapmR1 SAPM(2);

void setup() {
   Serial.begin(9600);
   SAPM.begin();
   SAPM.write(I2CsapmR1_M2,OUTPUT);
   SAPM.write(I2CsapmR1_M3,INPUT_PULLUP);
}

void loop() {
   SAPM.write(I2CsapmR1_D2,HIGH);
   int sensorValue = SAPM.read(I2CsapmR1_A0);
   int digValue = SAPM.read(I2CsapmR1_D3);
   Serial.print(sensorValue);
   Serial.print("  /   ");
   Serial.println(digValue);
   delay(100);
   SAPM.write(I2CsapmR1_D2,LOW);
   delay(100);
}
