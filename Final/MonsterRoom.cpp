/******************************************************************************
** Program name: MonsterRoom.cpp
** Author: Charles Chen
** Date: 03/14/2017
** Description:

******************************************************************************/

#include <iostream>
#include <random>
#include <string>
#include "Room.hpp"
#include "Player.hpp"
#include "MonsterRoom.hpp"

MonsterRoom::MonsterRoom() : Room()
{
    monsterDead = false;
}

MonsterRoom::MonsterRoom(Room* up, Room* down, Room* left,
    Room* right) : Room(up, down, left, right)
{
    monsterDead = false;
}

MonsterRoom::~MonsterRoom(){}

void MonsterRoom::printMenu(Player* player)
{
    std::cout << "There's a monster! " << std::endl;
    std::cout << "1. Try to dodge the monster - 50% chance " <<
        "of losing 50% of your health" << std::endl;
    std::cout << "2. Fight the monster with your fists - "
        << "monster will die, but you will lose 25% health" << std::endl;

    if (player->hasItem("Shotgun"))
    {
        std::cout << "3. Fire your shotgun! Monster will die, "
            << "but 50% chance "
            << "that you will lose 25% health" << std::endl;
    }
    else
    {
        std::cout << "3. No Shotgun" << std::endl;
    }

    if (player->hasItem("BFG 9000"))
    {
        std::cout << "4. Fire your BFG 9000! Monster will instantly "
            << "die" << std::endl;
    }
    else
    {
        std::cout << "4. No BFG 9000" << std::endl;
    }
}

void MonsterRoom::doSpecial(Player* player)
{
    if (monsterDead)
    {
        std::cout << "Monster is dead" << std::endl;
        return;
    }

    std::string userInput = "";
    bool attackDone = false;

    while (!attackDone)
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        printMenu(player);
        std::getline(std::cin, userInput);
        if (userInput == "1")
        {
            std::cout << "Trying to dodge..." << std::endl;
            if (randNum(2) == 2)
            {
                std::cout << "Success! You've dodged the monster" << std::endl;
            }
            else
            {
                std::cout << "You were hit!" << std::endl;
                player->removeHealth(50);
                std::cout << "Your health is now " << player->getHealth()
                    << std::endl;
            }
            attackDone = true;
        }
        else if (userInput == "2")
        {
            std::cout << "Fighting the monster with your fists..." << std::endl;
            player->removeHealth(25);
            std::cout << "Your health is now " << player->getHealth()
                << std::endl;
            monsterDead = true;
            attackDone = true;
        }
        else if (userInput == "3")
        {
            if (player->hasItem("Shotgun"))
            {
                std::cout << "Attacking with shotgun..." << std::endl;
                if (randNum(2) == 2)
                {
                    std::cout << "You were hit!" << std::endl;
                    player->removeHealth(25);
                    std::cout << "Your health is now " << player->getHealth()
                        << std::endl;
                }
                else
                {
                    std::cout << "You weren't hit!" << std::endl;
                }
                std::cout << "Monster is dead" << std::endl;
                monsterDead = true;
                attackDone = true;
            }
            else
            {
                std::cout << "You don't have a shotgun" << std::endl;
            }
        }
        else if (userInput == "4")
        {
            if (player->hasItem("BFG 9000"))
            {
                std::cout << "Attacking with BFG 9000" << std::endl;
                std::cout << "Monster is dead!" << std::endl;
                monsterDead = true;
                attackDone = true;
            }
            else
            {
                std::cout << "You don't have a BFG 9000" << std::endl;
            }
        }
    }

}

std::string MonsterRoom::getType()
{
    if (monsterDead)
    {
        return "MonsterDead";
    }
    else
    {
        return "Monster";
    }
}

/*
randNum(int n)
randNum takes in a number n of integers, and will return a random integer
between 1 and n, inclusive.
*/
int MonsterRoom::randNum(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,n);
    return dist(gen);
}
