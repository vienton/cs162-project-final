/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This specification file defines the abstract class Character. It 
* contains member variables for each character's attributes and virtual 
* functions to affect those attributes.
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
using std::string;

#include "utilities.hpp"

class Character {
protected:
    string charName;
    unsigned armor;
    int strength;
    unsigned aDice; // # of attack dice
    unsigned aSides; // # of sides for attack die
    unsigned dDice; // # of defense dice
    unsigned dSides; // # of sides for defense die
    
public:
    virtual string getName();
    virtual int attack();
    virtual int defend();
    virtual int getArmor();
    virtual int getStrength();
    virtual void reduceStrength(int i);
    virtual bool isDead() = 0; // makes Character an abstract class
    virtual ~Character();        
};
#endif // CHARACTER_HPP