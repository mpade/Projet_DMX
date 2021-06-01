 #include <Arduino.h>
#include "class_menu.h"
#include "class_joystick.h"
#include "class_trame.h"

int menu::Menu(int nbSpots)
{

  joystick Y;
  joystick Button;
  trame trame;
  int valY = Y.getYValue();        
  int valB = Button.getBValue(); 
  int choixSpot = 1;
  Serial.print("sélectionner le spot ");
  Serial.println(choixSpot);
  
    while (valB == 1)
    {
      valY = Y.getYValue();        
      valB = Button.getBValue(); 
        if (valB == 0)
          {   
            trame.ecritureTrame(choixSpot);
            delay(500);
          }
      
      //monter la valeur du choix
       if(valY == 0)
        {
            //revenir au premier choix si celui ci dépasse le nombre de spots enregistré
            if (choixSpot < 2)
              {
                choixSpot = 13;
              }
            choixSpot--;
            Serial.print("sélectionner le spot ");
            Serial.println(choixSpot);
        }

       //descendre la valeur du choix
       if(valY == 5)
        {
            //revenir au premier choix si celui ci dépasse le nombre de spots enregistré
            if (choixSpot > 11)
              {
                choixSpot = 0;
              }
            choixSpot++;
            Serial.print("sélectionner le spot ");
            Serial.println(choixSpot);
        }
      delay(200);
    } 
}
