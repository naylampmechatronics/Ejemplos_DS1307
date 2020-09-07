/****************************************************************************************
 Encendido Programado
  
  Programa para activar una salida digotal(foco, motor, etc) en un horario determinado
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

int segundo,minuto,hora,dia,mes,diaDeLaSemana;

DateTime HoraFecha;

void setup () {
  Serial.begin(9600);
  rtc.begin(); //Inicializamos el RTC
  pinMode(2, OUTPUT);
}

void loop () {
    HoraFecha = rtc.now(); //obtenemos la hora y fecha actual
    
    segundo=HoraFecha.second();
    minuto=HoraFecha.minute();
    hora=HoraFecha.hour();
    diaDeLaSemana=HoraFecha.dayOfTheWeek(); //0:Dominogo, 1:Lunes, 2:Martes ...
    
    float horas=hora+minuto/60.0;

    //condicion: >Domingo y  <sabado    y   >6.30pm  y <11.30pm
    if(diaDeLaSemana>0&&diaDeLaSemana<7 && horas>18.5&&horas<23.5)
    {
      digitalWrite(2, HIGH);
      Serial.print("Salida digital 13 = ON");
    }
    else
    {
      digitalWrite(2, LOW);
      Serial.print("Salida digital 13 = OFF");
    }

    //Enviamos por el puerto serie la hora y fecha.
    Serial.print("   hora = ");
    Serial.print(hora);
    Serial.print(":");
    Serial.print(minuto);
    Serial.print(":");
    Serial.print(segundo);
    Serial.print("  dia de La semana = ");
    Serial.print(HoraFecha.dayOfTheWeek());
    Serial.println();
    delay(1000);
}
