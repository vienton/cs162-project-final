/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This implementation file contains member function definitions 
* for the abstract class Character. Read the function descriptions to learn more
* about them.
*******************************************************************************/

#include "Character.hpp"

/*******************************************************************************
* Description: The getName function returns the variable name.
*******************************************************************************/
string Character::getName() {
    return charName;
}

/*******************************************************************************
* Description: The attack function rolls x number of dice with y sides and 
* return its result.
*******************************************************************************/
int Character::attack() {
    int result{};
    for (unsigned i = 0; i < aDice; i++) {
        result += generateRandom(1, aSides);
    }
    return result;
}

/*******************************************************************************
* Description: The defend function rolls x number of dice with y sides and 
* return its result.
*******************************************************************************/
int Character::defend() {
    int result{};
    for (unsigned i = 0; i < dDice; i++) {
        result += generateRandom(1, dSides);
    }
    return result;
}

/*******************************************************************************
* Description: The getArmor function returns the variable armor.
*******************************************************************************/
int Character::getArmor() {
    return armor;
}

/*******************************************************************************
* Description: The getStrength function returns the variable strength.
*******************************************************************************/
int Character::getStrength() {
    return strength;
}

/*******************************************************************************
* Description: The reduceStrength function accepts an integer and reduces the 
* strength by that amount.
*******************************************************************************/
void Character::reduceStrength(int i) {
    strength -= i;
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Character::~Character() {
}