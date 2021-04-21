/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This specification file defines the class abstract Medusa. It 
* inherits from the class Character.
*******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
using std::cout;
using std::endl;

#include "Character.hpp"
#include "utilities.hpp"

class Medusa : public Character {
public:
    virtual int attack();
    virtual bool isDead() override;
    Medusa();
    ~Medusa();
};

#endif // MEDUSA_HPP
