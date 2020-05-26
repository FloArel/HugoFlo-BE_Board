
#include "mydevices.h"
using namespace std;



Pressoir::Pressoir(int d): state(LOW),temps(d){
}


void Pressoir::run(){
 while (1)
  {
    if(ptrmem!=NULL){
      

      if(ifstream("on.txt")){
        state=HIGH;
        cout<<"pressoir état haut"<<endl;
      }
      else
      {
        state=LOW;
      }

      *ptrmem=state;
    }
    sleep(temps);
  }
  cout<<state;
  
};

//classe DigitalActuatorLED
Direction::Direction(int t):state(),temps(t){
};
void Direction::run(){
  while(1){
    if(ptrmem!=NULL){
      if(ifstream("up.txt")){
        state=UP;
        cout<<"direction up"<<endl;
      }
      else if (ifstream("down.txt")){
        state=DOWN;
        cout<<"direction down"<<endl;

      }
      else if (ifstream("left.txt")){
        state=LEFT;
       cout<<"direction left"<<endl;

      }
      else if (ifstream("right.txt")){
        state=RIGHT;
       cout<<"direction right"<<endl;

      }  
      else {
        state=NOTHING;
      }
      *ptrmem=state;
    }
    sleep(temps);
  }
  cout<<state;
  
};


Tilt::Tilt(int d):state(LOW),temps(d){}

void Tilt::run(){
 while (1)
  {
    if(ptrmem!=NULL){
      

      if(ifstream("agiter.txt")){
        state=HIGH;
        cout<<"tilt agité"<<endl;
        

      }
      else
      {
        state=LOW;
      }

      *ptrmem=state;
    }
    sleep(DELAY);
  }
  cout<<state;
  
};



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

/*void test_classe_mydevices(){
  Direction Bout_D(DELAY);
  Pressoir Bout_P(DELAY);
  Tilt Bout_T(DELAY);
  cout<<"boutons créés"<<endl;
  while(1){
    Bout_D.run();
    Bout_P.run();
    Bout_T.run();
  };*/



