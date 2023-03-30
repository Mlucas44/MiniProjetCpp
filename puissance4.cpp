#include "puissance4.h"
#include <iostream>
#include <vector>

// Constructeur
puissance4::puissance4() {
    board = new char[ROWS * COLS];
    initBoard();
}

// Destructeur
puissance4::~puissance4() {
    delete[] board;
}

// Initialise le plateau de jeu avec le symbole vide (EMPTY_SYMBOL).
void puissance4::initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // board = pointeur vers le tableau dynamique qui stoke les val du tab 
            *(board + i*COLS + j) = EMPTY_SYMBOL;
        }
    }
}

// Affiche le plateau de jeu sur la console.
void puissance4::printBoard() {
    std::cout << std::endl;
    // boucle sur les ligne du plateau (selon ROWS)
    for (int i = 0; i < ROWS; i++) {
        std::cout << "|";
        // boucle ensuite sur les colone (selon COLS)
        for (int j = 0; j < COLS; j++) {
            std::cout << *(board + i*COLS + j) << "|";
        }
        std::cout << std::endl;
    }
    std::cout << " 1 2 3 4 5 6 7" << std::endl << std::endl;
}

// Demande à l'utilisateur de saisir une colonne valide pour placer son jeton.
int puissance4::getColumn() {
    // Colonne choisie par le joueur
    int col;
    do {
        // demande au joueur de saisir une colonne
        std::cout << "Joueur " << (turn % 2) + 1 << ", veuillez choisir une colonne (1-7) : ";
        std::cin >> col;
        // Si saisie invalide
        if (std::cin.fail()) {
            // vide le flux d'entrée cin
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrée non valide. Veuillez entrer un nombre entier entre 1 et 7." << std::endl;
        } else if (col < 1 || col > 7) {
            std::cout << "Entrée non valide. Veuillez entrer un nombre entier entre 1 et 7." << std::endl;
        } else {
            break;
        }
    } while (true);

    return col;
}

// Place le jeton dans la colonne donnée sur le plateau de jeu.
bool puissance4::dropToken(char symbol, int col) {
    for (int i = ROWS - 1; i >= 0; i--) {
        // Vérifie si la case est vide 
        if (*(board + i*COLS + col) == EMPTY_SYMBOL) {
            *(board + i*COLS + col) = symbol;
            return true;
        }
    }
    return false;
}
// Vérifie si le symbole/Joueur donné a gagné le jeu.
bool puissance4::checkWin(char symbol) {
    // Vérification des lignes
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (*(board + i*COLS + j) == symbol && *(board + i*COLS + j+1) == symbol && 
                *(board + i*COLS + j+2) == symbol && *(board + i*COLS + j+3) == symbol) {
                return true;
            }
        }
    }
    // Vérification des colonnes
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (*(board + i*COLS + j) == symbol && *(board + (i+1)*COLS + j) == symbol && 
                *(board + (i+2)*COLS + j) == symbol && *(board + (i+3)*COLS + j) == symbol) {
                return true;
            }
        }
    }

    // Vérification des diagonales descendantes
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (*(board + i*COLS + j) == symbol && *(board + (i+1)*COLS + j+1) == symbol && 
                *(board + (i+2)*COLS + j+2) == symbol && *(board + (i+3)*COLS + j+3) == symbol) {
                return true;
            }
        }
    }

    // Vérification des diagonales montantes
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (*(board + i*COLS + j) == symbol && *(board + (i-1)*COLS + j+1) == symbol && 
                *(board + (i-2)*COLS + j+2) == symbol && *(board + (i-3)*COLS + j+3) == symbol) {
                return true;
            }
        }
    }

    return false;
}

// Vérifie si le plateau de jeu est rempli sans gagnant.
bool puissance4::isGameOver() {
    // parcour les ligne du plateau 
    for (int i = 0; i < ROWS; i++) {
        // parcour les colonnes du plateau
        for (int j = 0; j < COLS; j++) {
            // Vérifie que la case est vide 
            if (*(board + i*COLS + j) == EMPTY_SYMBOL) {
                return false;
            }
        }
    }
    return true;
}

// Affiche le résultat final de la partie en fonction de l'existence d'un gagnant ou d'un match nul.
void puissance4::printResult(bool isTie, int winner) {
    if (isTie) {
        std::cout << "Match nul !" << std::endl;
    } else {
        std::cout << "Le joueur " << winner << " a gagné !" << std::endl;
    }
}

// Lance la tram du jeu 
void puissance4::playGame() {
    initBoard();
    turn = 0;
    while (true) {
        printBoard();
        int col = getColumn()-1;
        char symbol = (turn % 2 == 0) ? PLAYER_ONE_SYMBOL : PLAYER_TWO_SYMBOL;
        if (dropToken(symbol, col)) {
            if (checkWin(symbol)) {
                printBoard();
                printResult(false, (turn % 2) + 1);
                break;
            }
            if (isGameOver()) {
                printBoard();
                printResult(true, 0);
                break;
            }
            turn++;
        } else {
            std::cout << "La colonne est pleine. Veuillez choisir une autre colonne." << std::endl;
        }
    }
}

bool puissance4::playAgain() {
    char choice;
    bool validChoice = false;
    do {
        std::cout << "Voulez-vous jouer à nouveau ? (O/N) : ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Entrée invalide. Veuillez entrer 'O' ou 'N'." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (choice == 'N' || choice == 'n') {
            return false;
        } else if (choice == 'O' || choice == 'o') {
            validChoice = true;
        } else {
            std::cout << "Entrée invalide. Veuillez entrer 'O' ou 'N'." << std::endl;
        }
    } while (!validChoice);
    return true;
}