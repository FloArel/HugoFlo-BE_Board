#ifndef INTERNAL_H
#define INTERNAL_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"

class Dice{
    private:
        int value;
    public:
        Dice();
        virtual ~Dice();
        int read_val();
        void throw_dice();
};



class Player{
    private:
        string name;
        Player* suiv;


    public:
        Player();
        virtual ~Player();
        void enter_name();


};