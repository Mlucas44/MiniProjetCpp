#ifndef PUISSANCE4_H
#define PUISSANCE4_H

#include <iostream>
#include <limits>
#include <cstdlib>

class puissance4 {
public:
    puissance4();
    ~puissance4();
    // méthode pour lancer le jeu
    void playGame();
    // méthode pour rejouer une fois la partie fini
    bool playAgain();
    // méthode pour demander les noms des joueurs
    void getPlayersInfo(); 

private:
    const int ROWS = 6;
    const int COLS = 7;
    int turn;
    char* board;
    const char PLAYER_ONE_SYMBOL = 'X';
    const char PLAYER_TWO_SYMBOL = 'O';
    const char EMPTY_SYMBOL = ' ';
    std::string player1_name;
    std::string player2_name;

    void initBoard();
    void printBoard();
    int getColumn();
    bool dropToken(char symbol, int col);
    bool checkWin(char symbol);
    bool isGameOver();
    void printResult(bool isTie, int winner);
};

#endif