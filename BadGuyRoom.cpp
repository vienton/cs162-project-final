/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class BadGuyRoom. Read the function descriptions below to learn more 
* about them. The class also has a constructor and destructor.
*******************************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "BadGuyRoom.hpp"

/*******************************************************************************
* Description: The special function implements the room's special action.
*******************************************************************************/
void BadGuyRoom::special(Player* p) {
    // implement the special action
    cout << "\nYikes! There's a bad guy in this room" << endl;
    
    // simulate battle
    Combat* battle = new Combat;
    battle->play(p);
    delete battle;
}

/*******************************************************************************
* Description: The default constructor sets the room type.
*******************************************************************************/
BadGuyRoom::BadGuyRoom() {
    setType("BadGuy");
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
BadGuyRoom::~BadGuyRoom(){
}