#ifndef INTERNAL_H
#define INTERNAL_H


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

class Dice{
    private:
        int value;
    public:
        Dice();
        virtual ~Dice(){};
        int read_val();
        void throw_dice();
};



class Player{
    private:
        string name;
        //Player* suiv;
        //string Roles[15];


    public:
        Player();
        Player(string nom);
        virtual ~Player();
        void enter_name(string nom);
        string get_name();
        Player& operator+=(const string & nom);
        //Player* get_suiv();
        



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
        
        Roles();
        Player* getPlayer(int role);

        void setPlayerRole(Player* attrib, int role);
        

};

#endif