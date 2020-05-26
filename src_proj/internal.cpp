#include "internal.h"
#include <cstdlib>
#include <time.h>

using namespace std;

#define TESTDE 0
#define TESTPLAY 1

//var globale pour savoir quels roles sont attribues avec masques
//static int roles_attrib=0;
//var globale total joueurs pour faire la liste
static int nb_joueurs=0;

//pointeurs joueurs pour parcours de la liste chainee
static Player* dernier=NULL;
static Player* premier=NULL;
static Player* J_courant=NULL;

//constructeur dice
Dice::Dice(){
    value=1;
    cout<<"dé créé"<<endl;
}



int Dice::read_val(){
    return value;
}

void Dice::throw_dice(){
    
    // donner une seed differente selon l'horloge interne
    srand (time(NULL));

    // generer valeur random de 1 a 6
    value = rand() % 6 + 1;
    
}

//constructeur player
Player::Player(){
    name="joueur sans nom";
    int i;
    for (i = 0; i < 15; i++)
    {
        Roles[i]="rien";
    }

    if (nb_joueurs==0){
        suiv=NULL;
        premier=this;
        dernier=this;
    }
    else
    {
        suiv=NULL;
        dernier->suiv=this;
        dernier=this;
    }
    
}

//destructeur player
Player::~Player(){

}

void Player::enter_name(string nom){
    name=nom;
    cout<<"nouveau nom: "<<name<<endl;
}

string Player::get_name(){
    return name;
}

Player* Player::get_suiv(){
    return suiv;
}

//TODO: classe rôles avec un attribut pour chaque qui prend un player?

int main(){
    
    #if TESTDE
        Dice De1;
        Dice De2;
        De2.throw_dice();
        cout<<De1.read_val()<<endl;
        cout<<De2.read_val()<<endl;
    #endif

    #if TESTPLAY
        Player J1;
        J1.enter_name("patate");
        Player J2;
        J2.enter_name("radis");
        int i
        for (i = 0; i < 15; i++)
        {
            
        }
        
        


    #endif

    return 0;



}
