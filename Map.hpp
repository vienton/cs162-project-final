/*******************************************************************************
* Program name: Program
* Author: Vien Ton
* Date: mm/dd/yyyy
* Description: This specification file defines the class Room. The member 
* variables are var1, var2, and var3. The private functions func1 does something. 
* The function func2 does something.  The constructor takes three arguments, 
* arg1, arg2, and arg3. It then initializes a Room object with those arguments. 
* The class also contains a destructor.
*******************************************************************************/

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
using std::vector;

#include "Room.hpp"
#include "BadGuyRoom.hpp"
#include "EmptyRoom.hpp"
#include "ExitRoom.hpp"
#include "KeyRoom.hpp"
#include "RewardRoom.hpp"

#define MAP_SIZE 3 // map dimension

class PlayMap {
private:
    // vector to hold keys to the map
    vector<vector<char>> key;
    // vector to hold the map
    vector<vector<Room*>> map;
public:
    void initializeRooms(); // initialize the map with rooms
    void linkRooms(); // link the rooms together
    PlayMap();
    ~PlayMap();
};

#endif // MAP_HPP
