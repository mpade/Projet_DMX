#include <Arduino.h>
#include "class_trame.h"
#include "class_pota.h"

pota value;

int trame::ecritureTrame(int numSpot)
{
  //récupération et écriture du Spot
  Serial.print(numSpot);
  Serial.print("::");

  //écriture des valeurs des pota
  for (int i=1; i<=9; i++)
  { 
    Serial.print(value.getPotaValue(i));
    Serial.print(":");
  }

  Serial.println(" ");
}
