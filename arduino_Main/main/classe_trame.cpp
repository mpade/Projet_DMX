#include <Arduino.h>
#include "class_trame.h"

int trame::ecritureTrame(int potaValue)
{
  Serial.print(potaValue);
  Serial.print(":");
}
