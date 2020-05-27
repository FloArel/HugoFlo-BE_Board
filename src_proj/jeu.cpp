#include "jeu.h"

using namespace std;

void Afficher_valeur_role (int de1, int de2, Player& J_courant, Roles* Game){
int a=de1;
int b=de2;
int c;
Dice DeHeros;
cout<<"Le dé 1 fait "<<a<<endl;
cout<<"le dé 2 fait "<<b<<endl;
if ((a==1 && b==1) || (a==2 && b==2)|| (a==3 && b==3)){
    cout<<"Coup dur vous êtes héros"<<endl;
    Game->setPlayerRole(J_courant,HEROS);
} else {
            if((a==1 && b==3) || (a==3 && b==1)){
                cout<<"Bizutage en vue, un écuyer est né"<<endl; 
                Game->setPlayerRole(J_courant,ECUYER);
            } else {
                if((a==1 && b==4) || (a==4 && b==1)){
                    cout<<"Chaud devant la catin est là"<<endl;
                    Game->setPlayerRole(J_courant,CATIN);
                } else {
                    if((a==1 && b==5) || (a==5 && b==1)||(a==2 && b==4) || (a==4 && b==2)){
                        cout<<"Tout le monde boit !"<<endl;
                    } else{
                        if((a==1 && b==6) || (a==6 && b==1)){
                            cout<<"Tu distribues une gorgée"<<endl;
                        } else{
                            if((a==2 && b==3) || (a==3 && b==2)){
                                cout<<"C'en est fini de toi va en prison et perd tous tes biens"<<endl;
                                Game->setPlayerRole(J_courant,PRISONNIER);
                            } else{
                                if(a+b==7){
                                    cout<<"Tous aux abris, le Dieu attaque et donne "<<a<<" gorgées à une victime"<<endl;
                                        if(Game->getPlayer(CATIN)->get_name()!="Personne"){
                                            cout<<"La Catin s'interpose"<<endl;
                                            DeHeros.throw_dice();
                                            c=DeHeros.read_val();
                                            cout<<"le résultat est "<<c<<endl;
                                            if(c==1){
                                                cout<<"La Catin est la meilleure, le Dieu boit "<<a<<" gorgées"<<endl;
                                            }else{ cout<<"La Catin est la pire, elle boit "<<a<<" gorgées"<<endl;}


                                        }else {
                                        if(Game->getPlayer(HEROS)->get_name()!="Personne"){
                                            cout<<"Héros lancez le dé"<<endl;
                                            DeHeros.throw_dice();
                                            c=DeHeros.read_val();
                                            cout<<"le résultat est "<<c<<endl;
                                            switch(c){
                                                case 1 : 
                                                    cout<<"le héros boit cul sec"<<endl; 
                                                    break;
                                                case 2 :
                                                case 3 : 
                                                    cout<<"le héros et la victime du Dieu boivent "<<a<<" gorgées"<<endl;
                                                    break;
                                                case 4 :
                                                case 5 : 
                                                    cout<<"le héros s'interpose et boit "<<a<<" gorgées"<<endl;
                                                    break;
                                                case 6 : 
                                                    cout<<"Sheh le Dieu tu bois "<<a<<" gorgées"<<endl;
                                                    break;

                                            }    

                                        }else {cout<<"La victime boit "<<a<<" gorgées"<<endl;}}
                                } else{
                                    if ((a==4 && b==4) || (a==5 && b==5)|| (a==6 && b==6)){
                                            cout<<"Gare à vous le Dieu est arrivé"<<endl;
                                            Game->setPlayerRole(J_courant,DIEU);
                                    } else {
                                        if((a==4 && b==5) || (a==5 && b==4)){
                                                cout<<"Monsieur le héros, vous avez une nouvelle princesse à sauver"<<endl;
                                                Game->setPlayerRole(J_courant,PRINCESSE);
                                        }else {
                                            if((a==3 && b==5) || (a==5 && b==3)){  
                                                    cout<<"Tournée générale, l'aubergiste vous accueille"<<endl;
                                                    Game->setPlayerRole(J_courant,AUBERGISTE);
                                            }else{
                                                if((a==6 && b==5) || (a==5 && b==6)){
                                                        cout<<"Le dragon sort de sa grotte"<<endl;
                                                        Game->setPlayerRole(J_courant,DRAGON);
                                                }else {
                                                    if((a==2 && b==6) || (a==6 && b==2)){
                                                            cout<<"Donne 2!"<<endl;
                                                    }else {
                                                        if((a==3 && b==6) || (a==6 && b==3)){
                                                                cout<<"Donne 3!"<<endl;
                                                        }else {
                                                            if((a==4 && b==6) || (a==6 && b==4)){
                                                                    cout<<"Donne 4!"<<endl;
                                                            }else{
                                                                cout<<"Il ne se passe rien"<<endl;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
               }
            }
}
        
}
