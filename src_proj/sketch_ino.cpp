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

bool partie_lancee=1;

Player J0("Personne");
Roles Game1(J0);

Player J1("Odran");
Player J2("Matis");
Player J3("Florian");
Player J4("Mael");
Player J5("Hugo");
enum Pouvoir {Dieu,Heros,Oracle,Ecuyer,Prisonnier,Catin,Aubergiste,Princesse,Dragon};
static const char* strSignal[9]={"Dieu","Héros","Oracle","Ecuyer","Prisonnier","Catin","Aubergiste","Princesse","Dragon"};

int stop=0;

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
  // on fixe les pin en entree et en sporite en fonction des capteurs/actionneurs mis sur la carte

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

    cout<<"C'est le tour de "<<courant->get_name()<<endl;
    //test lancé de dé si bouton tilt appuyé et renvoie la valeur des deux dés
    if(ifstream("agiter.txt")){
    De1.throw_dice();
    sleep(1);
    De2.throw_dice(); 
    
    Afficher_valeur_role(De1.read_val(),De2.read_val(),*courant,&Game1);
    if(Game1.getPlayer(PRISONNIER)->get_name()!=J0.get_name()){
      for(int j=1;j<10;j++){
        if(j!=5){
        if(Game1.getPlayer(j)->get_name()==Game1.getPlayer(PRISONNIER)->get_name()){
          Game1.setPlayerRole(J0,j);
        }
      }
      }
       cout<<"Le prisonnier perd tous ses rôles"<<endl;
    }

    /*for (chercher=Joueurs.begin(); chercher!=Joueurs.end(); chercher++)
    {
      cout<<chercher->get_name()<<endl;
    }*/

    //cout<<Game1.getPlayer(CATIN)->get_name()<<endl;
    for (int role = 1; role < 10; role++)
    {
      cout<<"Le rôle "<<strSignal[Dieu+role-1]<<" est attribué à "<<Game1.getPlayer(role)->get_name()<<endl;
    }

    if (courant==(Joueurs.end()-1))
    {
      courant=Joueurs.begin();
    }else{
      courant++;
    }
    
    
    
    }
  }
  sleep(4);
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



