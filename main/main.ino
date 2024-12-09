/*Programa principal , Software de control del proyecto BoB_V1...
  By: Angel Habid Navarro 27/09/2024 V0.1
*/

#include "Arduino.h"
#include "Menu.h"
#include "GPIO_config.h"

//Prototypes

//Global

void setup()
{
  Serial.begin(115200);
  //Configuracion de GPIOS para control de relays.
  GPIO_init();
}

void loop()
{
    s_case_1(menu_1()); 
}
