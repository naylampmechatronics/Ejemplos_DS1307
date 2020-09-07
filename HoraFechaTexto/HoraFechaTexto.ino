/****************************************************************************************
 Hora y Fecha en Texto
  
  Programa para leer la Hora y Fecha en formato de texto
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

char nombreDia[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};
char nombreMes[12][12]= {"Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
int segundo,minuto,hora,dia,mes,diaDeLaSemana;
long anio; //variable año

DateTime HoraFecha;

void setup () {
  Serial.begin(9600);
  rtc.begin(); //Inicializamos el RTC
}

void loop () {
    HoraFecha = rtc.now(); //obtenemos la hora y fecha actual
    
    segundo=HoraFecha.second();
    minuto=HoraFecha.minute();
    hora=HoraFecha.hour();
    dia=HoraFecha.day();
    mes=HoraFecha.month();
    anio=HoraFecha.year();
    diaDeLaSemana=HoraFecha.dayOfTheWeek();
    

    //Enviamos por el puerto serie la hora y fecha.
    Serial.print(hora);
    Serial.print(":");
    Serial.print(minuto);
    Serial.print(":");
    Serial.print(segundo);
    Serial.print(" , ");
    Serial.print(nombreDia[diaDeLaSemana]);
    Serial.print(" ");
    Serial.print(dia);
    Serial.print(" de ");
    Serial.print(nombreMes[mes-1]);
    Serial.print(" del ");
    Serial.print(anio);
    Serial.println();
    delay(1000);
}
