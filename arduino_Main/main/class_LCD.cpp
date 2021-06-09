#include <Arduino.h>
#include <Wire.h>  // inclure la bibliothèque permettant la communication par le protocole I2C
#include "rgb_lcd.h" // inclure la bibliothèque pour l'écran LCD
#include "class_LCD.h" 

rgb_lcd lcd; // création d'un objet lcd


int LCD::displaySpot(int SpotNb)
{
  lcd.begin(16, 2);   // configurer le nombre de colonnes et de lignes de l'écran LCD :
 
  // Ecrire un message sur l'écran LCD
  lcd.clear();   // effacer l'écran
  lcd.setCursor(4, 1); // mettre le curseur à la cinquième colonne, deuxième ligne
  lcd.print("Spot n.");
  lcd.print(SpotNb);// afficher le numéro du spot
}

int LCD::displayParameters(int channel, int PotaNb)
  {

      lcd.setCursor(1, 0);
      lcd.print("                ");
      switch (channel)
      { 
        case 1 :
          return(3);
          switch(PotaNb)
          {
            
            case 1 :
              Serial.print("valY : ");
              Serial.println(PotaNb); 
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": HUE");
              break;
              
            case 2 :
              Serial.print("valY : ");
              Serial.println(PotaNb); 
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": SATURATION");
              break;
            
            case 3 :
              Serial.print("valY : ");
              Serial.println(PotaNb); 
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": INT");
              break;
          }
          break;
              
        case 2 :
          return(4);
          switch(PotaNb) 
          {
            
            case 1 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": RED");
              break;
              
            case 2 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": GREEN");
              break;
            
            case 3 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": BLUE");
              break;

           case 4 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": WHITE");
              break;
          }
          break;

        case 3 :
          return(4);
          switch(PotaNb) 
          {
            
            case 1 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": HUE");
              break;
              
            case 2 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": SAT");
              break;
            
            case 3 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": INT");
              break;

           case 4 :
              lcd.setCursor(1, 0);
              lcd.print(PotaNb);
              lcd.print(": DIMMER");
              break;
          }
          break;
        }
      }
  
