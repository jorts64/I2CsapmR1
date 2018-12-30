#include <Wire.h>  // Include Wire if you're using I2C
#include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

#include "I2Csapm.h"
I2Csapm SAPM(2);

#define PIN_RESET 255  // Connect RST to pin 9
#define DC_JUMPER 0

MicroOLED oled(PIN_RESET, DC_JUMPER);    // I2C declaration

void setup()
{
  SAPM.begin();
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.display();  // Display what's in the buffer (splashscreen)
  SAPM.write(I2Csapm_LED_ON);
  delay(1000);     // Delay 1000 ms
  SAPM.write(I2Csapm_LED_OFF);
  delay(1000);     // Delay 1000 ms
  SAPM.write(I2Csapm_LED_ON);
  oled.clear(PAGE); // Clear the buffer.
  
}

void loop()
{
  int y;
  for (int i=0; i<63; i++)
  {
    y = SAPM.read(I2Csapm_A0);
    oled.pixel(i, 47-y/25);
    oled.display();
    delay(25);
  }
  oled.clear(PAGE);
}


