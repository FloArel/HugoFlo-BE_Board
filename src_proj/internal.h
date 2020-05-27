#ifndef INTERNAL_H
#define INTERNAL_H

//Ce fichier internal comprend la définition des différentes classes non associés à des capteur

//On attribue un int à chaque rôle pour les manipuler plus facilement
#define DIEU 1
#define HEROS 2
#define ORACLE 3
#define ECUYER 4
#define PRISONNIER 5
#define SEDUCTRICE 6
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
//Création de la classe Dice avec fonctions pour lancer un dé et lire sa valeur
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

//Création de la classe Player qui permet d'instancier un joueur et de lui donner un nom

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
//Création de la classe Roles 
//Meme si c'était moins intuitif, il était plus simple que les joueurs soient contenus dans le tableau des rôles
//En effet, dans ce jeu, un rôle ne peut être attribué que à un seul joueur en même temps
class Roles{
    private:
        //TODO attribut tableau de player pour none et prisonnier?
        Player* None;
        Player* Dieu;
        Player* Heros;
        Player* Oracle;
        Player* Ecuyer;
        Player* Prisonnier;
        Player* Seductrice;
        Player* Aubergiste;
        Player* Princesse;
        Player* Dragon;
        
    public:
        //Constructeur qui donne tous les rôles à un joueur "Personne" par défaut : cela permet de dire que personne n'a ce rôle
        Roles(Player& J0);
        //Fonction qui permet de dire quel joueur à le role donné en argument
        Player* getPlayer(int role);
        //Fonction permettant de donner à un rôle le nom d'un joueur
        void setPlayerRole(Player& attrib, int role);
        

};

#endif