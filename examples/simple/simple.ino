#include "I2Csapm.h"
#include <Wire.h>

I2Csapm SAPM(2);



void setup() {
   Serial.begin(9600);
   SAPM.begin();
}

void loop() {
   SAPM.write(I2Csapm_LED_ON);
//   int sensorValue = SAPM.read(I2Csapm_A0);
   int sensorValue = SAPM.read(I2Csapm_POS);
   Serial.println(sensorValue);
   delay(100);
   SAPM.write(I2Csapm_LED_OFF);
   delay(100);
}
