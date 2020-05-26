#include "core_simulation.h"
#include "mydevices.h"
#include "internal.h"


int main(){
  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs
  

 // I2CActuatorScreen screen;
  Direction Bout_D(DELAY);
  Pressoir Bout_P(DELAY);
  Tilt Bout_T(DELAY);
  I2CActuatorScreen screen;
  
  
  // branchement des capteurs actionneurs7
  esp8266.pin(0,Bout_D);
  esp8266.pin(1,Bout_P);
  esp8266.pin(2,Bout_T);
  esp8266.i2c(1,screen);
  // allumage de la carte
  esp8266.run();


 
  return 0;
}


