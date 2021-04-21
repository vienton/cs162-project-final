/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class Room. It contains 
* member variables for the room's attributes and functions to affect those 
* attributes. The class also contains a constructor and a destructor.
*******************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
using std::string;

#include "Player.hpp"
#include "Menu.hpp"
#include "utilities.hpp"

class Room {
protected:
    Room* up;
    Room* down;
    Room* left;
    Room* right;
    string type;
    bool exit;
    Player* p;
    friend class Game;
public:
    virtual void special(Player*) = 0; // function to make class abstract
    virtual void setType(string t);
    virtual bool getExit(); // for exiting the exit room
    Room();
    virtual ~Room();
        
};
#endif // ROOM_HPP