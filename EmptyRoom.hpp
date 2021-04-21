/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class EmptyRoom. The class 
* also contains a constructor and a destructor.
*******************************************************************************/

#ifndef EMPTY_ROOM_HPP
#define EMPTY_ROOM_HPP

#include <string>
using std::string;

#include "Menu.hpp"
#include "utilities.hpp"

#include "Player.hpp"
#include "Room.hpp"

class EmptyRoom : public Room {
private:

public:
    virtual void special(Player* p) override;
    EmptyRoom();
    virtual ~EmptyRoom();
        
};
#endif // EMPTY_ROOM_HPP