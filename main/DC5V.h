/*
    Ajuste y control de 5V DC usando PWM en el ATmega2560.
    by Angel Habid Navarro 09/27/2024 V0.3
*/
#ifndef DC5V_h
#define DC5V_h
#include "Arduino.h"
#include "Utils.h" // Importamos la función clearSerialBuffer

/**
 * Configura el pin de salida de PWM para generar un voltaje DC ajustable entre 0 y 5V.
 * 
 * @param voltage Voltaje deseado (debe estar entre 0V y 5V).
 */
void setDCVoltage(float voltage);

/**
 * Muestra el menú serial interactivo para ajustar el voltaje DC.
 * Permite ingresar un valor entre 0 y 5V y ajusta el voltaje generado por PWM en consecuencia.
 */
void VDC5Menu(void);

/**
 * Lee la entrada del usuario desde el puerto serial.
 * Ignora caracteres no deseados como '\n' y '\r' y valida que la entrada sea un valor flotante válido.
 * 
 * @return Un valor flotante válido introducido por el usuario.
 */
float readVoltageInput(void);

#endif
