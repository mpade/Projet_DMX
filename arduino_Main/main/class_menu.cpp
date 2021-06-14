#include <Arduino.h>
#include "class_menu.h"
#include "class_joystick.h"
#include "class_trame.h"
#include "class_pota.h"
#include "class_LCD.h"
#include "spotData.h"


int menu::MenuSpots()
{

  joystick Y;
  joystick X;
  joystick Button;
  trame trame;
  LCD displayValue;
  spotData data;
  int valY = Y.getYValue();
  int valX = X.getXValue();
  int valB = Button.getBValue();
  int choixSpot = 1;
  int choixPota = 1;

  int nbSpots = data.GetNb();
  String SpotAdr[nbSpots];   
  for (int i = 0; i < nbSpots; i++)
  {
    String result = data.GetData(1);
    if(result.length() > 0)
    {
      SpotAdr[i] = result;
      //displayValue.displayAdr(SpotAdr[i]);
    }
    else
    {
      i--;
    }
  }



  displayValue.displaySpot(choixSpot);
  //displayValue.displayAdr(SpotAdr[choixSpot-1]); 
    while (valB == 1)
    {

      //cette partie du code est pour le choix du spot, en utilisant la valeur Y du joystick
      
      valY = Y.getYValue();
      valX = X.getXValue();
      valB = Button.getBValue();
    
        if (valB == 0)
          {
            trame.ecritureTrame(data.GetNbPota(SpotAdr[choixSpot-1]), data.GetAdrTrame(SpotAdr[choixSpot-1]));
            delay(1000);
            valB = Button.getBValue();
          }
      
      //monter la valeur du choix
       if(valY == 0)
        {
            //revenir au premier choix si celui ci dépasse le nombre de spots enregistré
            if (choixSpot < 2)
              {
                choixSpot = nbSpots + 1;
              }
            choixSpot--;
            displayValue.displaySpot(choixSpot);
            displayValue.displayAdr(SpotAdr[choixSpot-1]);
        }

       //descendre la valeur du choix
       if(valY == 5)
        {
            //revenir au premier choix si celui ci dépasse le nombre de spots enregistré
            if (choixSpot > nbSpots-1)
              {
                choixSpot = 0;
              }
            choixSpot++;
            displayValue.displaySpot(choixSpot);
            displayValue.displayAdr(SpotAdr[choixSpot-1]);
            
            
        }
      delay(200);
    }   
}
