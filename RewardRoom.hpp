/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class RewardRoom. The class 
* also contains a constructor and a destructor.
*******************************************************************************/

#ifndef REWARD_ROOM_HPP
#define REWARD_ROOM_HPP

#include <string>
using std::string;

#include "Menu.hpp"
#include "utilities.hpp"

#include "Player.hpp"
#include "Room.hpp"

class RewardRoom : public Room {
private:

public:
    void special(Player* p);
    RewardRoom();
    virtual ~RewardRoom();
        
};
#endif // REWARD_ROOM_HPP