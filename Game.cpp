/*******************************************************************************
* Program name: Final Project
* Author: Vien Ton
* Date: 12/08/2019
* Description: This implementation file contains member function definitions 
* for the class Game. Read the function descriptions below to learn more about 
* them. The class also has a constructor and destructor.
*******************************************************************************/

#include "Game.hpp"

/*******************************************************************************
* Description: The endMenu function displays a menu at the end of the game and 
* returns true if the user wants to play again, and false if not.
*******************************************************************************/
bool Game::endMenu() {
    // create end menu object
    endGame = new Menu;
    endGame->addItem("1. Play again");
    endGame->addItem("2. Exit");
    endGame->setInstruction("Type your selection: ");
    endGame->setErrorMessage("Invalid input, try again: ");
    
    int menuChoice{};
    do {
        endGame->setOutputMessage("\nWould you like to play again?");
        endGame->print();
        endGame->printInstruction();
        menuChoice = getIntInput();       
        while (menuChoice < 1 || menuChoice > 2) {
            endGame->printErrorMessage();
            menuChoice = getIntInput();
        }
        if(menuChoice == 1) {
            delete endGame;
            return true;
        } else {
            delete endGame;
            return false;
        }
    } while(menuChoice < 1 || menuChoice > 2);
}

/*******************************************************************************
* Description: The initializeRooms function parses through the key vector and 
* instantiates a room based on the key value.
* Adated from: https://piazza.com/class/k0rofchnorj31s?cid=683
*******************************************************************************/
void Game::initializeRooms() {
    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            char temp = key[i][j];
            switch(temp) {
                case ' ': // empty room
                    board[i][j] = new EmptyRoom;
                    break;
                case 'b': // room with bad guy
                    board[i][j] = new BadGuyRoom;
                    break;
                case 'e': // room with exit
                    board[i][j] = new ExitRoom;
                    break;
                case 'k': // room with key
                    board[i][j] = new KeyRoom;
                    break;
                case 'r': // room with reward
                    board[i][j] = new RewardRoom;
                    break;
                default:
                    break;
            }
        }
    }
}

/*******************************************************************************
* Description: The function linkRooms links the board together via pointers.
* Adapted from: https://piazza.com/class/k0rofchnorj31s?cid=683
*******************************************************************************/
void Game::linkRooms() {
    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            // get potential locations of next board
            int up = i - 1;
            int down = i + 1;
            int left = j - 1;
            int right = j + 1;
            
            // deal with wraparound
            if(up < 0) {
                up = DIMENSION - 1;
            }
            
            if(down >= DIMENSION) {
                down = 0;
            }
            
            if(left < 0) {
                left = DIMENSION - 1;
            }
            
            if(right >= DIMENSION) {
                right = 0;
            }
            
            // connect the rooms on the board
            Room* temp = board[i][j];
            temp->up = board[up][j];
            temp->down = board[down][j];
            temp->left = board[i][left];
            temp->right = board[i][right];
        }
    }
}

/*******************************************************************************
* Description: The function printBoard prints out the board with the player's 
* current location
*******************************************************************************/
void Game::printBoard() {
    cout << "\nBasement layout and your location [x]:" << endl;
    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            if(i == xPos && j == yPos) {
                cout << "[x]";
            } else {
                cout << "[ ]";                
            }
        }
        cout << endl;
    }
}

