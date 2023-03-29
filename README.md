# Jeu de puissance 4

Le jeu de puissance 4 est un programme en ligne de commande qui permet à deux joueurs de jouer au célèbre jeu de puissance 4 sur une grille 7x6. Les joueurs jouent à tour de rôle en entrant le numéro de la colonne où ils souhaitent placer leur jeton.

## Fonctionnalités

1. Afficher la grille de jeu dans la console.
2. Laisser les joueurs choisir la colonne où ils veulent placer leur jeton.
3. Vérifier si un joueur a gagné, fait match nul ou si le jeu continue.
4. Afficher le résultat du jeu (victoire, match nul).
5. Optionnel: permettre aux joueurs de recommencer une partie.

### Exemple d'utilisation (CLI)

- `./puissance4`: Lance le jeu de puissance 4 en mode console.

## Contraintes techniques

1. Utiliser des tableaux statiques ou dynamiques pour représenter la grille de jeu.
2. Implémenter une classe pour gérer le jeu, avec des méthodes pour afficher la grille, effectuer les mouvements, vérifier les conditions de victoire et gérer les tours de jeu.
3. Utiliser des boucles for (version C++11) pour parcourir la grille et vérifier les conditions de victoire.
4. Gérer les erreurs d’entrée utilisateur et les exceptions, comme les colonnes pleines ou les entrées non valides.
5. Utiliser des caractères spécifiques pour représenter les jetons des deux joueurs et les cases vides de la grille.