#include <Arduino.h>
#include "spotData.h"
#include "class_LCD.h" 
  LCD displayValue;
  
int spotData::GetNb()
 {
      while (!Serial.available()); 
      String NbSpots = "";
      while (Serial.available()) 
          {
          NbSpots += (char) Serial.read();
          delay(1);  
          }
      return atoi(NbSpots.c_str());          
 }


byte spotData::GetData()
  {
      while (!Serial.available()); 
      String DataSpots = "";
      byte data[32];
      byte buffer[10];
      int i = 0;
      while (Serial.available()) 
          {  
            DataSpots += (char)Serial.read();
            DataSpots.toCharArray(buffer, 10);
            data[i] = buffer;
            displayValue.displayAdr(buffer);
            return (data[i]);
            i++;
            
          }
          
    
  }
