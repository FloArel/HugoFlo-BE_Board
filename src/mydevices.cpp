
#include "mydevices.h"

using namespace std;

int luminosite_environnement=200;


//classe sensor lumino
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),temps(d){
  
}

void AnalogSensorLuminosity::run(){
  while(1){
    lumin=luminosite_environnement;
    if(ptrmem!=NULL)
      *ptrmem=lumin;
    sleep(temps);
  }
}

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int  t):Device(),val(t),temps(d){
  alea=1;
}

void AnalogSensorTemperature::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val+alea;
    sleep(temps);
  }
}

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((eteint1))))\n";
    else
      cout << "((((allume1))))\n";
    sleep(temps);
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



