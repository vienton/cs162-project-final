/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class Room. It contains 
* member variables for the room's attributes and functions to affect those 
* attributes. The class also contains a constructor and a destructor.
*******************************************************************************/

#ifndef EXIT_ROOM_HPP
#define EXIT_ROOM_HPP

#include <string>
using std::string;

#include "Menu.hpp"
#include "utilities.hpp"

#include "Player.hpp"
#include "Room.hpp"

class ExitRoom : public Room {
private:

public:
    virtual void special(Player* p) override;
    ExitRoom();
    virtual ~ExitRoom();
        
};
#endif // EXIT_ROOM_HPP