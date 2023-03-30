#include "puissance4.h"
#include <iostream>
#include <vector>
    
puissance4::puissance4() {
    board = new char[ROWS * COLS];
    initBoard();
}

puissance4::~puissance4() {
    delete[] board;
}

void puissance4::initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(board + i*COLS + j) = EMPTY_SYMBOL;
        }
    }
}

void puissance4::printBoard() {
    std::cout << std::endl;
    for (int i = 0; i < ROWS; i++) {
        std::cout << "|";
        for (int j = 0; j < COLS; j++) {
            std::cout << *(board + i*COLS + j) << "|";
        }
        std::cout << std::endl;
    }
    std::cout << " 1 2 3 4 5 6 7" << std::endl << std::endl;
}

int puissance4::getColumn() {
    int col;
    do {
        std::cout << "Joueur " << (turn % 2) + 1 << ", veuillez choisir une colonne (1-7) : ";
        std::cin >> col;
        if (std::cin.fail()) {
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

bool puissance4::dropToken(char symbol, int col) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (*(board + i*COLS + col) == EMPTY_SYMBOL) {
            *(board + i*COLS + col) = symbol;
            return true;
        }
    }
    return false;
}

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


bool puissance4::isGameOver() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (*(board + i*COLS + j) == EMPTY_SYMBOL) {
                return false;
            }
        }
    }
    return true;
}

void puissance4::printResult(bool isTie, int winner) {
    if (isTie) {
        std::cout << "Match nul !" << std::endl;
    } else {
        std::cout << "Le joueur " << winner << " a gagné !" << std::endl;
    }
}

void puissance4::playGame() {
    initBoard();
    turn = 0;
    while (true) {
        printBoard();
        int col = getColumn();
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
    do {
        std::cout << "Voulez-vous jouer à nouveau ? (O/N) : ";
        std::cin >> choice;
        if (std::cin.fail()){
               } else if (choice == 'N' || choice == 'n') {
            return false;
        }
    } while (true);
}