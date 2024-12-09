/*
  Menu via UART para el ATmega2560 programado con arduino.
  by Angel Habid Navarro 09/27/2024 V0.1
*/
#include "Arduino.h"
#include "Menu.h"
#include "PWM_V1.h"
#include "Source_s.h"
#include "CAN_sel.h"
#include "Debugger_s.h"
#include "DC5V.h"
#include "GPIO_config.h"
#include "Relay_ctrl.h"

int menu_1(void)
{
  //Local
  int menu_ret_1;
  String dumy_s;
  int once;
  int menu_opt;
  int loop_ctl;

  //init
  menu_opt = 0;
  loop_ctl = 1;
 
//Loop sub-menu
  while (1)
  {
    if (loop_ctl == 1)
    {
      delay(500);
      Serial.flush();
      Serial.println();//escape
      Serial.println("Bienvenido al menu UART e BoB, porfavor selecciona una se las siguientes opciones tecleando el numero correspondiente...\n\n");
      //Serial.println("[1] Menu de seleccion de fuentes.\n");
      Serial.println("[1] Menu de canales CAN.\n");  
      Serial.println("[2] Menu para configurar canales de PWM.\n");
      Serial.println("[3] Menu para control de la salida DC vriable de 5V.\n");
      Serial.println("[4] Seleccionar puerto de salida para Debbugger.\n");
      Serial.println("[5] Menu de configuacion de canales (Switches).\n");
      loop_ctl = 0;
    }

    dumy_s = String(Serial.read(),HEX);
     
    if (Serial.available() != 0 && dumy_s != 0xa)
    {
      
      menu_opt = Serial.parseInt(); 
      Serial.println(menu_opt);
      
      if(menu_opt != 0)
      {
        loop_ctl = 1;
        return menu_opt; 
      }
    }
  }
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
      Serial.println("\nFuncion seleccion de Canales de potencia... Activada \n\n");
      displayMenu(); // Llama al menú del archivo Relay_ctrl.cpp
      break;

    default:
      Serial.println("\nError, el valor ingresado no corresponde a una funcion existente, intenta de nuevo\n\n");
      break;
  }   
}
