/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This specification file defines the class abstract BlueMen. 
* It inherits from the class Character.
*******************************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include <iostream>
using std::cout;
using std::endl;

#include "Character.hpp"

class BlueMen : public Character {
public:
    virtual void reduceStrength(int i) override;
    virtual bool isDead() override;
    BlueMen();
    ~BlueMen();
};

#endif // BLUE_MEN_HPP
