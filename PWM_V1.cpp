/*
  Ajuste y control de 2 pines de PWM para el ATmega2560 programado con arduino.
  by Angel Habid Navarro 09/27/2024 V0.1
*/
#include "Arduino.h"
#include "PWM_V1.h"

// Fuctionality
int PWM_1(void)
{
  int opt;
  int duty_c;
  String dumy_s;
    
  opt = 0;
  duty_c = 0;

  Serial.flush();
  Serial.println("Selecciona el canal de PWM que quieres utilizar:   \n\n");
  Serial.println("[1] PWM CH1.\n");
  Serial.println("[2] PWM CH2.\n");
  
  while (1)
  {
    dumy_s = String(Serial.read(),HEX);
     
    if (Serial.available() != 0 && dumy_s != 0xa)
    {
      opt = Serial.parseInt();
      Serial.println(opt);
      
      Serial.flush();
      Serial.print("Establece el ciclo de trabajo que necesitas:   \n\n");

      
      while (1)
      {
        dumy_s = String(Serial.read(),HEX);
     
        if (Serial.available() != 0 && dumy_s != 0xa)
        {
          duty_c = Serial.parseInt();
          Serial.println(duty_c);

          if(duty_c > 255)
          {
            duty_c = 255;  
          }

          switch (opt)
          {
            case 1:
              analogWrite(PWM_CH1,duty_c);
              Serial.println("Canal 1 configurado correctamente!");
              return 0;
              break;
      
            case 2:
              analogWrite(PWM_CH2,duty_c);
              Serial.println("Canal 2 configurado correctamente!");
              return 0;
              break;
      
            default:
              Serial.println("Error, comando no valido");
              return 0;
              break;
          } 
        }
      }
    }
  }
}
