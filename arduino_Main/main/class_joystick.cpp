 #include <Arduino.h>
 #include "class_joystick.h"
 float joystick::getYValue()
  {
    
    int axeY = A11; // signal de l'axe Y sur entrée A11
    pinMode (axeY, INPUT); // définition de A11 comme une entrée    
    //lecture de la valeur Y du joystick
    int valueY = analogRead (axeY) * (5.0 / 1023.0);

    return valueY;
  }

  float joystick::getXValue()
  {
    int axeX = A10; // signal de l'axe X sur entrée A10
    pinMode (axeX, INPUT); // définition de A10 comme une entrée
    //lecture de la valeur X du joystick
    int valueX = analogRead (axeX) * (5.0 / 1023.0);
  
    return valueX;
  }

  float joystick::getBValue()
  {
    int Button = 12; //signal du bouton sur l'entrée 12
    pinMode (Button, INPUT_PULLUP); //définition de 12 comme une entrée de pression
    int valueB = digitalRead(Button);

    return valueB;
  }
