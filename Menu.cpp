/*******************************************************************************
* Program name: Menu
* Author: Vien Ton
* Date: 10/30/2019
* Description: This implementation file contains member function definitions for 
* the class Menu. For more details of the functions, read their descriptions.
*******************************************************************************/

#include "Menu.hpp"

/*******************************************************************************
* Description: The print function prints out menu item strings in the list.
*******************************************************************************/
void Menu::print(){
    std::cout << outputMessage << std::endl;
    for (string s : list){
        std::cout << s << std::endl;
    }
}

/*******************************************************************************
* Description: The setOutputMessage function takes a string as an argument and 
* sets it as the top output message for the menu.
*******************************************************************************/
void Menu::setOutputMessage(string s){
    outputMessage = s;
}

/*******************************************************************************
* Description: The printOutputMessage function prints the outputMessage string.
*******************************************************************************/
void Menu::printOutputMessage(){
    cout << outputMessage;
}

/*******************************************************************************
* Description: The setInstruction function takes a string as an argument and 
* sets it as the instruction for the menu.
*******************************************************************************/
void Menu::setInstruction(string s){
    instruction = s;
}

/*******************************************************************************
* Description: The printInstruction function prints the instruction string.
*******************************************************************************/
void Menu::printInstruction(){
    cout << instruction;
}

/*******************************************************************************
* Description: The errorMessage function takes a string as an argument and sets 
* it as the invalid input message for the menu.
*******************************************************************************/
void Menu::setErrorMessage(string s){
    errorMessage = s;
}

/*******************************************************************************
* Description: The printErrorMessage function prints the errorMessage string.
*******************************************************************************/
void Menu::printErrorMessage(){
    cout << errorMessage;
}

/*******************************************************************************
* Description: The addItem function takes a string as an argument and adds it
* to the member vector variable list.
*******************************************************************************/
void Menu::addItem(string s){
    list.push_back(s);
}

/*******************************************************************************
* Description: The getIntInput function gets an integer input, validates, and 
* returns it.
*******************************************************************************/
int Menu::getIntInput(){
    string temp{};
    bool isInt{};
    
    do {
        isInt = true;
        getline(cin, temp);
        for(auto i : temp) {
            if(!isdigit(i)){ // check for non-integer
                isInt = false;
            }
        }
        
        if(isInt == false) {
            cout << "Invalid input, try again: ";
        }
    } while(!isInt);
    
    return stoi(temp);
}

/*******************************************************************************
* Description: The default constructor initializes the member variables to 
* empty.
*******************************************************************************/
Menu::Menu() 
    : outputMessage{}, instruction{}, errorMessage{}, list{}, intInput{} {
}

/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Menu::~Menu(){
}

