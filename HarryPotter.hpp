/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This specification file defines the class abstract HarryPotter. 
* It inherits from the class Character.
*******************************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include <iostream>
using std::cout;
using std::endl;

#include "Character.hpp"
#include "utilities.hpp"

class HarryPotter : public Character {
private:
    bool hogwarted;
public:
    virtual void reduceStrength(int i) override;
    virtual bool isDead() override;
    HarryPotter();
    ~HarryPotter();
};

#endif // HARRY_POTTER_HPP
