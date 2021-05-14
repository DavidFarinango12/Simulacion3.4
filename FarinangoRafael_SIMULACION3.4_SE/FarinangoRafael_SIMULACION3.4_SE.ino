/*
 *CAPITULO III: MODULOS DE COMUNICACION I2C
 *CODIGO 13: ENVIO Y RECEPCION DE DATOS COMPLEJOS POR COMUNICACION I2C
 *OBJETIVO: EL USUARIO ENVIA CARACTERES POR COMUNICACION SERIAL Y EL MASTER LO RECIBE Y ENVIA POR I2C HACIA EL ESCLAVO
 *          Y SEGUN EL DATO ENVIADO ENCIENDE UN LED
 *NOMBRE: RAFAEL FARINANGO
 */

////////////////////////////////MASTER///////////////////

#include <Wire.h>
char dato;


void setup() {
  Wire.begin();
  Serial.begin(9600);
}


void loop() {
  if(Serial.available()>0){       //verifica si existe datos
    dato=Serial.read();           //almacena el dato
    Wire.beginTransmission(4);    //empieza la comunicacion I2C
    Wire.write(dato);             //envio dato
    Wire.endTransmission();       //termina la comunicacion I2C  
  }
  
}
