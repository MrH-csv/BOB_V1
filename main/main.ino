/*Programa principal , Software de control del proyecto BoB_V1...
  By: Angel Habid Navarro 27/09/2024 V0.1
*/

#include "Arduino.h"
#include "Menu.h"
#include "GPIO_config.h"
#include "PWM_V1.h"
#include "Source_s.h"
#include "CAN_sel.h"
#include "Debugger_s.h"
#include "DC5V.h"
#include "GPIO_config.h"
#include "Relay_ctrl.h"
#include "Utils.h"
//Prototypes
void s_case_1 (int);
//Global
extern int loop_ctl;

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


void s_case_1 (int opt)
{
  switch (opt)
  {
    /*
    case 1:
      Serial.println("\nMenu de seleccion de fuentes: \n\n");
      Surcsel();
      break;
      */

    case 1:
      Serial.println("\nMenu de seleccion para las salidas de CAN: \n\n");
      CAN_bus_s();
      break;

    case 2:
      Serial.println("\nMenu de configuracion de canales PWM: \n\n");
      PWM_1();// pendiente agregar el que se pueda cambiar la frecuencia del PWM.
      break;

    case 3:
      Serial.println("\nFuncion seleccion 5V DC VARIABLE... Activada \n\n");
      VDC5Menu(); // Menú para ajustar el voltaje
      break;

    case 4:
      Serial.println("\nMenu de seleccion de puerto de salida del Debugger:\n\n");
      Debugger();
      break;

    case 5:
      displayMenu(); // Llama al menú del archivo Relay_ctrl.cpp
      Serial.println("\nFuncion seleccion de Canales de potencia... Activada \n\n");
      break;

    default:
      Serial.println("\nError, el valor ingresado no corresponde a una funcion existente, intenta de nuevo\n\n");
      break;
  }   
}
