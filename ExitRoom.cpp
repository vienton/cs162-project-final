/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class ExitRoom. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "ExitRoom.hpp"

/*******************************************************************************
* Description: The special function implements the room's special action.
*******************************************************************************/
void ExitRoom::special(Player* p) {
    // create menu object
    int menuChoice{};
    Menu* exitMenu = new Menu;
    exitMenu->addItem("1. Unlock door");
    exitMenu->addItem("2. Do nothing");
    exitMenu->setInstruction("Type your selection: ");
    exitMenu->setErrorMessage("Invalid input, try again: ");    

    // output room messages
    cout << "\nYou've found the room with the exit!" << endl;
    cout << "You may unlock the door and exit if you have the key" << endl;
    cout << "\nDo you want to try to unlock the door?";
    
    // implement exit action
    do {
        exitMenu->print();
        exitMenu->printInstruction();
        menuChoice = getIntInput();
        while (menuChoice < 1 || menuChoice > 2) {
            exitMenu->printErrorMessage();
            menuChoice = getIntInput();
        }
        switch(menuChoice) {
            case 1:
                if(p->getKey()) { // unlock door
                    cout << "\nYou have successfully unlocked the door" << endl;
                    exit = true;
                    break;
                } else { // cannot unlock door
                    cout << "\nYou cannot unlock the door without the key" << endl;
                    break;
                }
            case 2:
                break;
            default:
                break;
        }        
    } while(menuChoice < 1 || menuChoice > 2);

    // deallocate memory
    delete exitMenu;
}

/*******************************************************************************
* Description: The default constructor sets the exit varible to false and the 
* room type.
*******************************************************************************/
ExitRoom::ExitRoom() {
    exit = false;
    setType("Exit");
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
ExitRoom::~ExitRoom(){
}