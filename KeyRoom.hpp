/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class Room. The class also 
* contains a constructor and a destructor.
*******************************************************************************/

#ifndef KEY_ROOM_HPP
#define KEY_ROOM_HPP

#include <string>
using std::string;

#include "Menu.hpp"
#include "utilities.hpp"

#include "Player.hpp"
#include "Room.hpp"

class KeyRoom : public Room {
private:

public:
    virtual void special(Player* p) override;
    KeyRoom();
    virtual ~KeyRoom();
        
};
#endif // KEY_ROOM_HPP