#include "class_pota.h"
#include "class_joystick.h"
#include "class_trame.h"
#include "class_menu.h"

menu menu;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //déclaration des fonctions
  menu.MenuSpots(12);
}
