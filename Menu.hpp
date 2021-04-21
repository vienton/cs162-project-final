/*********************************************************************
* Program name: Menu
* Author: Vien Ton
* Date: 10/30/2019
** Description: This specification file defines the class Menu. The
** member variables are list, charChoice, and intChoice. The function
** print prints the Menu object, and addItem adds an item to the list.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Menu {
private:
    string outputMessage;
    string instruction;
    string errorMessage;
    std::vector<string> list;
    int intInput;

public:
    // print menu list
    void print();
    
    // outputMessage setter/printer
    void setOutputMessage(string s);
    void printOutputMessage();
    
    // instruction setter/printer
    void setInstruction(string s);
    void printInstruction();
    
    // invalidInput setter/printer
    void setErrorMessage(string s);
    void printErrorMessage();

    // add item to menu list
    void addItem(string s);

    // get inputs
    int getIntInput();
    // TODO: char getCharInput();

    // constructor and destructor
    Menu();
    Menu(string s);
    ~Menu();
};

#endif //MENU_HPP