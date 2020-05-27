#include "internal.h"
#include <cstdlib>
#include <time.h>

using namespace std;

#define TEST 0
#define TESTDE 0
#define TESTPLAY 1
#define TESTLISTE 1

//Ce fichier internal comprend les différentes classes non associées à des capteur


//constructeur dice
Dice::Dice(){
    value=1;
}


//Fonction poue lire la valeur du dé
int Dice::read_val(){
    return value;
}
//Fonction pour lancer le dé
void Dice::throw_dice(){
    
    // donner une seed differente selon l'horloge interne
    srand (time(NULL));

    // generer valeur random de 1 a 6
    value = rand() % 6 + 1;
    
}

//constructeur player
Player::Player(){
    name="joueur sans nom";
    
    
    
}
//Surcharge de constructeur
Player::Player(string nom){
    name=nom;
}

//destructeur player
Player::~Player(){
}
//Fonction pour attribuer un nom à un joueur
void Player::enter_name(string nom){
    name=nom;
    cout<<"nouveau nom: "<<name<<endl;
}
//Fonction pour obtenir le nom d'un joueur
string Player::get_name(){
    return name;
}

//constructeur roles
//constructeur: Tous les rôles sont attribués à un faux joueur J0
Roles::Roles(Player& J0){
    
    None=&J0;
    Dieu=&J0;
    Heros=&J0;
    Oracle=&J0;
    Ecuyer=&J0;
    Prisonnier=&J0;
    Catin=&J0;
    Aubergiste=&J0;
    Princesse=&J0;
    Dragon=&J0;

}
 //Fonction qui permet de dire quel joueur à le role donné en argument
Player* Roles::getPlayer(int role){
    switch (role)
        {
        case DIEU:
            return Dieu;
            break;
        case HEROS:
            return Heros;
            break;
        case ORACLE:
            return Oracle;
            break;
        case ECUYER:
            return Ecuyer;
            break;
        case PRISONNIER:
            return Prisonnier;
            break;
        case CATIN:
            return Catin;
            break;
        case AUBERGISTE:
            return Aubergiste;
            break;
        case PRINCESSE:
            return Princesse;
            break;
        case DRAGON:
            return Dragon;
            break;
        //voir si on raise une erreur
        default:
            return None;
            break;
        }
}
//Fonction permettant de donner à un rôle le nom d'un joueur
void Roles::setPlayerRole(Player& attrib, int role){
    switch (role){
        case DIEU:
            Dieu=&attrib;
            break;
        case HEROS:
            Heros=&attrib;
            break;
        case ORACLE:
            Oracle=&attrib;
            break;
        case ECUYER:
            Ecuyer=&attrib;
            break;
        case PRISONNIER:
            Prisonnier=&attrib;
            break;
        case CATIN:
            Catin=&attrib;
            break;
        case AUBERGISTE:
            Aubergiste=&attrib;
            break;
        case PRINCESSE:
            Princesse=&attrib;
            break;
        case DRAGON:
            Dragon=&attrib;
            break;
        }
}


// surcharge operateur += pour le nom de joueur
Player& Player::operator+= (const string & nom){
    if (nom == ""){
        cout << "Le nom ne peut pas etre vide!\n";
        exit(0);
    }
    enter_name(nom);
    return (*this);
}

//TODO: classe rôles avec un attribut pour chaque qui prend un player?
#if TEST
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
        Player J3("fraise");
        J1+="Plus radis";
        

    #endif

    #if TESTLISTE
        vector<Player> Joueurs;
        vector<Player>::iterator courant;
        Joueurs.push_back(J1);
        Joueurs.push_back(J2);
        Joueurs.push_back(J3);
        Roles Game1;
        Game1.setPlayerRole(&J3,DRAGON);
        cout<<"le dragon est "<<Game1.getPlayer(DRAGON)->get_name()<<endl;
        //cout<<Game1.getPlayer(DIEU)->get_name()<<endl;
        cout<<"nb joueurs crees "<<nb_joueurs<<endl;


    #endif


    courant=Joueurs.begin();
    cout<<courant->get_name()<<endl;
    courant++;
    cout<<courant->get_name()<<endl;


    return 0;


}
#endif