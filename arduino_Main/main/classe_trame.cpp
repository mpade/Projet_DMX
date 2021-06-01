#include <Arduino.h>
#include "class_trame.h"
#include "class_pota.h"

pota value;

int trame::ecritureTrame(int numSpot)
{
  Serial.print(numSpot);
  Serial.print("::");
  for (int i=0; i<=9; i++)
  { 
    Serial.print(value.getPotaValue(i));
    Serial.print(":");
  }

  Serial.println(" ");
}
