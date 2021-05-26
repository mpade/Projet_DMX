#include "class_pota.h"
#include "class_joystick.h"
#include "class_trame.h"

pota value1;
pota value2;
pota value3;
pota value4;
joystick X;
joystick Y;
joystick Button;
trame trame;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  //déclaration des fonctions
  value1.getPotaValue1();
  value2.getPotaValue2();
  value3.getPotaValue3();
  value4.getPotaValue4();
  X.getXValue();
  Y.getYValue();
  Button.getBValue();
  trame.potaConversion(value1.getPotaValue1());
  
}
