/*******************************************************************************
* Program name: Validate Input
* Author: Vien Ton
* Date: 10/27/2019
* Description: This specification file contains declarations for functions to 
* validate inputs and generate random numbers.
*******************************************************************************/

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <limits> // for numeric_limits
using std::numeric_limits;

#include <ios> // for streamsize
using std::streamsize;

#include <iostream>
using std::cout;
using std::cin;

#include <string>
using std::string;

#include <cctype> // for the isalpha() function
#include <ctime> // for the time() function

// get integer
int getIntInput();

// get character
char getCharInput();

// get string
string getStringInput();

// generate uniform random number between min and max
int generateRandom(int min, int max);

#endif