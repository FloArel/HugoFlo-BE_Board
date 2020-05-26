#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"
#include <fstream>
//#include "internal.h"

#define NOTHING 0
#define UP 1
#define DOWN 2
#define LEFT 3 
#define RIGHT 4


// exemple de capteur analogique de temperature, ne pas oublier d'heriter de Device
class Button: public Device {
private:
  // fait osciller la valeur du cpateur de 1
  int alea;
  // valeur de temperature mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
  
public:
  // thread representant le capteur et permettant de fonctionner independamment de la board
    virtual void run()=0;
    //constructeur
  Button(){};
};




// Création des trois classes de boutons différentes qui héritent de Button

//classe bouton
class Pressoir: public Button{
  private:
    int state;
    int temps;
  public:
    //constructeur
    Pressoir(int d);

    void run();
};

class Tilt: public Button{
  private:
    int state;
    int temps;
  public:
  //constructeur
  Tilt(int d);
  void run();
};

class Direction: public Button{
  private:
    int state;
    int temps;
  public:
  //constructeur
  Direction(int t);
  void run();
};


class LCD{
  //on voit si on peut utiliser la classe LCD qui existe
};





// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Device{
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];
  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

#endif
