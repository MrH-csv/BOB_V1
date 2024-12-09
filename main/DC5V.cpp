/*
    Ajuste y control de 2 pines de PWM para el ATmega2560.
    by Angel Habid Navarro 09/27/2024 V0.2
*/

#include "DC5V.h"

void setDCVoltage(float voltage) {
    if (voltage < 0) voltage = 0;      // Aseguramos un mínimo de 0V
    if (voltage > 5) voltage = 5;      // Aseguramos un máximo de 5V

    // Calculamos el duty cycle en términos de un rango de 0 a 255
    uint8_t dutyCycle = (uint8_t)((voltage / 5.0) * 255.0);

    // Configuración de PWM en el pin DC_5V usando registros
    DDRB |= (1 << PB5);               // Configuramos el pin como salida (PB5 -> OC1A -> PE5 en Arduino)
    TCCR1A = (1 << COM1A1) | (1 << WGM11);  // Modo Fast PWM, 10 bits
    TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS11); // Prescaler de 8
    ICR1 = 0x03FF;                    // TOP en 10 bits (1023)
    OCR1A = (dutyCycle * ICR1) / 255; // Configuramos el duty cycle
}


float readVoltageInput() {
    String input = "";
    char receivedChar;
    float voltage = -1.0;

    while (true) {
        if (Serial.available() > 0) {
            receivedChar = Serial.read();
            // Ignoramos caracteres de nueva línea o retorno de carro
            if (receivedChar != '\n' && receivedChar != '\r') {
                input += receivedChar;
            } else if (input.length() > 0) {
                // Intentamos convertir la entrada a un valor flotante
                voltage = input.toFloat();
                break;
            }
        }
    }
    return voltage;
}

void VDC5Menu() {
    float voltage = 0.0;

    Serial.println("Ingresa el valor de voltaje que deseas (Entre 0V y 5V):");

    while (true) {
        voltage = readVoltageInput(); // Lee la entrada con validación
        if (voltage >= 0.0 && voltage <= 5.0) {
            setDCVoltage(voltage);
            Serial.print("El voltaje se ajustó a: ");
            Serial.println(voltage, 2); // Mostramos el voltaje con 2 decimales
            break;
        } else {
            Serial.println("Valor inválido. Ingresa un valor entre 0V y 5V.");
        }
    }
}
