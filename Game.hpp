/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class Game. It contains 
* member variables for the room's attributes and functions to affect those 
* attributes. The class also contains a constructor and a destructor.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "utilities.hpp"
#include "Menu.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "BadGuyRoom.hpp"
#include "EmptyRoom.hpp"
#include "ExitRoom.hpp"
#include "KeyRoom.hpp"
#include "RewardRoom.hpp"

#define DIMENSION 3

class Game {
private:
    int xPos, yPos;
    bool gameOver;
    // 2D vector to hold the map
    vector<vector<Room*>> board;
    // 2D array to hold keys to instantiate the map
    vector<vector<char>> key;
    Menu* endGame;
    Menu* playMenu;
    Player* player;
    Room* current;
public:
    void setGameOver(); // set gameOver flag to true;
    bool endMenu(); // print menu at end of game
    void initializeRooms(); // initialize the map with rooms
    void linkRooms(); // link the rooms together
    void printBoard(); // print out the boad with player's location
    void play(); // function to run the ame
    Game();
    ~Game();
};

#endif // GAME_HPP
