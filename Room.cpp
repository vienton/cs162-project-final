/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class Room. Read the function descriptions below to learn more about 
* them. The class also has a constructor and destructor.
*******************************************************************************/

#include "Room.hpp"

/*******************************************************************************
* Description: The setType function accepts a string parameter and sets that as 
* the room type.
*******************************************************************************/
void Room::setType(string t) {
    type = t;
}

/*******************************************************************************
* Description: The getExit function returns the exit status of the room.
*******************************************************************************/
bool Room::getExit() {
    return exit;
}

/*******************************************************************************
* Description: The default constructor initializes the member variables to 
* empty.
*******************************************************************************/
Room::Room() 
    : up{nullptr}, down{nullptr}, left{nullptr}, right{nullptr}, type{}, 
      exit{false}, p{} {
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Room::~Room(){
}