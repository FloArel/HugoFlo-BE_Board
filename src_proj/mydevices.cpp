
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
      }
      else
      {
        state=LOW;
      }

      *ptrmem=state;
    }
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
      }
      else if (ifstream("down.txt")){
        state=DOWN;
      }
      else if (ifstream("left.txt")){
        state=LEFT;
      }
      else if (ifstream("right.txt")){
        state=RIGHT;
      }  
      else {
        state=NOTHING;
      }
      *ptrmem=state;
    }
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
      }
      else
      {
        state=LOW;
      }

      *ptrmem=state;
    }
  }
  cout<<state;
};

void test_classe_mydevices(){
  Direction Bout_D(DELAY);
  Pressoir Bout_P(DELAY);
  Tilt Bout_T(DELAY);
  cout<<"boutons créés"<<endl;
  while(1){
    Bout_D.run();
    Bout_P.run();
    Bout_T.run();
  };
};


