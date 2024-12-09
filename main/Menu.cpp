/*
  Menu via UART para el ATmega2560 programado con arduino.
  by Angel Habid Navarro 09/27/2024 V0.1
*/
#include "Arduino.h"
#include "Menu.h"


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
