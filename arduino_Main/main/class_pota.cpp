#include <Arduino.h>
#include "class_pota.h"

float pota::getPotaValue(int input, int num)
{
    pinMode (input, INPUT); //définition de input comme une entrée
   
   //lecture des valeurs du potentiometre
   int PotaValue = analogRead(input);
   PotaValue = map(PotaValue, 0, 1023, 0, 255);
   return PotaValue;
}
