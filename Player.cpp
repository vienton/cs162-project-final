/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class Player. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "Player.hpp"

/*******************************************************************************
* Description: The addStrength function accepts an integer parameter and adds 
* that to the player's strength, not to exceed the maximum strength.
*******************************************************************************/
void Player::addStrength(int h) {
    if(strength + h > MAX_STRENGTH) {
        strength = MAX_STRENGTH;
    } else {
        strength += h;
    }
}

/*******************************************************************************
* Description: The restoreStrength function restores the player to full strength
*******************************************************************************/
void Player::restoreStrength() {
    strength = MAX_STRENGTH;    
}

/*******************************************************************************
* Description: The saveReward function takes a string parameter representing 
* the reward item. If the satchel is at capacity, it does not save the item.
*******************************************************************************/
void Player::saveReward(string r) {
    if(satchel.size() >= CAPACITY) {
        cout << "\nNo more space in the satchel" << endl;
        cout << "Cannot save " << r << endl;
    } else {
        satchel.push_back(r);
        cout << "You have saved " << r << " in your satchel" << endl;
    }
}

/*******************************************************************************
* Description: The useReward function prints out the rewards if any is saved in 
* the player's satchel. It then prompts the user to use the items, if any, and 
* executes the function to utilize the item.
*******************************************************************************/
void Player::useReward() {    
    // if there are items in the satchel
    if(satchel.size()) {        
        // print available rewards
        cout << "\nUse an item in your satchel? " << endl;
        int j {1};
        for(auto i : satchel) {
            cout << j << ". " << i << endl;
            j++;
        }
        cout << satchel.size() + 1 << ". No thanks" << endl;
        cout << "Type your selection: ";
        int menuChoice = getIntInput();
        
        while(menuChoice < 1 || unsigned(menuChoice) > satchel.size() + 1) {
            cout << "Invalid input, try again: ";
            menuChoice = getIntInput();
        }
        
        // execute user selection
        if(unsigned(menuChoice) <= satchel.size()) {
            if(satchel[menuChoice - 1] == "Water") {
                addStrength(30); // consume water
                satchel.erase(satchel.begin() + menuChoice - 1);
                cout << "You've recovered 30 health points" << endl;
            } else if(satchel[menuChoice - 1] == "Sandwich") {
                addStrength(20); // consume sandwich
                satchel.erase(satchel.begin() + menuChoice - 1);
                cout << "You've recovered 20 health points" << endl;
            } else if(satchel[menuChoice - 1] == "Pill") {
                restoreStrength();
                satchel.erase(satchel.begin() + menuChoice - 1);
                cout << "You've recovered all your health points" << endl;
            }            
        }
    }
}

/*******************************************************************************
* Description: The getKey function returns true if the player has the key.
*******************************************************************************/
bool Player::getKey() {
    return hasKey;
}

/*******************************************************************************
* Description: The saveKey function saves the key with the player if the user 
* selects to do so.
*******************************************************************************/
void Player::saveKey() {
    hasKey = true;
}

/*******************************************************************************
* Description: The isDead function returns true if the character has strength 
* of less than or equal to zero, and false otherwise.
*******************************************************************************/
bool Player::isDead() {
    if(strength <= 0) {
        return true;
    } else {
        return false;
    }
}
    
/*******************************************************************************
* Description: The default constructor initializes the member variables to 
* empty.
*******************************************************************************/
Player::Player() {
    charName = "You";
    armor = 0;
    strength = MAX_STRENGTH;
    aDice = 2;
    aSides = 6;
    dDice = 2;
    dSides = 6;
    hasKey = false;
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Player::~Player(){
    satchel.clear();
}