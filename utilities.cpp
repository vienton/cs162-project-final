/*******************************************************************************
* Program name: Utilities
* Author: Vien Ton
* Date: 11/19/2019
* Description: This implementation file contains contain utility function 
* definitions to validate inputs and generate random numbers.
*******************************************************************************/

#include "utilities.hpp"

/*******************************************************************************
* Description: The getIntInput function gets an integer input from cin, 
* validates, and returns it.
*******************************************************************************/
int getIntInput(){
    string tmp{};
    bool isInt = false;
    
    while(!isInt) {
        isInt = true;
        getline(cin, tmp);
        for(auto i : tmp) { // check for non-integers
            if(!isdigit(i)) {
                isInt = false;
            }
        }
        
        if(isInt == false) {
            cout << "Invalid integer input, try again: ";
        } else {
            try {
                stoi(tmp);
            } catch(...) {
                isInt = false;
                cout << "Invalid integer input, try again: "; 
            }
        }
    }
    
    // TODO: factor in cin.ignore() to ignore newline left by previous input
    
    return stoi(tmp);
}

/*******************************************************************************
* Description: The getCharInput function gets a string input from cin, checks 
* for non-alphanumeric more more than 1 characters, validates the character, and
* returns it.
*******************************************************************************/
char getCharInput(){
    string tmp{};
    
    cin >> tmp;
    
    while (!isalpha(tmp[0]) || tmp.size() > 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignore stream
        cout << "Invalid character input, try again: ";
        cin >> tmp;
    }
    tmp = tolower(tmp[0]);
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignore stream
    return tmp[0];
}

/*******************************************************************************
* Description: The getStringInput function gets a string from cin, validates it 
* for invalid characters, and returns it.
*******************************************************************************/
string getStringInput() {
    string tmp{};
    
    getline(cin, tmp);
    
    while(tmp.length() == 0) { // if user only hits enter without any input
        cout << "Invalid input, try again: ";
        getline(cin, tmp);
    }
    
    for(unsigned i = 0; i < tmp.length(); i++) {
        while (static_cast<int>(tmp[i]) < 32 && static_cast<int>(tmp[i]) > 126) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // ignore stream
            cout << "Invalid character in string, try again: ";
            getline(cin, tmp);
        }
    }
    return tmp;
}

/*******************************************************************************
* Description: The generateRandom function takes a two integers as arguments 
* and generate a trivial uniformly distributed random number between the minimum
* and maximum numbers, inclusive.
*******************************************************************************/
int generateRandom(int min, int max) {
    // srand(time(NULL)); // seed this only once in the program
    int result{};
    result = rand() % max + min;
    return result;
}