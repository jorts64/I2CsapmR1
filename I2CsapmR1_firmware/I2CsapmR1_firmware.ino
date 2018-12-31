/*   I2CsapmR1 firmware
 *   I2C slave arduino pro micro for D1 mini R1 kit
 *   firmware for Arduino pro micro 3.3V ATmega328p 8MHz I2C slave
 */

#include "I2CsapmR1_firmware.h"
#include <Wire.h>
#define I2CADDR 2

 byte ordre = 0;
 byte dada = 0; 

 int analin[6];
 int digm[12];
 int digd[12];

 int i;

void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  for (i=0;i<12;i++) digm[i]=INPUT;
  Wire.begin(I2CADDR);
  Wire.onReceive(escolta);
  Wire.onRequest(respon);
}

void loop() {
    analin[0]=analogRead(A0);
    analin[1]=analogRead(A1);
    analin[2]=analogRead(A2);
    analin[3]=analogRead(A3);
    analin[4]=analogRead(A6);
    analin[5]=analogRead(A7);
    for (i=0;i<12;i++){
      if ((digm[i]==INPUT) || (digm[i]==INPUT_PULLUP)){
        digd[i]=digitalRead(i+2);
      }
      
    }
    
}

void escolta(int ordrelen) {
  ordre = Wire.read();
  if (ordrelen>1) {
  dada =  Wire.read();
  switch(ordre) {
    case I2CsapmR1_M2:
      pinMode(2,dada);
      break;
    case I2CsapmR1_M3:
      pinMode(3,dada);
      break;
    case I2CsapmR1_M4:
      pinMode(4,dada);
      break;
    case I2CsapmR1_M5:
      pinMode(5,dada);
      break;
    case I2CsapmR1_M6:
      pinMode(6,dada);
      break;
    case I2CsapmR1_M7:
      pinMode(7,dada);
      break;
    case I2CsapmR1_M8:
      pinMode(8,dada);
      break;
    case I2CsapmR1_M9:
      pinMode(9,dada);
      break;
    case I2CsapmR1_M10:
      pinMode(10,dada);
      break;
    case I2CsapmR1_M11:
      pinMode(11,dada);
      break;
    case I2CsapmR1_M12:
      pinMode(12,dada);
      break;
    case I2CsapmR1_M13:
      pinMode(13,dada);
      break;
    case I2CsapmR1_D2:
      digitalWrite(2,dada);
      break;
    case I2CsapmR1_D3:
      digitalWrite(3,dada);
      break;
    case I2CsapmR1_D4:
      digitalWrite(4,dada);
      break;
    case I2CsapmR1_D5:
      digitalWrite(5,dada);
      break;
    case I2CsapmR1_D6:
      digitalWrite(6,dada);
      break;
    case I2CsapmR1_D7:
      digitalWrite(7,dada);
      break;
    case I2CsapmR1_D8:
      digitalWrite(8,dada);
      break;
    case I2CsapmR1_D9:
      digitalWrite(9,dada);
      break;
    case I2CsapmR1_D10:
      digitalWrite(10,dada);
      break;
    case I2CsapmR1_D11:
      digitalWrite(11,dada);
      break;
    case I2CsapmR1_D12:
      digitalWrite(12,dada);
      break;
    case I2CsapmR1_D13:
      digitalWrite(13,dada);
      break;
    }
  }
}

void respon() {
  int resposta;
  switch(ordre) {
    case I2CsapmR1_A0:
      resposta = analin[0];
      break;
    case I2CsapmR1_A1:
      resposta = analin[1];
      break;
    case I2CsapmR1_A2:
      resposta = analin[2];
      break;
    case I2CsapmR1_A3:
      resposta = analin[3];
      break;
    case I2CsapmR1_A6:
      resposta = analin[4];
      break;
    case I2CsapmR1_A7:
      resposta = analin[5];
      break;
    case I2CsapmR1_D2:
      resposta = digd[0];
      break;
    case I2CsapmR1_D3:
      resposta = digd[1];
      break;
    case I2CsapmR1_D4:
      resposta = digd[2];
      break;
    case I2CsapmR1_D5:
      resposta = digd[3];
      break;
    case I2CsapmR1_D6:
      resposta = digd[4];
      break;
    case I2CsapmR1_D7:
      resposta = digd[5];
      break;
    case I2CsapmR1_D8:
      resposta = digd[6];
      break;
    case I2CsapmR1_D9:
      resposta = digd[7];
      break;
    case I2CsapmR1_D10:
      resposta = digd[8];
      break;
    case I2CsapmR1_D11:
      resposta = digd[9];
      break;
    case I2CsapmR1_D12:
      resposta = digd[10];
      break;
    case I2CsapmR1_D13:
      resposta = digd[11];
      break;
    default:
      resposta = -1;
      break;
  }
  byte buffer[2];
  buffer[0]=resposta >> 8;
  buffer[1]=resposta & 0xff;
  Wire.write(buffer,2);
  ordre=0;
}

