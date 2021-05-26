#include <Arduino.h>
#include "class_pota.h"

float pota::getPotaValue1()
{
    int input1 = A1; //signal du Potentiometre sur l'entrée 1
    pinMode (input1, INPUT); //définition de A1 comme une entrée
   
   //lecture des valeurs du potentiometre
    PotaValue1 = analogRead(input1);
  return PotaValue1;
}

float pota::getPotaValue2()
{
   int input2 = A2; //signal du Potentiometre sur l'entrée 2
   pinMode (input2, INPUT); //définition de A2 comme une entrée

   //lecture des valeur du potentiometre
   PotaValue2 = analogRead(input2);
   
   return PotaValue2;  
}

float pota::getPotaValue3()
{
   int input3 = A3; //signal du Potentiometre sur l'entrée 3
   pinMode (input3, INPUT); //définition de A3 comme une entrée

   //lecture des valeurs du potentiometre
   PotaValue3 = analogRead(input3);

   return PotaValue2;
}

float pota::getPotaValue4()
{
   int input4 = A4; //signal du Potentiometre sur l'entrée 4
   pinMode (input4, INPUT); //définition de A4 comme une entrée

   //lecture des valeurs du potentiometre
   PotaValue4 = analogRead(input4);
}
