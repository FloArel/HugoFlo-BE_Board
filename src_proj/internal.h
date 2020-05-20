#ifndef INTERNAL_H
#define INTERNAL_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
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
        Player* suiv;
        string Roles[15];


    public:
        Player();
        virtual ~Player();
        void enter_name(string nom);
        string get_name();
        Player* get_suiv();



};

class Liste{
    private:
        
    public:

};

#endif