/*******************************************************************************
* Description: The play function simulates the game.
*******************************************************************************/
void Game::play() {
    // instantiate game menu
    playMenu = new Menu;
    playMenu->addItem("e. Move up");
    playMenu->addItem("d. Move down");
    playMenu->addItem("s. Move left");
    playMenu->addItem("f. Move right");
    playMenu->setInstruction("Type your selection: ");
    playMenu->setErrorMessage("Invalid input, try again: ");
    char menuChoice{};    
    
    // instantiate objects
    player = new Player;
    
    // initialize and link rooms
    initializeRooms();
    linkRooms();
    
    // initialize game parameters
    xPos = yPos = 0;
    current = board[0][0];
    bool gameWon = false;
    int playerStrength = player->getStrength();
    
    // print game info
    cout << "\n##### Welcome to the Basement of Eternal Pain! #####" << endl;
    cout << endl;
    cout << "1. You are trapped in the basement of an evil building." << endl;
    cout << "2. In here, the rooms just go round and round, endlessly." << endl;
    cout << "3. To win, find the exit door, open it, and exit, before you're dead." << endl;
    cout << "4. But, you cannot open the exit door without the key." << endl;
    cout << "5. You may find the key in one of the rooms." << endl;
    cout << "6. Be careful, there may be a bad guy in each room, or a reward." << endl;
    cout << "7. A reward will benefit you; and a battle with a bad guy will damage you, or kill you." << endl;
    cout << "8. Watch out for the Blue Men! These little guys will almost always kill you." << endl;
    cout << "9. If you encounter a reward item, you may save it in your satchel for later, or use it right then." << endl;
    cout << "10. You may save only 1 reward item in your satchel at a time, and never know when you may need it." << endl;
    cout << "11. The key doesn't count as an item because it doesn't take up much space in your satchel." << endl;
    cout << "12. With each move to a new room, your strength is reduced by 10 points." << endl;
    cout << "13. You will die when your strength is below 0." << endl;
    cout << "\n##### Enough about rules, let the pain begin! #####" << endl;

    // simulate the game
    while(playerStrength > 0 && !gameWon) {
        
        // print player's health status
        playerStrength = player->getStrength();
        cout << "\nYour starting strength: " << playerStrength << endl;

        // print content of player's satchel
        player->useReward();
                
        // execute special function
        current->special(player);
        playerStrength = player->getStrength();
        gameWon = current->getExit();

        // print out the board
        if(playerStrength > 0 && !gameWon) {
            printBoard();
            playMenu->setOutputMessage("\nWhere would you like to go next?");
            playMenu->print();
            playMenu->printInstruction();
            menuChoice = getCharInput();       
            
            // get user's choice
            while (menuChoice != 'e' && 
                   menuChoice != 'd' && 
                   menuChoice != 's' && 
                   menuChoice != 'f' &&
                   menuChoice == ' ') {
                playMenu->printErrorMessage();
                menuChoice = getCharInput();
            }
            
            // move player to new room
            switch(menuChoice) {
                case 'e':
                    current = current->up;
                    if(xPos - 1 < 0) { // wrap around
                        xPos = DIMENSION - 1;
                    } else {
                        xPos--;
                    }
                    break;
                case 'd':
                    current = current->down;
                    if(xPos + 1 == DIMENSION) {
                        xPos = 0;
                    } else {
                        xPos++;
                    }
                    break;
                case 's':
                    current = current->left;
                    if(yPos - 1 < 0) {
                        yPos = DIMENSION - 1;
                    } else {
                        yPos--;
                    }
                    break;
                case 'f':
                    if(yPos + 1 == DIMENSION) {
                        yPos = 0;
                    } else {
                        yPos++;
                    }
                    current = current->right;
                    break;
                default:
                    break;
            }
        }
                        
        // reduce player's strength
        player->reduceStrength(10);
        playerStrength = player->getStrength();

        // print out updated strength
        cout << "\nYour remaining strength: " << playerStrength << endl;
        
        // print divider
        cout << "\n------- ===== ### ===== -------" << endl;
    
        // get exit status
        gameWon = current->getExit();
    }
    
    // get exit status from the room
    if(gameWon) {
        cout << "\n>>>>> Congratulations, you've won! <<<<<" << endl;
    } else {
        cout << "\n>>>>> You died before being able to exit. You've lost! <<<<<" << endl;
    }
    
    // reset board position
    current = board[0][0];
    
    // free up memory
    // delete rooms on the board
    for(int i = 0; i < DIMENSION; i++) {
        for(int j = 0; j < DIMENSION; j++) {
            delete board[i][j];
        }
    }
    // delete player
    delete player;
    
    // delete play menu
    delete playMenu;
}

/*******************************************************************************
* Description: The default constructor initializes the member variables default 
* values.
*******************************************************************************/
Game::Game()
    :   xPos{}, yPos{}, gameOver{false}, 
        board(DIMENSION, vector<Room*>(DIMENSION, nullptr)), 
        endGame{nullptr}, playMenu{nullptr}, player{nullptr}, current{nullptr} {
    
    // initialize keys
    // ' ': empty room
    // 'b': bad guy room
    // 'e': exit room
    // 'k': key room
    // 'r': reward room
    // TODO: make the game more difficult by randomizing room type
    key = {
        {' ', 'r', 'b'},
        {'b', 'k', 'r'},
        {'r', 'b', 'e'},
    };
}


/*******************************************************************************
* Description: This is the default destructor.
*******************************************************************************/
Game::~Game() {
}

