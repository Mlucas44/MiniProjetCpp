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

## Installation du projet 

1. Assurez-vous que Docker et Visual Studio Code sont installés sur votre ordinateur.
2. Installez les extensions `CMake`, `CMake Tools`, `Dev Containers` dans Visual Studio Code.
2. Clonez le dépôt Git en utilisant la commande suivante :

```
git clone https://github.com/Mlucas44/MiniProjetCpp.git
```
3. Ouvrez le dossier du projet dans Visual Studio Code et appuyez sur `Ctrl` + `Shift` + `P`.Sélectionnez `Dev Containers: Open Folder in Container...` dans la liste et choisissez `From docker`. Cela créera le dossier `.devcontainer`
4. Ensuite, appuyez sur `Ctrl` + `Shift` + `P` et sélectionnez `CMake: Build`.Choisissez `GCC Linux` et laissez les options par défaut. Appuyez sur `Entrée`.Cela créera le dossier `./build`
5. Vous pouvez maintenant exécuter le programme en tapant la commande suivante dans un terminal :
```
./build/mini_projet_cpp
```
6. Amusez-vous bien !  ;) 
