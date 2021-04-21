/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This specification file defines the class Combat. It contains 
* pointers to Character's derived objects for the game play and to Menu objects.
* The functions charactersMenu and endMenu display the two menus to obtain 
* inputs from users. The play function runs the game based on user's selections.
* The class also contains a constructor and destructor.
*******************************************************************************/

#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "Menu.hpp"
#include "utilities.hpp"

#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Player.hpp"

class Combat {
private:
    Character *char1;
    Character *char2;
    
public:
    void charactersMenu();
    bool endMenu();
    void play(Player* p);
    Combat();
    ~Combat();
};

#endif // COMBAT_HPP
