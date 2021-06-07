#include <Arduino.h>
#include "class_menu.h"
#include "class_joystick.h"
#include "class_trame.h"
#include "class_pota.h"
#include "class_LCD.h"

int menu::MenuSpots(int nbSpots)
{

  joystick Y;
  joystick X;
  joystick Button;
  trame trame;
  LCD displayValue;
  int valY = Y.getYValue();    
  int valX = X.getXValue();   
  int valB = Button.getBValue(); 
  int choixSpot = 1;
  int choixPota = 1;

  

  displayValue.displayParameters(1, choixPota);
  displayValue.displaySpot(choixSpot);
 
 
    
    while (valB == 1)
    {

      /*cette partie du code est pour le choix du spot, en utilisant la valeur Y du joystick*/
      
      valY = Y.getYValue();
      valX = X.getXValue();        
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
            displayValue.displaySpot(choixSpot);
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
            displayValue.displaySpot(choixSpot);
        }


        /*cette partie du code est pour le choix du potentiomètre, en utilisant la valeur X du joystick*/
              //monter la valeur du choix
       if(valX == 0)
        {
          
            //revenir au premier choix si celui ci dépasse le nombre de spots enregistré
            if (choixPota < 2)
              {
                choixPota = 10;
              }
            choixPota--;
            displayValue.displayParameters(1, choixPota);
        }

       //descendre la valeur du choix
       if(valX == 5)
        {
            //revenir au premier choix si celui ci dépasse le nombre de spots enregistré
            if (choixPota > 8)
              {
                choixPota = 0;
              }
            choixPota++;
            displayValue.displayParameters(1, choixPota);
        }
      delay(200);
    } 
}
