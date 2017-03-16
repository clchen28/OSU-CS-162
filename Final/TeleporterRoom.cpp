/******************************************************************************
** Program name: TeleporterRoom.cpp
** Author: Charles Chen
** Date: 03/13/2017
** Description:

******************************************************************************/

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Room.hpp"
#include "TeleporterRoom.hpp"

TeleporterRoom::TeleporterRoom() : Room(){}

TeleporterRoom::TeleporterRoom(Room* destination) : Room()
{
    this->destination = destination;
}

TeleporterRoom::TeleporterRoom(Room* up, Room* down, Room* left, Room* right) :
    Room(up, down, left, right){}

TeleporterRoom::TeleporterRoom(Room* destination, Room* up, Room* down,
    Room* left, Room* right) : Room(up, down, left, right)
{
    this->destination = destination;
}

TeleporterRoom::~TeleporterRoom(){}

void TeleporterRoom::printMenu()
{
    std::cout << "This room has a teleporter." << std::endl;
    std::cout << "1. Use teleporter" << std::endl;
    std::cout << "2. Leave room" << std::endl;
}

void TeleporterRoom::doSpecial(Player* player)
{
    found = true;
    std::string userInput = "";
    int selection = -1;

    while (selection != 2)
    {
        printMenu();
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');

        // Selects submenu item
        switch (selection)
        {
            case 1:
                player->movePlayer(destination);
                std::cout << "Teleported to new location" << std::endl;
                selection = 2;
            break;

            case 2:
            break;

            default:
            std::cout << "Enter a valid menu item (1 or 2)";
            std::cout << std::endl;
        }
    }
}

std::string TeleporterRoom::getType()
{
    return "Teleporter";
}
