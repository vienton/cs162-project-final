/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class RewardRoom. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "RewardRoom.hpp"

/*******************************************************************************
* Description: The special function implements the room's special action.
*******************************************************************************/
void RewardRoom::special(Player* p) {
    // create menu object
    int menuChoice{};
    Menu* rewardMenu = new Menu;
    rewardMenu->addItem("1. Save the reward");
    rewardMenu->addItem("2. Use the reward");
    rewardMenu->setInstruction("Type your selection: ");
    rewardMenu->setErrorMessage("Invalid input, try again: ");    
    
    // output room messages
    cout << "\nYou're in luck, there's a reward in this room!" << endl;
    cout << "The reward is ";
    
    // randomly generate reward
    int num = generateRandom(1, 3);
    switch(num) {
        case 1:
            cout << "Water" << endl;
            cout << "Water will increase your strength by 30 health points" << endl;
            break;
        case 2:
            cout << "a Sandwich" << endl;
            cout << "A sandwich will increase your strength by 20 health points" << endl;

            break;
        case 3:
            cout << "a Magic Pill" << endl;
            cout << "A Magic Pill will restore your strength completely" << endl;
            break;
        default:
            break;
    }
    
    // provide user's choice to save or use reward
    cout << "\nYou can save the reward or use it";
    do {
        rewardMenu->print();
        rewardMenu->printInstruction();
        menuChoice = getIntInput();
        while (menuChoice < 1 || menuChoice > 2) {
            rewardMenu->printErrorMessage();
            menuChoice = getIntInput();
        }
        switch(menuChoice) {
            case 1: // save reward
                switch(num) {
                    case 1:
                        p->saveReward("Water");
                        break;
                    case 2:
                        p->saveReward("Sandwich");
                        break;
                    case 3:
                        p->saveReward("Pill");
                        break;
                    default:
                        break;
                }
                break;
            case 2: // use reward
                switch(num) {
                    case 1:
                        p->addStrength(30); // consume water
                        cout << "You've recovered 30 health points" << endl;
                        break;
                    case 2:
                        p->addStrength(20); // consume sandwich
                        cout << "You've recovered 20 health points" << endl;
                        break;
                    case 3:
                        p->restoreStrength(); // consume pill
                        cout << "You've recovered all your health points" << endl;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    } while(menuChoice < 1 || menuChoice > 2);
    
    // deallocate memory
    delete rewardMenu;
}

/*******************************************************************************
* Description: The default constructor sets the room type.
*******************************************************************************/
RewardRoom::RewardRoom() {
    setType("Reward");
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
RewardRoom::~RewardRoom(){
}