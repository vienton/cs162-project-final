/*******************************************************************************
* Program name: Fantasy Combat Game
* Author: Vien Ton
* Date: 11/02/2019
* Description: This implementation file contains member function definitions 
* for the class Combat. Read the function descriptions to learn more
* about them.
*******************************************************************************/

#include "Combat.hpp"

/*******************************************************************************
* Description: The play function simulates the battle between the Player and a 
* randomly assigned Character.
*******************************************************************************/
void Combat::play(Player* p) {
    // assign characters
    char1 = p;
    
    // randomly assign character 2
    int num = generateRandom(1, 5);
    switch(num) {
        case 1:
        {
            char2 = new Vampire;
            break;
        }
        case 2:
        {
            char2 = new Barbarian;
            break;
        }
        case 3:
        {
            char2 = new BlueMen;
            break;
        }
        case 4:
        {
            char2 = new Medusa;
            break;
        }
        case 5:
        {
            char2 = new HarryPotter;
            break;
        }
        default:
        {
            break;
        }
    }
    
    cout << "\nYou must battle " << char2->getName() << endl;

    // play 
    int roundNo{1}, aRoll{}, dRoll{}, actualDamage{};
    do {
        // assign random first attacker
        int firstAttacker = generateRandom(1, 2);
        
        if(firstAttacker == 1 && !char1->isDead()) { // if char1 is first attacker
            
            // roll the dice
            aRoll = char1->attack(); // attack roll
            dRoll = char2->defend(); // defend roll
            
            // calculate damage
            actualDamage = aRoll - dRoll - char2->getArmor();
            if(actualDamage <= 0) { // make sure no negative damage
                actualDamage = 0;
            } else {
                actualDamage = aRoll - dRoll - char2->getArmor();                    
            }
            
            // reduce defender's strength
            char2->reduceStrength(actualDamage);
            
            if(!char2->isDead()) { // make sure defender isn't already dead
                
                // roll the dice
                aRoll = char2->attack(); // attack roll
                dRoll = char1->defend(); // defend roll
                
                // calculate damage
                actualDamage = aRoll - dRoll - char1->getArmor();
                if(actualDamage <= 0) { // make sure no negative damage
                    actualDamage = 0;
                } else {
                    actualDamage = aRoll - dRoll - char1->getArmor();                    
                }
                
                // reduce defender's strength
                char1->reduceStrength(actualDamage);
                
            }
        } else if (firstAttacker == 2 && !char2->isDead()) { // if char2 is first attacker

            // roll the dice
            aRoll = char2->attack(); // attack roll
            dRoll = char1->defend(); // defend roll
            
            // calculate damage
            actualDamage = aRoll - dRoll - char1->getArmor();
            if(actualDamage <= 0) { // make sure no negative damage
                actualDamage = 0;
            } else {
                actualDamage = aRoll - dRoll - char1->getArmor();                    
            }
            
            // reduce defender's strength
            char1->reduceStrength(actualDamage);
            
            if(!char1->isDead()) { // make sure defender isn't already dead
                
                // roll the dice
                aRoll = char1->attack(); // attack roll
                dRoll = char2->defend(); // defend roll
                
                // calculate damage
                actualDamage = aRoll - dRoll - char2->getArmor();
                if(actualDamage <= 0) { // make sure no negative damage
                    actualDamage = 0;
                } else {
                    actualDamage = aRoll - dRoll - char2->getArmor();                    
                }
                
                // reduce defender's strength
                char2->reduceStrength(actualDamage);
                
            }
        }
        roundNo++;
    } while(!char1->isDead() && !char2->isDead());
    
    if(char1->isDead()) {
        cout << "\n" << char2->getName() << " killed " << char1->getName() << endl;
    } else if (char2->isDead()) {
        cout << "\n" << char1->getName() << " killed " << char2->getName() << endl;
    }
    
    // deallocate memory for character objects
    delete char2;
}

/*******************************************************************************
* Description: The default constructor initializes each member pointer to 
* nullptr.
*******************************************************************************/
Combat::Combat()
    : char1{nullptr}, char2{nullptr}{
}

/*******************************************************************************
* Description: The default destructor deletes objects created for the game.
*******************************************************************************/
Combat::~Combat() {
}