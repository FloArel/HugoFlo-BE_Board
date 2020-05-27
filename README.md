# BE_Board
Simulation du projet de C++: Jeu de dés mon foie est mon glaive.

Les boutons sont simulés par la présence de fichiers .txt dans le dossier de l'exécutable. Pour faciliter la simulation de ces boutons nous avons écrit un script shell "script_bouton.sh" permettant l'interaction au clavier.

Les règles du jeu sont assez élaborées car dépendent du montant des dés, et les combinaisons sont nombreuses. Nous allons rédiger les règles en détail dans ce readme mais leur connaissance n'est pas du tout indispensable pour jouer.

Les fichiers internal contiennent les définitions des classes internes telles que les joueurs et les rôles, les fichiers mydevice contiennent les définitions des classes correspondant aux objets physiques: boutons, écran.
Le fichier Jeu.cpp contient la fonction principale d'évaluation des actions et attributions de rôles selon le montant des dés.

Précisions sur la boucle loop du fichier sketch_ino.cpp:
 
Elle est "séparée" en deux parties, le paramétrage de la partie, puis le déroulement de la partie. Le paramétrage n'a lieu que la première fois que la boucle est exécutée et sert à ajouter le bon nombre de joueurs et leur noms. C'est ici que servent le bouton directionnel et le poussoir.
