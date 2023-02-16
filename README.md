Lollipop est un jeu de hasard où le joueur doit décider de ses pourcentages de gain et perte, plus les chances de gagner sont grandes, moins les gains seront élevés et inversement.
25 images  dissimulent soit des sucettes, soit des bâtons de sucette. 
Le joueur peut choisir le nombre de bâtons de sucettes qu'il y'aura parmi les 25 images. Plus il y'a de bâtons de sucette, plus le joueur prend de risques et donc les gains augmentent fortement. 
L'objectif du joueur est donc d'éviter ces bâtons de sucette et de deviner l'emplacement des sucettes.

La librairie externe que l'on utilisera sera SDL. Cela nous permettra de créer une interface graphique sur laquelle l'utilisateur pourra jouer au jeu et interagir avec les images.

La base de donnée stockera les données des utilisateurs (pseudo, mot de passe), leur gains actuels ainsi que les statistiques et les scores des parties précédentes.

________________________________________________________________________________________________________________________________________________________________________

Etapes effecutées :


-Jeu fonctionnel, les carrés se retournent sans erreurs et cliquer sur un lose arrête le jeu en retournant toutes les cases.

-Cliquer sur "Cashout" arrête la game en cours et force le reveal de toutes les cases. 

-On peut aussi relancer une partie, ce qui va remettre les cases à l'état initial et lancer un nouveau randomizer. 

-A chaque cashout ou gameover, un nouvel élément se rajoute a liste chainée et stocke différentes statistiques de jeu.

-Changer le nombre de broccolis modifie aussi le multiplicateur de maniere logique.

-Cliquer sur une lollipop change le multiplicateur

-Le compte en BANK est bien relié au bet et au multiplicateur, que ce soit en lançant une partie, en effectuant un cash out ou en perdant

Etapes en cours :


1- Fichier config avec mot de passe et username à stocker et à demander à chaque lancement du jeu 

2- Creation d'une nouvelle interface graphique pour se login ou sign in

4- Stocker la liste chainée dans un .txt et le récupérer au lancement du programme fichier txt

5- Les valeurs en BANK peuvent être négatives, faire en sorte que le chiffre au BET ne puisse pas dépasser le cash actuellement disponible