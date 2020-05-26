#include <unistd.h>
#include "core_simulation.h"
#include "internal.h"

#include <fstream>
#include "jeu.h"

Dice De1;
Dice De2;
vector<Player> Joueurs;
vector<Player>::iterator courant;
vector<Player>::iterator chercher;

bool partie_lancee=1;

Player J0("Personne n'a ce role");
Roles Game1(J0);

Player J1("Odran");
Player J2("Matis");
Player J3("Florian");
Player J4("Mael");
Player J5("Hugo");



int stop=0;

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  // on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte

  //pin0 est le bouton de direction
  pinMode(0,INPUT);
  //pin1 est le bouton poussoir classique
  pinMode(1,INPUT);
  //pin2 est le bouton tilt
  pinMode(2,INPUT);

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
    //test bouton appuyé si fichiers txt créés
    digitalRead(0);
    digitalRead(1);
    


  }
  else{
    digitalRead(2);


    //test lancé de dé si bouton tilt appuyé et renvoie la valeur des deux dés
    if(ifstream("agiter.txt")){
    De1.throw_dice();
    sleep(1);
    De2.throw_dice(); 
    
    Afficher_valeur_role(De1.read_val(),De2.read_val(),*courant,&Game1);
    for (chercher=Joueurs.begin(); chercher!=Joueurs.end(); chercher++)
    {
      cout<<chercher->get_name()<<endl;
    }

    //cout<<Game1.getPlayer(CATIN)->get_name()<<endl;
    for (int role = 1; role < 10; role++)
    {
      cout<<"le role "<<role<<" est attribue à "<<Game1.getPlayer(role)->get_name()<<endl;
    }
    
    while (stop==0)
    {
      stop=digitalRead(1);
      sleep(1);
    }

    if (courant==Joueurs.end())
    {
      courant=Joueurs.begin();
    }else{
      courant++;
    }
    
    
    
    }
  }
  sleep(5);
};

 /* char buf[100];
  char buf2[100];
  int val;
  int valum;
  static int cpt=0;
  static int bascule=0;
  int i=0;
  
  for(i=0;i<10;i++){
    // lecture sur la pin 1 : capteur de temperature
    val=analogRead(1);
    valum=analogRead(2);
    sprintf(buf,"temperature %d",val);
    Serial.println(buf);
    sprintf(buf2,"luminosite %d",valum);
    Serial.println(buf2);

    if(cpt%5==0){
        // tous les 5 fois on affiche sur l ecran la temperature
      sprintf(buf,"%d",val);
      bus.write(1,buf,100);
    }
    cpt++;
    sleep(1);
  }
  bascule=digitalRead(4);
  cout<<"etat bouton: "<<bascule<<endl;
// on eteint et on allume la LED
  if(bascule){
    digitalWrite(0,HIGH);
    digitalWrite(3,HIGH);
    cout<<"bascule vers on \n";
  }
  else{
    digitalWrite(0,LOW);
    digitalWrite(3,LOW);
    cout<<"bascule vers off \n";
  }
  //bascule=1-bascule;
  */



