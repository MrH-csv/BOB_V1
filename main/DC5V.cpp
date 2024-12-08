/*
    Ajuste y control de 2 pines de PWM para el ATmega2560 programado con arduino.
    by Angel Habid Navarro 09/27/2024 V0.1
*/
#include "Arduino.h"
#include "DC5V.h"

// Fuctionality
int VDC5(void)
{
    int opt;
    float x;
    int y;
    int duty_c;
    float vdc_calc;
    String dumy_s;

    opt = 0;
    duty_c = 0;
    x=0.0;
    vdc_calc=0.0;

    Serial.flush();
    Serial.println("Ingresa el valor de voltaje que deseas (Entre 0V y 5V): \n\n");

    while (1)
    {
        dumy_s = String(Serial.read(),HEX);
        
        if (Serial.available() != 0 && dumy_s != 0xa)
        {
            opt = Serial.parseInt();
            Serial.println(opt);
            x = opt;
            vdc_calc = (5 * x ) / 255;
            duty_c = int(vdc_calc);

            if(duty_c > 255)
            {
                duty_c = 255;  
            }

            y = (int)x;

            analogWrite(DC_5V,duty_c);
            Serial.println("El voltaje se ajusto a:");
            Serial.print(y);
            Serial.print("\n");
            return 0;
        }
    }  

    

}
