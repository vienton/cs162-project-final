/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This implementation file contains member function definitions 
* for the class Barbarian. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "Barbarian.hpp"

/*******************************************************************************
* Description: The isDead function returns true if the character has strength 
* of less than or equal to zero, and false otherwise.
*******************************************************************************/
bool Barbarian::isDead() {
    if(strength <= 0) {
        return true;
    } else {
        return false;
    }
}

/*******************************************************************************
* Description: The constructor initializes the member variables to the class's 
* default values.
*******************************************************************************/
Barbarian::Barbarian() {
    charName = "Barbarian";
    armor = 0;
    strength = 12;
    aDice = 2;
    aSides = 6;
    dDice = 2;
    dSides = 6;
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Barbarian::~Barbarian() {
}
