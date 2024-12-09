/*
  by Angel Habid Navarro 09/27/2024 V0.3
*/
#include "Arduino.h"
#include "Debugger_s.h"

int Debugger(void)
{
    int opt;
    String dumy_s1;
    opt = 0;

    Serial.println("\nSelecciona el puerto de salida de la señal del Debugger:\n");
    Serial.println("[1] CH1 como salida.\n");
    Serial.println("[2] CH2 como salida.\n");
    Serial.println("[3] Desconectar Debugger.\n");

    while (1)
    {
        dumy_s1 = String(Serial.read(),HEX);
     
        if (Serial.available() != 0 && dumy_s1 != 0xa)
        {
            opt = Serial.parseInt(); 
            Serial.println(opt);

            switch (opt)
            {
            case 1:             // PL1 DBG EN 1.
                PORTL |= 0x02;//PL1 = high.
                PORTL &= !0x01;//PL0 = low.
                return 0;
                break;

            case 2:             // PL0 DBG EN 2.
                PORTL |= 0x01;//PL0 = high.
                PORTL &= !0x02;//PL1 = low.
                return 0;
                break;

            case 3:             // Off the DBG CH.
                PORTL &= !0x03;//PL0 & PL1 = low.
                return 0;
                break;
            
            default:
                Serial.println("Error opcion invalida..");
                break;
            }
        
        
        }
    }
}
