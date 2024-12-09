/*
  Control de un GPIO en proyecto BOB_V1
  usando el ATmega2560.
  by Angel Habid Navarro 09/28/2024 V0.1
*/
#include "Arduino.h"
#include "GPIO_config.h"

void GPIO_init (void)
{
    //Configuracion de GPIOS para control de relays.
    DDRA |= 0xFF;//Port A as output.
    DDRB |= 0x40;//Port B as output (Port B only PB6 is used).
    DDRC |= 0xFF;//Port C as output.
    DDRD |= 0xFF;//Port D as output.
    DDRE |= 0x3B;//Port E as output(PE2, PE6 and PE7 are not used)
    DDRF |= 0xFF;//Port F as output.
    DDRG |= 0x1F;//Port G as output (Port G only available PG0 to PG5 (PG5 no used)).
    DDRH |= 0xFF;//Port H as output.
    DDRJ |= 0xFF;//Port J as output.
    DDRK |= 0xFF;//Port K as output.
    DDRL |= 0xFF;//Port L as output.
}
