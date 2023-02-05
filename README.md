Lollipop est un jeu de hasard où le joueur doit décider de ses pourcentages de gain et perte, plus les chances de gagner sont grandes, moins les gains seront élevés et inversement.
25 images  dissimulent soit des sucettes, soit des bâtons de sucette. 
Le joueur peut choisir le nombre de bâtons de sucettes qu'il y'aura parmi les 25 images. Plus il y'a de bâtons de sucette, plus le joueur prend de risques et donc les gains augmentent fortement. 
L'objectif du joueur est donc d'éviter ces bâtons de sucette et de deviner l'emplacement des sucettes.

La librairie externe que l'on utilisera sera SDL. Cela nous permettra de créer une interface graphique sur laquelle l'utilisateur pourra jouer au jeu et interagir avec les images.

La base de donnée stockera les données des utilisateurs (pseudo, mot de passe), leur gains actuels ainsi que les statistiques et les scores des parties précédentes.

________________________________________________________________________________________________________________________________________________________________________

Il est nécessaire dans un premier temps de créer une interface graphique très simple, dans laquelle on va générer des carrés. Le seul évènement qui sera pris en charge au début sera le clic de souris sur ces carrés. Si l'utilisateur clique sur l'iun d'eux, alors le carré devra changer de couleur.
A terme, il faudra charger des images dans SQL et les remplacer selon l'état du carré --> cliqué ou non.
Dans un second temps je pense qu'il serait urgent de trouver comment rajouter le caractère aléatoire de l'état du carré, d'abord sans avoir à demander à l'utilsateur le coefficiant de gain/perte, on pourra l'imposer manuellement (50% par exemple) et faire le test pour vérifier qu'une fois qu'un carré rouge est cliqué , il devienne soit bleu à 50% ou jaune à 50% par exemple.