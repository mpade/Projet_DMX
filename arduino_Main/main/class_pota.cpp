#include <Arduino.h>
#include "class_pota.h"


int pota::getPotaValue(int i)
{
    int input_table[9];
    int PotaValue[9];
    input_table[1] = A1;
    input_table[2] = A2;
    input_table[3] = A3;
    input_table[4] = A4;
    input_table[5] = A5;
    input_table[6] = A6;
    input_table[7] = A7;
    input_table[8] = A8;
    input_table[9] = A9;

    pinMode (input_table[i], INPUT); //définition de input comme une entrée

   //lecture des valeurs du potentiometre
   PotaValue[i] = analogRead(input_table[i]);
   PotaValue[i] = map(PotaValue[i], 0, 1023, 0, 255);
   return PotaValue[i];
}
