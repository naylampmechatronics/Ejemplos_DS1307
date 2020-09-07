/****************************************************************************************
 Actualizar RTC
  
  Programa para actualizar la Hora y Fecha del RTC
  El código es compatible tanto con el DS1307 como el DS3231
  
 Conexiones:
  ------------------------------------------------------------------------
  M. DS1307-> Arduino Uno,Nano,Mini | Arduino Mega,DUE | Arduino Leonardo
  ------------------------------------------------------------------------
  SCL      ->   A5                  |   21             |   3
  SDA      ->   A4                  |   20             |   2 
  VCC      ->   5V                  |   5V             |   5V
  GND      ->   GND                 |   GND            |   GND
  ------------------------------------------------------------------------
  *No se puede cambiar de pines, los pines indicados son para la comunicación I2C 
   y son los pines SDA y SCL de cada placa respectivamente
  
 Dirección
  La dirección I2C del DS1307 y también del DS3231 es 0x68 y no se puede cambiar
 
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 06/09/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/52_tutorial-rtc-ds1307-y-eeprom-at24c32.html
   -https://github.com/naylampmechatronics/Ejemplos_DS1307
**************************************************************************************************/
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;
//RTC_DS3231 rtc; //Para un DS3231

void setup () {
  Serial.begin(9600);
  rtc.begin(); //Inicializamos el RTC
  Serial.println("Estableciendo Hora y fecha...");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//Hora de compilación
  rtc.adjust(DateTime(2016,6,10,18,29,0));//2016,Junio,10,18 h,29 min,0 seg
  Serial.println("DS1307 actualizado con la hora y fecha que se compilo este programa:");
  Serial.print("Fecha = ");
  Serial.print(__DATE__);
  Serial.print("  Hora = ");
  Serial.println(__TIME__);
}

void loop () {
}
