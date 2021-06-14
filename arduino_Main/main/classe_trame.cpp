#include <Arduino.h>
#include "class_trame.h"
#include "class_pota.h"

pota value;

int trame::ecritureTrame(int nbPota, int adr)
{

  //écriture des valeurs des pota
  for (int i=1; i<=nbPota; i++)
  {
    Serial.print(adr+(i-1));
    Serial.print(":"); 
    Serial.println(value.getPotaValue(i));
    
  }
  Serial.println("");
}
