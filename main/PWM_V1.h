/*
  Ajuste y control de 2 pines de PWM para el ATmega2560.
  by Angel Habid Navarro 09/27/2024 V0.3
*/
#ifndef PWM_V1_h
#define PWM_V1_h
#include "Arduino.h"
#include "Utils.h" // Importamos la función clearSerialBuffer

// Arduino pin selection
#define PWM_CH1 5 // El pin 13 es temporal; el correcto es el PE3 -> pin 5
#define PWM_CH2 2 // PE4

// Functions

/**
 * Configura el pin seleccionado para operar en modo PWM con la frecuencia y ciclo de trabajo especificados.
 * 
 * @param pin Pin del ATmega2560 que se configurará como salida PWM.
 * @param frequency Frecuencia en Hz del PWM.
 * @param dutyCycle Ciclo de trabajo del PWM en porcentaje (0-100).
 */
void setupPWM(uint8_t pin, uint16_t frequency, uint8_t dutyCycle);

/**
 * Muestra un menú serial interactivo para configurar los pines de PWM.
 * Espera entradas del usuario para seleccionar el canal, frecuencia y ciclo de trabajo.
 * 
 * @return Siempre devuelve 0 al finalizar.
 */
int PWM_1(void);

#endif
