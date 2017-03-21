/******************************************************************************
** Program name: Game.cpp
** Author: Charles Chen
** Date: 03/13/2017
** Description:
Implementation of Game class.
******************************************************************************/

#include "Game.hpp"
#include "Room.hpp"
#include "ItemRoom.hpp"
#include "Player.hpp"
#include "MonsterRoom.hpp"
#include "ExitRoom.hpp"
#include <iostream>
#include <set>
#include <string>
#include <functional>
#include "inputValidator.hpp"

/*
Game()
Default constructor sets up attributes and initializes the starting location
of Rooms, as well as sets up special rooms.
*/
Game::Game()
{
    moves = 0;

    startRoom = new ItemRoom;
    Room* tempRoom1 = startRoom;
    Room* tempRoom2 = nullptr;
    Room* tempRoom3 = nullptr;
    Room* tempRoom4 = nullptr;

    // roomRow1-4 point to the Room in the first column for each row of Rooms
    roomRow1 = startRoom;
    roomRow2 = nullptr;
    roomRow3 = nullptr;
    roomRow4 = nullptr;

    // Sets up the first row of empty ItemRooms
    for (int i = 0; i < 4; i++)
    {
        tempRoom1->setRight(new ItemRoom);
        tempRoom1->getRight()->setLeft(tempRoom1);
        tempRoom1 = tempRoom1->getRight();
    }

    // Sets up the second row of empty ItemRooms
    tempRoom1 = roomRow1;
    roomRow2 = new ItemRoom;
    roomRow2->setUp(roomRow1);
    roomRow1->setDown(roomRow2);
    tempRoom2 = roomRow2;
    for (int i = 0; i < 4; i++)
    {
        tempRoom2->setRight(new ItemRoom);
        tempRoom2->getRight()->setLeft(tempRoom2);
        tempRoom2->getRight()->setUp(tempRoom1->getRight());
        tempRoom1->getRight()->setDown(tempRoom2->getRight());
        tempRoom1 = tempRoom1->getRight();
        tempRoom2 = tempRoom2->getRight();
    }

    // Sets up the third row of empty ItemRooms
    tempRoom2 = roomRow2;
    roomRow3 = new ItemRoom;
    roomRow3->setUp(roomRow2);
    roomRow2->setDown(roomRow3);
    tempRoom3 = roomRow3;
    for (int i = 0; i < 4; i++)
    {
        tempRoom3->setRight(new ItemRoom);
        tempRoom3->getRight()->setLeft(tempRoom3);
        tempRoom3->getRight()->setUp(tempRoom2->getRight());
        tempRoom2->getRight()->setDown(tempRoom3->getRight());
        tempRoom2 = tempRoom2->getRight();
        tempRoom3 = tempRoom3->getRight();
    }

    // Sets up the fourth row of empty ItemRooms
    tempRoom3 = roomRow3;
    roomRow4 = new ItemRoom;
    roomRow4->setUp(roomRow3);
    roomRow3->setDown(roomRow4);
    tempRoom4 = roomRow4;
    for (int i = 0; i < 4; i++)
    {
        tempRoom4->setRight(new ItemRoom);
        tempRoom4->getRight()->setLeft(tempRoom4);
        tempRoom4->getRight()->setUp(tempRoom3->getRight());
        tempRoom3->getRight()->setDown(tempRoom4->getRight());
        tempRoom3 = tempRoom3->getRight();
        tempRoom4 = tempRoom4->getRight();
    }

    // Sets up a MonsterRoom in the 2nd row, 3rd column
    Room* tempRoom = nullptr;
    Room* newRoom = nullptr;
    tempRoom = roomRow2->getRight()->getRight();
    newRoom = new MonsterRoom(tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getLeft()->setRight(newRoom);
    newRoom->getDown()->setUp(newRoom);
    delete tempRoom;

    // Sets up a MonsterRoom in the 4th row, 2nd column
    tempRoom = nullptr;
    newRoom = nullptr;
    tempRoom = roomRow4->getRight();
    newRoom = new MonsterRoom(tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getLeft()->setRight(newRoom);
    delete tempRoom;

    // Sets up an ExitRoom in the 4th row, 3rd column
    tempRoom = nullptr;
    newRoom = nullptr;
    tempRoom = roomRow4->getRight()->getRight();
    newRoom = new ExitRoom(tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getLeft()->setRight(newRoom);
    delete tempRoom;

    // Adds a Key to the Room in the 2nd row, 4th column
    tempRoom = nullptr;
    newRoom = nullptr;
    tempRoom = roomRow2->getRight()->getRight()->getRight();
    newRoom = new ItemRoom("Key", tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getLeft()->setRight(newRoom);
    newRoom->getDown()->setUp(newRoom);
    delete tempRoom;

    // Adds a BFG 9000 to the ROom in the 3rd row, 1st column
    tempRoom = nullptr;
    newRoom = nullptr;
    tempRoom = roomRow3;
    newRoom = new ItemRoom("BFG 9000", tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getDown()->setUp(newRoom);
    roomRow3 = newRoom;
    delete tempRoom;

    // Adds a Shotgun to the room in the 3rd row, 4th column
    tempRoom = nullptr;
    newRoom = nullptr;
    tempRoom = roomRow3->getRight()->getRight()->getRight();
    newRoom = new ItemRoom("Shotgun", tempRoom->getUp(), tempRoom->getDown(),
        tempRoom->getLeft(), tempRoom->getRight());
    newRoom->getRight()->setLeft(newRoom);
    newRoom->getUp()->setDown(newRoom);
    newRoom->getLeft()->setRight(newRoom);
    newRoom->getDown()->setUp(newRoom);
    delete tempRoom;

    // Starts the player at the Room in the first row/column
    player = new Player(roomRow1);
}

/*
~Game()
Destructor deallocates memory for each Room.
*/
Game::~Game()
{
    Room* tempRoom1 = roomRow1;
    Room* tempRoom2 = roomRow2;
    Room* tempRoom3 = roomRow3;
    Room* tempRoom4 = roomRow4;

    // When the tempRoom pointer reaches an edge, it will reach a nullptr
    while (tempRoom1->getRight() != nullptr)
    {
        tempRoom1 = tempRoom1->getRight();
        delete tempRoom1->getLeft();
    }
    delete tempRoom1;

    while (tempRoom2->getRight() != nullptr)
    {
        tempRoom2 = tempRoom2->getRight();
        delete tempRoom2->getLeft();
    }
    delete tempRoom2;

    while (tempRoom3->getRight() != nullptr)
    {
        tempRoom3 = tempRoom3->getRight();
        delete tempRoom3->getLeft();
    }
    delete tempRoom3;

    while (tempRoom4->getRight() != nullptr)
    {
        tempRoom4 = tempRoom4->getRight();
        delete tempRoom4->getLeft();
    }
    delete tempRoom4;

    delete player;
}

/*
printRow(Room* row)
This method will print a character corresponding to the status of a Room for
each Room for a given row.
*/
void Game::printRow(Room* row)
{
    Room* tempRoom = row;
    while (tempRoom != nullptr)
    {
        if (tempRoom->getType() == "Exit" && tempRoom->isFound())
        {
            std::cout << "E";
        }
        else if (player->getPlayerPosition() == tempRoom)
        {
            std::cout << "P";
        }
        else if (!tempRoom->isFound())
        {
            std::cout << "X";
        }
        else if (player->getPlayerPosition() == tempRoom)
        {
            std::cout << "P";
        }
        else if (tempRoom->getType() == "Item")
        {
            std::cout << "I";
        }
        else if (tempRoom->getType() == "Empty")
        {
            std::cout << "O";
        }
        else if (tempRoom->getType() == "Monster")
        {
            std::cout << "M";
        }
        else if (tempRoom->getType() == "MonsterDead")
        {
            std::cout << "D";
        }
        tempRoom = tempRoom->getRight();
    }
    std::cout << std::endl;
}

/*
printMap()
printMap prints a map of the game board. It uses the printRow method to print
a character to represent each Room on the board.
*/
void Game::printMap()
{
    std::cout << "Map: P is your location, X is unknown, ";
    std::cout << "O is an empty room, M has a monster, " << std::endl;
    std::cout << "E is the exit, I has items" << std::endl;

    printRow(roomRow1);
    printRow(roomRow2);
    printRow(roomRow3);
    printRow(roomRow4);
}

/*
playGame()
playGame() will play through the game until the player wins, dies, or runs out
of time.
*/
void Game::playGame()
{
    // Used for user input and validation
    std::string userInput = "";
    auto allowedDirections = [](std::string input) -> bool
            {
                return (input == "up")
                    || (input == "down")
                    || (input == "left")
                    || (input == "right")
                    || (input == "Up")
                    || (input == "Down")
                    || (input == "Left")
                    || (input == "Right");
            };

    Room* nextRoom = nullptr;
    bool gameOver = false;

    while (!gameOver)
    {
        // At the start of every round, will print the map
        printMap();

        // Will perform the special function of the current Room that the Player
        // is in
        player->getPlayerPosition()->doSpecial(player);

        // End the game if the player has reached the exit
        if (player->getReachedExit())
        {
            gameOver = true;
            std::cout << "You've reached the exit!" << std::endl;
            printMap();
        }

        // End the game if the player is dead
        else if (player->isDead())
        {
            gameOver = true;
            std::cout << "You died!" << std::endl;
        }

        // End the game if the player has taken more than 20 moves
        else if (moves > 20)
        {
            std::cout << "You took too long! Game over." << std::endl;
            gameOver = true;
        }

        // Otherwise move the player to a new room
        while ((nextRoom == nullptr) && (!gameOver))
        {
            inputValidator(userInput, allowedDirections,
                "Which room do you want to enter? [up/down/left/right]",
                "Invalid input");
            if (userInput == "Up" || userInput == "up")
            {
                nextRoom = player->getPlayerPosition()->getUp();
            }
            if (userInput == "Down" || userInput == "down")
            {
                nextRoom = player->getPlayerPosition()->getDown();
            }
            if (userInput == "Left" || userInput == "left")
            {
                nextRoom = player->getPlayerPosition()->getLeft();
            }
            if (userInput == "Right" || userInput == "right")
            {
                nextRoom = player->getPlayerPosition()->getRight();
            }
            player->movePlayer(nextRoom);
        }
        
        moves++;
        nextRoom = nullptr;
    }
}
