/*
  by Angel Habid Navarro 09/27/2024 V0.3
*/
#ifndef UTILS_H
#define UTILS_H
#include "Arduino.h"

/**
 * Limpia el buffer serial para garantizar que no queden datos residuales.
 */
inline void clearSerialBuffer() {
    while (Serial.available() > 0) {
        Serial.read();
    }
}

#endif