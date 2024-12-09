/*
  by Angel Habid Navarro 09/27/2024 V0.3
*/
#include "Relay_ctrl.h"

// Función para configurar los relays y LEDs según el canal y el estado seleccionado
void configureRelay(int channel, int state) {
    // No se reinician completamente los puertos; usamos máscaras en hexadecimal para modificar solo los bits necesarios.

    switch (channel) 
    {
        case 1: // Configuración para CH1
            switch (state) {
                case 1: // Connected
                    PORTJ &= 0x7F; // Limpiar PJ7 (bit 7)
                    PORTA &= 0xF3; // Limpiar PA2 (bit 2) y PA3 (bit 3)
                    PORTK = (PORTK & 0x1F) | 0x40; // Limpiar PK5, PK6 y PK7, establecer PK6
                    break;

                case 2: // Disconnected
                    PORTJ &= 0x7F; // Limpiar PJ7 (bit 7)
                    PORTA = (PORTA & 0xF3) | 0x04; // Limpiar PA3 (bit 3), establecer PA2 (bit 2)
                    PORTK &= 0x1F; // Limpiar PK5, PK6 y PK7 (ningún LED activo)
                    break;

                case 3: // Short to Battery
                    PORTJ &= 0x7F; // Limpieza de seguridad en PJ7
                    PORTA &= 0xF3; // Limpieza de PA2 y PA3 antes de configurar
                    PORTJ |= 0x80; // Establecer PJ7 (bit 7)
                    PORTA |= 0x04; // Establecer PA2 (bit 2)
                    PORTK = (PORTK & 0x1F) | 0x80; // Limpiar PK5 y PK6, establecer PK7
                    break;

                case 4: // Short to Gnd
                    PORTJ &= 0x7F; // Limpieza de seguridad en PJ7
                    PORTA &= 0xF3; // Limpieza de PA2 y PA3 antes de configurar
                    PORTA |= 0x0C; // Establecer PA2 (bit 2) y PA3 (bit 3)
                    PORTK = (PORTK & 0x1F) | 0x20; // Limpiar PK6 y PK7, establecer PK5
                    break;
            }
            break;

        case 2: // Configuración para CH2
            switch (state) {
                case 1: // Connected
                    PORTJ &= 0xF8; // Limpiar PJ2, PJ1, PJ0
                    PORTK = (PORTK & 0xE3) | 0x08; // Limpiar PK2 y PK4, establecer PK3
                    break;

                case 2: // Disconnected
                    PORTJ &= 0xF8; // Limpieza de seguridad en PJ2, PJ1, PJ0
                    PORTJ = (PORTJ & 0xF8) | 0x02; // Establecer PJ1
                    PORTK &= 0xE3; // Limpiar PK2, PK3 y PK4 (ningún LED activo)
                    break;

                case 3: // Short to Battery
                    PORTJ &= 0xF8; // Limpieza de seguridad en PJ2, PJ1, PJ0
                    PORTJ = (PORTJ & 0xF8) | 0x06; // Establecer PJ2 y PJ1
                    PORTK = (PORTK & 0xE3) | 0x10; // Limpiar PK2 y PK3, establecer PK4
                    break;

                case 4: // Short to Gnd
                    PORTJ &= 0xF8; // Limpieza de seguridad en PJ2, PJ1, PJ0
                    PORTJ |= 0x01; // Establecer PJ0
                    PORTK = (PORTK & 0xE3) | 0x04; // Limpiar PK3 y PK4, establecer PK2
                    break;
            }
            break;

        case 3: // Configuración para CH3
            switch (state) {
                case 1: // Connected
                    PORTA &= 0x8F; // Limpiar PA4, PA5, PA6
                    PORTF = (PORTF & 0x1F) | 0x10; // Limpiar PF3, PF4 y PF5, establecer PF4
                    break;

                case 2: // Disconnected
                    PORTA &= 0x8F; // Limpieza de PA4, PA5 y PA6 antes de configurar
                    PORTA |= 0x20; // Establecer PA5
                    PORTF &= 0x1F; // Limpiar PF3, PF4 y PF5 (ningún LED activo)
                    break;

                case 3: // Short to Battery
                    PORTA &= 0x8F; // Limpieza de PA4, PA5 y PA6 antes de configurar
                    PORTA |= 0x30; // Establecer PA4 y PA5
                    PORTF = (PORTF & 0x1F) | 0x20; // Limpiar PF3 y PF4, establecer PF5
                    break;

                case 4: // Short to Gnd
                    PORTA &= 0x8F; // Limpieza de PA4, PA5 y PA6 antes de configurar
                    PORTA |= 0x60; // Establecer PA5 y PA6
                    PORTF = (PORTF & 0x1F) | 0x08; // Limpiar PF3, PF4 y PF5, establecer PF3
                    break;
            }
            break;

        case 4: // Configuración para CH4
            switch (state) {
                case 1: // Connected
                    PORTC &= 0x1F; // Limpiar PC7, PC6, PC5
                    PORTF = (PORTF & 0xF8) | 0x02; // Limpiar PF0, PF1 y PF2, establecer PF1
                    break;

                case 2: // Disconnected
                    PORTC &= 0x1F; // Limpieza de PC7, PC6, PC5 antes de configurar
                    PORTC |= 0x40; // Establecer PC6
                    PORTF &= 0xF8; // Limpiar PF0, PF1 y PF2 (ningún LED activo)
                    break;

                case 3: // Short to Battery
                    PORTC &= 0x1F; // Limpieza de PC7, PC6, PC5 antes de configurar
                    PORTC |= 0x60; // Establecer PC7 y PC6
                    PORTF = (PORTF & 0xF8) | 0x04; // Limpiar PF0 y PF1, establecer PF2
                    break;

                case 4: // Short to Gnd
                    PORTC &= 0x1F; // Limpieza de PC7, PC6, PC5 antes de configurar
                    PORTC |= 0x20; // Establecer PC5
                    PORTF = (PORTF & 0xF8) | 0x01; // Limpiar PF1 y PF2, establecer PF0
                    break;
            }
            break;
    }

}


