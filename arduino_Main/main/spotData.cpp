#include <Arduino.h>
#include "spotData.h"

int spotData::getData()
  {
    int nbRead = Serial.read();
    int Data[nbRead];

      for (i = 0; i <= nbRead; i++)
        {
          int Data[i] = Serial.read();
          Serial.println(data[i]);
        }
  }
