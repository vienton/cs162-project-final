/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class BadGuyRoom. The class 
* also contains a constructor and a destructor.
*******************************************************************************/

#ifndef BG_ROOM_HPP
#define BG_ROOM_HPP

#include <string>
using std::string;

#include "Menu.hpp"
#include "utilities.hpp"

#include "Player.hpp"
#include "Room.hpp"
#include "Combat.hpp" // for battle with bad guys

class BadGuyRoom : public Room {
private:

public:
    virtual void special(Player* p) override;
    BadGuyRoom();
    virtual ~BadGuyRoom();
        
};
#endif // BG_ROOM_HPP