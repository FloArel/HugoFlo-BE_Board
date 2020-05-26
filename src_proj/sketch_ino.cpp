#include <unistd.h>
#include "core_simulation.h"
#include "internal.h"
#include <fstream>
#include "jeu.h"

Dice De1;
Dice De2;

// la fonction d'initialisation d'arduino
void Board::setup(){
  // on configure la vitesse de la liaison
  Serial.begin(9600);
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(0,INPUT);
  pinMode(2,INPUT);
 
}

// la boucle de controle arduino
void Board::loop(){
//test bouton appuyé si fichiers txt créés
digitalRead(0);
digitalRead(1);
digitalRead(2);


//test lancé de dé si bouton tilt appuyé et renvoie la valeur des deux dés
if(ifstream("agiter.txt")){
De1.throw_dice();
sleep(1);
De2.throw_dice(); 
Afficher_valeur_role(De1.read_val(),De2.read_val());
sleep(5);
}


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



