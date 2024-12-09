#include "Arduino.h"
#include "PWM_V1.h"

void setupPWM(uint8_t pin, uint16_t frequency, uint8_t dutyCycle) {
    // Configuración del PWM usando registros
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
    uint8_t opt;
    uint8_t dutyCycle;
    uint16_t frequency;

    Serial.println("Selecciona el canal de PWM que quieres configurar:\n");
    Serial.println("[1] PWM CH1.");
    Serial.println("[2] PWM CH2.");

    while (Serial.available() == 0) {}
    opt = Serial.parseInt();
    Serial.println(opt);

    Serial.println("Establece la frecuencia (en Hz):");
    while (Serial.available() == 0) {}
    frequency = Serial.parseInt();
    Serial.println(frequency);

    Serial.println("Establece el ciclo de trabajo (0-100%):");
    while (Serial.available() == 0) {}
    dutyCycle = Serial.parseInt();
    Serial.println(dutyCycle);

    if (dutyCycle > 100) dutyCycle = 100;

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
