/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class KeyRoom. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "KeyRoom.hpp"

/*******************************************************************************
* Description: The special function implements the room's special action.
*******************************************************************************/
void KeyRoom::special(Player* p) {
    int menuChoice{};
    Menu* keyMenu = new Menu;
    keyMenu->addItem("1. Save key");
    keyMenu->addItem("2. Nah, forget it");
    keyMenu->setInstruction("Type your selection: ");
    keyMenu->setErrorMessage("Invalid input, try again: ");

    // output room messages
    cout << "\nNice job, you have found the key!" << endl;
    cout << "The key will open the exit door, but the door is not here" << endl;
    cout << "\nWould you like to save the key?";
    
    // get user input and execute choice
    do {
        keyMenu->print();
        keyMenu->printInstruction();
        menuChoice = getIntInput();
        while (menuChoice < 1 || menuChoice > 2) {
            keyMenu->printErrorMessage();
            menuChoice = getIntInput();
        }
        switch(menuChoice) {
            case 1: 
                p->saveKey();
                break;
            case 2:
                break;
            default:
                break;
        }
    } while(menuChoice < 1 || menuChoice > 2);
    
    // deallocate memory
    delete keyMenu;
}

/*******************************************************************************
* Description: The default constructor sets the room type.
*******************************************************************************/
KeyRoom::KeyRoom() {
    setType("Key");
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
KeyRoom::~KeyRoom(){
}