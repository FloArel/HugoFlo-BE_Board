#include "jeu.h"

using namespace std;
//Fonction qui va récupérer en argument la valeur des deux dés, le joueur qui les a lancé et un pointeur vers le "tableau" des rôles
void Afficher_valeur_role (int de1, int de2, Player& J_courant, Roles* Game){
int a=de1; //attribue la valeur des dés dans des variables internes, pour évtier d'écrire De.get_val() à chaque fois
int b=de2;
int c;
Dice DeHeros; //Création d'un objet dé interne car quand les dés font 7, le héros et la catin s'interposent face au Dieu
cout<<"Le dé 1 fait "<<a<<endl; 
cout<<"le dé 2 fait "<<b<<endl;

//Les blocs if imbriqués ci-dessous montrent l'ensemble des possibilités du résultat des dés
//A chaque résultat, on affiche ce qu'il se passe et on attribue en interne le joueur courant au rôle si nécessaire
if ((a==1 && b==1) || (a==2 && b==2)|| (a==3 && b==3)){
    cout<<"Coup dur vous êtes héros"<<endl;
    Game->setPlayerRole(J_courant,HEROS);
} else {
            if((a==1 && b==3) || (a==3 && b==1)){
                cout<<"Bizutage en vue, un écuyer est né"<<endl; 
                Game->setPlayerRole(J_courant,ECUYER);
            } else {
                if((a==1 && b==4) || (a==4 && b==1)){
                    cout<<"Chaud devant la seductrice est là"<<endl;
                    Game->setPlayerRole(J_courant,SEDUCTRICE);
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

                                //Lorsque que les dés font 7, le dieu attaque. Si les rôles de Catin et Héros sont déjà attribués, ces derniers s'interposent et lancent un dé


                                if(a+b==7){
                                    cout<<"Tous aux abris, le Dieu attaque et donne "<<a<<" gorgées à une victime"<<endl;
                                    //Ci-dessous, la catin tente de s'interposer en lançant le dé déHeros instancié en début de fct
                                        if(Game->getPlayer(SEDUCTRICE)->get_name()!="Personne"){
                                            cout<<"La Seductrice s'interpose"<<endl;
                                            DeHeros.throw_dice();
                                            c=DeHeros.read_val();
                                            cout<<"le résultat est "<<c<<endl;
                                            if(c==1){
                                                cout<<"La Seductrice est la meilleure, le Dieu boit "<<a<<" gorgées"<<endl;
                                            }else{ cout<<"La Seductrice est la pire, elle boit "<<a<<" gorgées"<<endl;}


                                        }else{
                                        //Si la catin n'existe pas ou rate, le héros s'interpose en lançant le même dé
                                        //Le case sert à dire ce qu'il se passe en fonction du résultat du dé du héros                                  
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
                                            //Si le héros et la catin ne sont pas attribués, la victime boit directement 
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
