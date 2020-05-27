#ifndef INTERNAL_H
#define INTERNAL_H

//Ce fichier internal comprend la définition des différentes classes non associés à des capteur

//On attribue un int à chaque rôle pour les manipuler plus facilement
#define DIEU 1
#define HEROS 2
#define ORACLE 3
#define ECUYER 4
#define PRISONNIER 5
#define CATIN 6
#define AUBERGISTE 7
#define PRINCESSE 8
#define DRAGON 9

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <vector>

//#include "core_simulation.h"

using namespace std;
//Création de la classe Dice
class Dice{
    private:
        int value;
    public:
        //constructeur
        Dice();
        //Destructeur
        virtual ~Dice(){};
        int read_val();
        void throw_dice();
};



class Player{
    private:
        string name;

    public:
        Player();
        Player(string nom);
        virtual ~Player();
        void enter_name(string nom);
        string get_name();
        Player& operator+=(const string & nom);
        
        



};

class Roles{
    private:
        //TODO attribut tableau de player pour none et prisonnier?
        Player* None;
        Player* Dieu;
        Player* Heros;
        Player* Oracle;
        Player* Ecuyer;
        Player* Prisonnier;
        Player* Catin;
        Player* Aubergiste;
        Player* Princesse;
        Player* Dragon;
        
    public:
        
        Roles(Player& J0);

        Player* getPlayer(int role);

        void setPlayerRole(Player& attrib, int role);
        

};

#endif