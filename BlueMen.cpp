/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This implementation file contains member function definitions 
* for the class BlueMen. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "BlueMen.hpp"

/*******************************************************************************
* Description: The reduceStrength function accepts an integer parameter and 
* reduces the object's strength by that value.
*******************************************************************************/
void BlueMen::reduceStrength(int i) {
    strength -= i;
    if(i >= 4) {
        int lostDice = i / 4;
//        cout << "BLUE MEN LOSE " << lostDice << " DICE!" << endl;
        dDice -= lostDice; // reduce a defense die every 4 points
    }
}

/*******************************************************************************
* Description: The isDead function returns true if the character has strength 
* of less than or equal to zero, and false otherwise.
*******************************************************************************/
bool BlueMen::isDead() {
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
BlueMen::BlueMen() {
    charName = "Blue Men";
    armor = 3;
    strength = 12;
    aDice = 2;
    aSides = 10;
    dDice = 3;
    dSides = 6;
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
BlueMen::~BlueMen() {
}
