#include <iostream>
#include <vector>
#include "puissance4.h"

int main()
{
    bool play = true;
    while (play) {
        puissance4 game;
        game.playGame();
        play = game.playAgain();
    }
    return 0;
}
