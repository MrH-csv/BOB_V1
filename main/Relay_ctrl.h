/*
  by Angel Habid Navarro 12/09/2024 BOB_V0.1
*/

#ifndef RELAY_CTRL_H
#define RELAY_CTRL_H

#include <avr/io.h>
#include <stdio.h>

// Prototipos
void configureRelay(uint8_t channel, uint8_t state);
void displayMenu();

#endif
