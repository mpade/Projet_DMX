#include <Arduino.h>
#include <Wire.h>  // inclure la bibliothèque permettant la communication par le protocole I2C
#include "rgb_lcd.h" // inclure la bibliothèque pour l'écran LCD
#include "class_LCD.h" 

rgb_lcd lcd; // création d'un objet lcd

int LCD::displaySpotvalue(int value)
{

  lcd.setCursor(2, 0); // mettre le curseur à la cinquième colonne, deuxième ligne
  lcd.print("adr:");
  lcd.print(value);// afficher le numéro du spot
  
}

int LCD::displaySpot(int SpotNb)
{
  lcd.begin(16, 2);   // configurer le nombre de colonnes et de lignes de l'écran LCD :
 
  // Ecrire un message sur l'écran LCD
  lcd.clear();   // effacer l'écran
  lcd.setCursor(4, 1); // mettre le curseur à la cinquième colonne, deuxième ligne
  lcd.print("Spot n.");
  lcd.print(SpotNb);// afficher le numéro du spot
}

int LCD::displayAdr(String value)
{
  lcd.setCursor(0, 0); // mettre le curseur à la troisième colonne, première ligne
  lcd.print("adr:");
  lcd.print(value);// afficher le numéro du spot
}
