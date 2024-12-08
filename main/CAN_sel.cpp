#include "Arduino.h"
#include "CAN_sel.h"

int CAN_bus_s(void)
{
    int opt;
  String dumy_s1;
    opt = 0;

    Serial.println("\nSelecciona entre el los dos puertos de salida del bus de CAN:\n");
    Serial.println("\n(Para abrir un cnaal de CAN unicamente cambia al cnal contrario).\n\n");
    Serial.println("[1] Usar CAN CH1 como salida. \n"); 
    Serial.println("[2] Usar CAN CH2 como salida. \n"); 

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
                PORTG &= !0x18;//PG4 and PG3 = Low.
                return 0;
                break;

            case 2:
                PORTG |= 0x18;//PG4 and PG3 = High.
                return 0;
                break;
            
            default:
                Serial.println("Error opcion invalida..");
                break;
            }
        
        
        }
    }
}
