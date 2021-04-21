/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This implementation file contains member function definitions 
* for the class HarryPotter. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "HarryPotter.hpp"

/*******************************************************************************
* Description: The reduceStrength function accepts an integer parameter and 
* reduces the object's strength by that value.
*******************************************************************************/
void HarryPotter::reduceStrength(int i) {
    strength -= i;
    if(strength <= 0 && !hogwarted) {
//        cout << "HARRY'S HOGWARTS ACTIVATED" << endl;
        strength = 20;
        hogwarted = true;
    }
}

/*******************************************************************************
* Description: The isDead function returns true if the character has strength 
* of less than or equal to zero, and false otherwise.
*******************************************************************************/
bool HarryPotter::isDead() {
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
HarryPotter::HarryPotter() {
    charName = "Harry Potter";
    armor = 0;
    strength = 10;
    aDice = 2;
    aSides = 6;
    dDice = 2;
    dSides = 6;
    hogwarted = false;
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
HarryPotter::~HarryPotter() {
}
