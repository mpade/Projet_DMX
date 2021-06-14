#include <Arduino.h>
#include "spotData.h"
#include "class_LCD.h" 


  LCD displayValue;


spotData::spotData()
{
  buffer.setStorage(storage_array, ELEMENT_COUNT_MAX, 0);
}
  
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


String spotData::GetData(int selection)
  {
      //while (!Serial.available()); 
      while (Serial.available()) 
      {  
        char c = (char)Serial.read();
        buffer.push_back(c); 
      }

      int indexEnd = -1;
      for(int i = 0; i < buffer.size(); i++)
      {
        if(buffer[i] == '\n')
        {
          indexEnd = i;
          break;
        }
      }

      if(indexEnd >= 0)
      {
        String result = "";

        for(int i = 0; i < indexEnd; i++)
        {
          result += buffer.front();
          buffer.remove(0);
        }

        buffer.remove(0);

        return result;
      }

      return "";
  }


int spotData::GetNbPota(String adrSpot)
  {

    String NbPota = adrSpot;
    int tiret = NbPota.indexOf('-');
    NbPota = NbPota.charAt(tiret + 1);
    return atoi(NbPota.c_str());
  }

int spotData::GetAdrTrame(String adrSpot)
  {
    String adrTrame = adrSpot;
    int debut = adrTrame.indexOf(':');
    int fin = adrTrame.indexOf('-');
    adrTrame = adrTrame.substring(debut + 1, fin);
    return atoi(adrTrame.c_str());    
  }
