/*
  by Angel Habid Navarro 12/09/2024 BOB_V0.1
*/

#include "Relay_ctrl.h"

// Función para configurar los relays y LEDs según el canal y el estado seleccionado
void configureRelay(uint8_t channel, uint8_t state) {
    // Inicializamos los puertos a un estado seguro
    PORTJ = 0x00;
    PORTA = 0x00;
    PORTK = 0x00;
    PORTF = 0x00;
    PORTC = 0x00;

    // Configuraciones específicas según canal y estado
    switch (channel) {
        case 1: // Canal CH1
            switch (state) {
                case 1: // Connected
                    PORTJ = 0x00;
                    PORTA = 0x00;
                    PORTK = 0x40; // LED PK6
                    break;

                case 2: // Disconnected
                    PORTJ = 0x00;
                    PORTA = 0x04; // DCRM_2
                    PORTK = 0x00;
                    break;

                case 3: // Short to Battery
                    PORTJ = 0x80; // DCRM_1
                    PORTA = 0x04; // DCRM_2
                    PORTK = 0x80; // LED PK7
                    break;

                case 4: // Short to Gnd
                    PORTJ = 0x00;
                    PORTA = 0x0C; // DCRM_2 y DCRM_3
                    PORTK = 0x20; // LED PK5
                    break;

                default:
                    // Estado inválido
                    break;
            }
            break;

        case 2: // Canal CH2
            switch (state) {
                case 1: // Connected
                    PORTJ = 0x00;
                    PORTC = 0x02; // LED PK3
                    break;

                case 2: // Disconnected
                    PORTJ = 0x02;
                    PORTC = 0x00;
                    break;

                case 3: // Short to Battery
                    PORTJ = 0x81;
                    PORTC = 0x04; // LED PK4
                    break;

                case 4: // Short to Gnd
                    PORTJ = 0x03;
                    PORTC = 0x01; // LED PK2
                    break;

                default:
                    // Estado inválido
                    break;
            }
            break;

        case 3: // Canal CH3
            switch (state) {
                case 1: // Connected
                    PORTA = 0x00;
                    PORTF = 0x08; // LED PF4
                    break;

                case 2: // Disconnected
                    PORTA = 0x04; // DCRM_8
                    PORTF = 0x00;
                    break;

                case 3: // Short to Battery
                    PORTA = 0x05;
                    PORTF = 0x20; // LED PF5
                    break;

                case 4: // Short to Gnd
                    PORTA = 0x06;
                    PORTF = 0x10; // LED PF3
                    break;

                default:
                    // Estado inválido
                    break;
            }
            break;

        case 4: // Canal CH4
            switch (state) {
                case 1: // Connected
                    PORTC = 0x00;
                    PORTF = 0x02; // LED PF1
                    break;

                case 2: // Disconnected
                    PORTC = 0x10; // DCRM_11
                    PORTF = 0x00;
                    break;

                case 3: // Short to Battery
                    PORTC = 0x11;
                    PORTF = 0x04; // LED PF2
                    break;

                case 4: // Short to Gnd
                    PORTC = 0x12;
                    PORTF = 0x01; // LED PF0
                    break;

                default:
                    // Estado inválido
                    break;
            }
            break;

        default:
            // Canal inválido
            break;
    }
}

void displayMenu() {
    uint8_t channel, state;

    while (1) {
        printf("Selecciona el canal (1-4):\n");
        scanf("%hhu", &channel);

        printf("Selecciona el estado:\n");
        printf("[1] Connected\n");
        printf("[2] Disconnected\n");
        printf("[3] Short to Battery\n");
        printf("[4] Short to Gnd\n");
        scanf("%hhu", &state);

        if (channel >= 1 && channel <= 4 && state >= 1 && state <= 4) {
            configureRelay(channel, state);
        } else {
            printf("Opción inválida.\n");
        }
    }
}
