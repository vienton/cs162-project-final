/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This specification file defines the class Player. It contains 
* member variables for the player's attributes and functions to affect those 
* attributes. The class also contains a constructor and a destructor.
*******************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Character.hpp"

#define MAX_STRENGTH 100 // player's maximum strength
#define CAPACITY 1 // satchel capacity

class Player : public Character {
private:
    bool hasKey;
    vector<string> satchel;
public:
    void addStrength(int h); // add to health points
    void restoreStrength(); // set health points to parameter
    void saveReward(string r); // save reward to satchel
    void useReward(); // use reward in satchel
    bool getKey(); // return true if player has key
    void saveKey(); // save key
    virtual bool isDead() override; // override Character class
    Player();
    ~Player();
};
#endif // PLAYER_HPP