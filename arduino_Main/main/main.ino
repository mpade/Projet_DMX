#include "class_pota.h"
#include "class_joystick.h"
#include "class_trame.h"

pota value;
joystick X;
joystick Y;
joystick Button;
trame trame;

float table[10];
int input_table[10];


void setup() {
  // put your setup code here, to run once:
  input_table[1] = A1;
  input_table[2] = A2;
  input_table[3] = A3;
  input_table[4] = A4;
  input_table[5] = A5;
  input_table[6] = A6;
  input_table[7] = A7;
  input_table[8] = A8;
  input_table[9] = A9;
  Serial.begin(9600);
}

void loop() {
  //déclaration des fonctions
  for (int place =1; place<10; place++)
  {
    table[place] = value.getPotaValue(input_table[place], place);
  } 
  X.getXValue();
  Y.getYValue();        
  Button.getBValue();

  Serial.print("la trame est : ");
  for (int place =1; place<10; place++)
  {  
    trame.ecritureTrame(table[place]);
  }
  Serial.println(" ");
  
}