// Función del menú principal
void displayMenu() {
    int channel = 0, state = 0;
    String input;

    // Función para limpiar el buffer serial
    auto cleanBuffer = []() {
        while (Serial.available() > 0) {
            Serial.read();
        }
    };

    // Seleccionar canal
    while (true) {
        Serial.println("\nSelecciona el canal:");
        Serial.println("[1] CH1");
        Serial.println("[2] CH2");
        Serial.println("[3] CH3");
        Serial.println("[4] CH4");

        cleanBuffer(); // Limpiar buffer antes de leer entrada

        while (Serial.available() == 0) {} // Esperar entrada
        input = Serial.readStringUntil('\n'); // Leer entrada hasta el salto de línea

        if (input.toInt() >= 1 && input.toInt() <= 4) {
            channel = input.toInt();
            break;
        } else {
            Serial.println("Canal inválido. Intenta de nuevo.");
        }
    }

    // Seleccionar estado
    while (true) {
        Serial.println("\nSelecciona el estado:");
        Serial.println("[1] Connected");
        Serial.println("[2] Disconnected");
        Serial.println("[3] Short to Battery");
        Serial.println("[4] Short to Gnd");

        cleanBuffer(); // Limpiar buffer antes de leer entrada

        while (Serial.available() == 0) {} // Esperar entrada
        input = Serial.readStringUntil('\n'); // Leer entrada hasta el salto de línea

        if (input.toInt() >= 1 && input.toInt() <= 4) {
            state = input.toInt();
            configureRelay(channel, state);
            return; // Salimos de la función
        } else {
            Serial.println("Estado inválido. Intenta de nuevo.");
        }
    }
}
