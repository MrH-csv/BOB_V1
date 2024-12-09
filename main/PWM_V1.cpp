/*
  by Angel Habid Navarro 09/27/2024 V0.3
*/
#include "Arduino.h"
#include "PWM_V1.h"


String readValidInput() {
    String input = "";
    char receivedChar;
    while (true) {
        if (Serial.available() > 0) {
            receivedChar = Serial.read();
            // Ignorar el carácter 0xA
            if (receivedChar != '\n' && receivedChar != '\r') {
                input += receivedChar;
            } else if (input.length() > 0) {
                // Detenerse si hay entrada válida y termina con '\n' o '\r'
                break;
            }
        }
    }
    return input;
}

void setupPWM(uint8_t pin, uint16_t frequency, uint8_t dutyCycle) {
    if (pin == PWM_CH1) {
        pinMode(pin, OUTPUT);
        TCCR3A = (1 << COM3A1) | (1 << WGM31); // PWM, Phase Correct
        TCCR3B = (1 << WGM33) | (1 << CS31);   // Prescaler 8
        ICR3 = (F_CPU / (2 * 8 * frequency)) - 1; // TOP value for desired frequency
        OCR3A = (ICR3 * dutyCycle) / 100;      // Duty cycle
    } else if (pin == PWM_CH2) {
        pinMode(pin, OUTPUT);
        TCCR3A |= (1 << COM3B1);
        OCR3B = (ICR3 * dutyCycle) / 100;
    }
}

int PWM_1(void) {
    uint8_t opt = 0;
    uint8_t dutyCycle = 0;
    uint16_t frequency = 0;

    Serial.println("Menu de configuración de canales PWM:");
    Serial.println("\nSelecciona el canal de PWM que quieres configurar:");
    Serial.println("[1] PWM CH1.");
    Serial.println("[2] PWM CH2.");
    
    while (true) {
        String input = readValidInput();
        opt = input.toInt();
        if (opt == 1 || opt == 2) {
            break;
        } else {
            Serial.println("Error, comando no válido. Intenta nuevamente.");
        }
    }
    Serial.println(opt);

    Serial.println("Establece la frecuencia (en Hz):");
    while (true) {
        String input = readValidInput();
        frequency = input.toInt();
        if (frequency > 0) {
            break;
        } else {
            Serial.println("Error, frecuencia no válida. Intenta nuevamente.");
        }
    }
    Serial.println(frequency);

    Serial.println("Establece el ciclo de trabajo (0-100%):");
    while (true) {
        String input = readValidInput();
        dutyCycle = input.toInt();
        if (dutyCycle >= 0 && dutyCycle <= 100) {
            break;
        } else {
            Serial.println("Error, ciclo de trabajo no válido. Intenta nuevamente.");
        }
    }
    Serial.println(dutyCycle);

    switch (opt) {
        case 1:
            setupPWM(PWM_CH1, frequency, dutyCycle);
            Serial.println("Canal 1 configurado correctamente!");
            break;

        case 2:
            setupPWM(PWM_CH2, frequency, dutyCycle);
            Serial.println("Canal 2 configurado correctamente!");
            break;

        default:
            Serial.println("Error, comando no válido.");
            break;
    }

    return 0;
}
