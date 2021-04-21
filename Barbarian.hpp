/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This specification file defines the class abstract Barbarian. 
* It inherits from the class Character.
*******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Character.hpp"
#include "utilities.hpp"

class Barbarian : public Character {
public:
    virtual bool isDead() override;
    Barbarian();
    ~Barbarian();
};

#endif // BARBARIAN_HPP
