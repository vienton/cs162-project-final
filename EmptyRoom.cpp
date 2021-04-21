/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class EmptyRoom. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include "EmptyRoom.hpp"

/*******************************************************************************
* Description: The special function implements the room's special action.
*******************************************************************************/
void EmptyRoom::special(Player* p) {
    cout << "\nYou are in an empty room" << endl;
    cout << "There is nothing here" << endl;
}

/*******************************************************************************
* Description: The default constructor sets the room type.
*******************************************************************************/
EmptyRoom::EmptyRoom() {
    setType("Empty");
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
EmptyRoom::~EmptyRoom(){
}