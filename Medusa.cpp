/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This implementation file contains member function definitions 
* for the class Medusa. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "Medusa.hpp"

/*******************************************************************************
* Description: The attack function rolls x number of dice with y sides and 
* return its result. If result is 12, Medusa's Glare is activated, adding 100 
* additional attack points.
*******************************************************************************/
int Medusa::attack() {
    int result{};
    for (unsigned i = 0; i < aDice; i++) {
        result += generateRandom(1, aSides);
    }
    if(result == 12) { // if Medusa rolls a 12, activate the glare
//        cout << "MEDUSA'S GLARE ACTIVATED!" << endl;
        return result + 100; // implement glare special ability by adding 100
    } else {
        return result;
    }
}

/*******************************************************************************
* Description: The isDead function returns true if the character has strength 
* of less than or equal to zero, and false otherwise.
*******************************************************************************/
bool Medusa::isDead() {
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
Medusa::Medusa() {
    charName = "Medusa";
    armor = 3;
    strength = 8;
    aDice = 2;
    aSides = 6;
    dDice = 1;
    dSides = 6;
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Medusa::~Medusa() {
}
