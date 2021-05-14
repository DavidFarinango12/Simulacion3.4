//////////////////////ESCLAVO/////////////

#include <Wire.h>

char dato;
const int led1=8;
const int led2=9;
const int led3=10;


void setup() {
  Wire.begin(4);        // ID de esclavo
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}


void loop() {
  
}


void receiveEvent(int bytes){
  while(Wire.available()){
    dato=Wire.read();
    switch (dato){
      case 'A':
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
      break;
      case 'B':
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
      break;
      case 'C':
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,HIGH);
      break;
      default:
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
      break;
    }
  }

}
