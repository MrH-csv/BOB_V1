/*Programa principal , Software de control del proyecto BoB_V1...
  By: Angel Habid Navarro 27/09/2024 V0.1
*/

#include "Arduino.h"
#include "Menu.h"
#include "PWM_V1.h"
#include "Source_s.h"
#include "CAN_sel.h"
#include "Debugger_s.h"
#include "DC5V.h"
#include "GPIO_config.h"



//Prototypes
void s_case_1 (int);

//Global
int loop_ctl;

void setup()
{
  Serial.begin(115200);
  //Configuracion de GPIOS para control de relays.
  GPIO_init();
  // pinMode(PWM_CH1,OUTPUT);
  // pinMode(PWM_CH2,OUTPUT);
  // pinMode(DC_5V,OUTPUT);

  

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
      VDC5();// pendiente de probar.
      break;

    case 4:
      Serial.println("\nMenu de seleccion de puerto de salida del Debugger:\n\n");
      Debugger();
      break;

    case 5:
      Serial.println("\nFuncion seleccion de Canales de potencia... Activada \n\n");
      Relay_dcomm_sel();
      break;

    default:
      Serial.println("\nError, el valor ingresado no corresponde a una funcion existente, intenta de nuevo\n\n");
      break;
  }   
}