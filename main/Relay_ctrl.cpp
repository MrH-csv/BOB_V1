#include "Relay_ctrl.h"

int Relay_dcomm_sel(void)
{
  int opt;
  String dumy_s1;
    opt = 0;

    Serial.println("\nSelecciona El numero de canal que deseas modificar:\n");
    Serial.println("[1] Canal con funcionalidad completa y DGB independiente.\n");
    Serial.println("[2] Canal con funcionalidad completa y DGB independiente.\n");
    Serial.println("[3] Canal con funcionalidad completa y DGB independiente.\n");
    Serial.println("[4] Canal con funcionalidad completa y DGB independiente.\n");
    Serial.println("[5] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[6] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[7] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[8] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[9] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[10] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[11] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[12] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[13] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[14] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[15] Canal con funcionalidad reducida y DGB comun.\n");
    Serial.println("[16] Canal con funcionalidad reducida y DGB comun.\n");
    

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
