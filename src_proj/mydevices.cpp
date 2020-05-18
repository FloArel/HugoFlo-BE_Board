
#include "mydevices.h"

using namespace std;



Pressoir::Pressoir(int d): Button(),state(LOW),temps(d){
}


void Pressoir::run(){
 while (1)
  {
    if(ptrmem!=NULL){
      

      if(ifstream("on.txt")){
        state=HIGH;
      }
      else
      {
        state=LOW;
      }

      *ptrmem=state;
    }
  }
  
}


  
}
//classe DigitalActuatorLED
Direction::Direction(int t):Button(),state(),temps(t){
}
void Direction::run(){
  while(1){
    if(ptr_mem!=NULL){
      switch case:
        
    }
 
  }
}


Tilt::Tilt(int d,int  t):Button(),val(t),temps(d){}

void Tilt::run(){
 while (1)
  {
    if(ptrmem!=NULL){
      

      if(ifstream("on.txt")){
        state=HIGH;
      }
      else
      {
        state=LOW;
      }

      *ptrmem=state;
    }
  }
  
}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}

//led intelligente
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void IntelligentDigitalActuatorLED::run(){
  int lumin_base=luminosite_environnement;
  while(1){

    if(ptrmem!=NULL)
      state=*ptrmem;

    if (state==LOW){
      cout << "((((eteint2))))\n";
      luminosite_environnement=lumin_base;
    }
    else{
      cout << "((((allume2))))\n";
      luminosite_environnement=lumin_base+50;
    }
    sleep(temps);
    }
}


