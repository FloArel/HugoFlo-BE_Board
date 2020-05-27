# BE_Board
Simulation du projet de C++: Jeu de dés mon foie est mon glaive.

Les boutons sont simulés par la présence de fichiers .txt dans le dossier de l'exécutable. Pour faciliter la simulation de ces boutons nous avons écrit un script shell "script_bouton.sh" permettant l'interaction au clavier.

Les règles du jeu sont assez élaborées car dépendent du montant des dés, et les combinaisons sont nombreuses. Nous allons rédiger les règles en détail dans ce readme mais leur connaissance n'est pas du tout indispensable pour jouer.

Les fichiers internal contiennent les définitions des classes internes telles que les joueurs et les rôles, les fichiers mydevice contiennent les définitions des classes correspondant aux objets physiques: boutons, écran.
Le fichier Jeu.cpp contient la fonction principale d'évaluation des actions et attributions de rôles selon le montant des dés.

Précisions sur la boucle loop du fichier sketch_ino.cpp:  
Elle est "séparée" en deux parties, le paramétrage de la partie, puis le déroulement de la partie. Le paramétrage n'a lieu que la première fois que la boucle est exécutée et sert à ajouter le bon nombre de joueurs et leur noms. C'est ici que servent le bouton directionnel et le poussoir.

## Règles du Jeu
Dans ce jeu, des rôles vous seront affectés en fonction de vos lancés de dés.  
6 sur un des dés => distribue l’autre dé (par exemple 6 et 2 : distribue 2)  
51/42 sur les dés : tout le monde boit.
* __Rôle de Dieu__  
Le joueur devient Dieu s’il fait un double 4, 5 ou 6.
A chaque fois qu’un joueur joue, si la somme des dés normaux fait 7, Dieu attaque le village et distribue le plus grands des dés normaux (ex : 4 et 3, Dieu distribue 4)  
Si la séductrice ou le héros sont attribués ils doivent intervenir.

* __Rôle du Héros__  
Le joueur devient Héros s’il fait double 1, 2 ou 3.
Quand Dieu attaque le village le Héros tente de protéger le village en lançant un dé, s’il fait :
  * 1 il est foudroyé, il boit son verre cul-sec et n’est plus le Héros  
  * 2 ou 3 il échoue et boit le nombre de gorgées en jeu, et Dieu distribue les gorgées  
  * 4 ou 5 le héros réussi seulement à s'interposer, il boit les gorgées en jeu  
  * 6 le Héros protège le village, Dieu boit les gorgées en jeu
  
* __Rôle de l'Ecuyer__  
Le joueur devient écuyer s’il fait 3 et 1.
Boit tout ce que le Héros boit (autant de gorgées que le Héros).

* __Rôle de l'Oracle__  
Le joueur devient Oracle s’il fait 2 et 1.
Peut influer de 1 sur le score du dé lancé par le héros lors de la défense contre le dieu, dans un sens ou dans l'autre (par exemple si le héros fait 5, il peut choisir de changer le montant en 4 ou 6, ou laisser 5).

* __Rôle du Prisonnier__  
Le joueur devient Prisonnier s’il fait 3 et 2 s’il n’y a pas déjà un Prisonnier, pour fêter son nouveau statut il boit.  
On perd tous ses rôles en rentrant en prison et on ne peut pas en gagner en étant en prison.  
Doit boire quand un joueur fait un 3.  
Pour sortir de prison il faut faire un 3, et boire pour fêter ça.  

* __Rôle de la Séductrice__  
Le joueur devient la Séductrice s’il fait 4 et 1.
Lorsque Dieu attaque le village, la Séductrice s’interpose en lançant un dé avant le Héros:  
  * Si elle fait 1, elle sauve le village, Dieu boit ses gorgées et ne distribue pas.  
  * Si elle fait un autre score, elle boit son score.
L’Oracle ne prédit pas le score de la Séductrice.  

* __Rôle de l'Aubergiste__  
Le joueur devient Aubergiste s’il fait 5 et 3.  
Dès que quelqu’un distribue des gorgées à un autres joueur, peut faire +1 ou -1 au nombre de gorgées.  

* __Rôle de la Princesse__  
Le joueur devient Princesse s’il fait 5 et 4.  
A chaque fois qu’un joueur donne des gorgées à la Princesse, elle peut en donner la moitié au Héros (ex : si un joueur lui donne 4 gorgées, elle peut en transmettre 2 à son Héros, donc elle boit 2 et le héros 2).  

* __Rôle du Dragon__  
Le joueur devient Dragon s’il fait 6 et 5.  
Le joueur donne 5 gorgées en plus de devenir Dragon.  
Quand un joueur lui donne des gorgées il peut les souffler à droite ou à gauche, il donne son nombre de gorgées divisé par 2 à la première personne à côté de lui, divisé par 4 à la personne d’après, etc jusqu’à arriver à 1.  
