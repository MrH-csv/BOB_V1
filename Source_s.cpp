#include "Arduino.h"
#include "Source_s.h"

int Surcsel(void)
{
  int opt;
  String dumy_s1;
    opt = 0;

    Serial.println("\nSelecciona entre VBat o una fuente de alimentacion externa:\n");
    Serial.println("[1] Usar Voltaje de la bateria (se debe contar con un voltaje\n");
    Serial.println("de al menos 12V DC ... Revise el manual\n");
    Serial.println("[2] Voltaje de una fuente externa.\n");

    while (1)
    {
        dumy_s1 = String(Serial.read(),HEX);
     
        if (Serial.available() != 0 && dumy_s1 != 0xa)
        {
            opt = Serial.parseInt(); 
            Serial.println(opt);

            switch (opt)
            {
            case 1:
                PORTL &= !0x10;//PL4 = Low.
                return 0;
                break;

            case 2:
                PORTL |= 0x10;//PL4 = High.
                return 0;
                break;
            
            default:
                Serial.println("Error opcion invalida..");
                break;
            }
        
        
        }
    }
}
