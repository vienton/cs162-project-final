/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/09/2019
* Description: This progam simulates a game where the object is for the player 
* to go through 9 rooms and finds a key in order to open the exit door. The 
* program can be run by executing the command "make" at the terminal prompt, 
* then the command "./run".
*******************************************************************************/

#include "utilities.hpp"
#include "Game.hpp"

int main() {
    srand(time(NULL));
    bool playFlag = false;
    Game* game = new Game;
    
    do {
        game->play();
        playFlag = game->endMenu();
    } while(playFlag);
    
    delete game;
    return 0;
}