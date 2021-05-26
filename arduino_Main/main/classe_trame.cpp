#include <Arduino.h>
#include "class_trame.h"

int trame::potaConversion(float valPota)
{
  //on converti la valeur de Pota en numérique
  int convPota = map(valPota, 0, 1023, 0, 255);
  Serial.print("la valeur est : ");
  Serial.println(convPota);
  delay(100);
}

char trame::ecritureTrame()
{
  
}
