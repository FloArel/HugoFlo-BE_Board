#include <unistd.h>
#include "core_simulation.h"
#include <fstream>
#include "jeu.h"
#include "internal.h"

Dice De1;
Dice De2;
vector<Player> Joueurs;
vector<Player>::iterator courant;
vector<Player>::iterator chercher;

//On démarre sans l'instanciation dynamique, qui ne marche pas pour l'instant
int partie_lancee=1;
//Déclaration du joueur par défaut 
Player J0("Personne");
Roles Game1(J0);
//Déclaration des joueurs 
Player J1("Odran");
Player J2("Matis");
Player J3("Florian");
Player J4("Mael");
Player J5("Hugo");

//Enumération pour afficher les rôles en toutes lettres sur le terminal
enum Pouvoir {Dieu,Heros,Oracle,Ecuyer,Prisonnier,Seductrice,Aubergiste,Princesse,Dragon};
static const char* strSignal[9]={"Dieu","Héros","Oracle","Ecuyer","Prisonnier","Seductrice","Aubergiste","Princesse","Dragon"};

int stop=0;

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);

  //pin0 est le bouton de direction
  pinMode(0,INPUT);
  //pin1 est le bouton poussoir classique
  pinMode(1,INPUT);
  //pin2 est le bouton tilt
  pinMode(2,INPUT);
//Ajout des joueurs dans la liste chainée
  Joueurs.push_back(J1);
  Joueurs.push_back(J2);
  Joueurs.push_back(J3);
  Joueurs.push_back(J4);
  Joueurs.push_back(J5);
  courant=Joueurs.begin();
 
}

// la boucle de controle arduino
void Board::loop(){
  
  if (partie_lancee!=1){
    
    char buf[100];
    int nb=1;
    sprintf(buf,"Entrez le nombre de joueurs grace aux boutons:");
    bus.write(1,buf,100);
    int dir=0;
    while (partie_lancee!=1)
    {
      sprintf(buf,"%d Joueurs",nb);
      bus.write(1,buf,100);

      //test bouton appuyé si fichiers txt créés
      
      //on lit la valeur du bouton directionnel 
      dir=digitalRead(0);
      switch (dir)
      {
      case 1:
        //augmenter nb de joueurs si up ou right
        if (nb<20){
          nb++;
          sleep(2);}
        break;
      case 2:
        //diminuer si down ou left
        if (nb>1){
          nb--;
          sleep(2);}
        break;

      case 3:
        //left
        if (nb>1){
          nb--;
          sleep(2);}
        break;
      case 4:
        //right
        if (nb<20){
          nb++;
          sleep(2);}
        break;
      default:
        break;
      }
      dir=0;

      partie_lancee=digitalRead(1);
      if (partie_lancee)
      {
        //la partie commentée suivante devait servir à implémenter la liste des joueurs
        /*
        for (int i = 0; i < nb; i++)
        {
          //instanciation dynamique des joueurs et chaînage dans la liste
          Player J("Joueur %d",nb);
          Joueurs.push_back(J);

        }
        
        sprintf(buf,"Partie lancee avec %d joueurs!",nb);
        bus.write(1,buf,100);
        courant=Joueurs.begin();
        
        */
      }
      
    
    }

  }
  else{
    int tilt=digitalRead(2);
    sleep(1);
    tilt=digitalRead(2);
    

    cout<<"C'est le tour de "<<courant->get_name()<<endl;
    //test lancé de dé si bouton tilt appuyé et renvoie la valeur des deux dés
    if(tilt){
    De1.throw_dice();
    sleep(1); //sert à donner 2 valeurs de dés différents car la rand est calé sur l'horloge interne de la machine
    De2.throw_dice(); 
    
    Afficher_valeur_role(De1.read_val(),De2.read_val(),*courant,&Game1,J0);
    

    //Si un joueur est prisonnier, il doit perdre ses rôles
    if(Game1.getPlayer(PRISONNIER)->get_name()!=J0.get_name()){
      for(int j=1;j<10;j++){
        if(j!=5){
        if(Game1.getPlayer(j)->get_name()==Game1.getPlayer(PRISONNIER)->get_name()){
          Game1.setPlayerRole(J0,j);
        }
      }
      }
       cout<<"Le prisonnier n'a plus de rôles!"<<endl;
    }

  //Permet de faire un rappel des rôles de chaque joueur à la fin de chaque tour de joueur
    for (int role = 1; role < 10; role++)
    {
      cout<<"Le rôle "<<strSignal[Dieu+role-1]<<" est attribué à "<<Game1.getPlayer(role)->get_name()<<endl;
    }
  //Permet de passer au joueur suivant
    if (courant==(Joueurs.end()-1))
    {
      courant=Joueurs.begin();
    }else{
      courant++;
    }
    
    
    
    }
  }
  sleep(2);
};




