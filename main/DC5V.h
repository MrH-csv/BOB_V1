/*
  Ajuste y control de PWM para generacion de señal analogica
  con el ATmega2560 programado con arduino.
  by Angel Habid Navarro 09/27/2024 V0.1
*/
#ifndef DC5V_h
#define DC5V_h

#include "Arduino.h"

// Definición del pin para la señal DC
#define DC_5V 3 // PE5 -> pin 3 en Arduino

// Prototipo de función
void setDCVoltage(float voltage);
void VDC5Menu(void);

#endif
