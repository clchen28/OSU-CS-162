#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"

int main()
{
    LoadedDie die(6);
    std::cout << die.rollDie() << std::endl;
    return 0;
}
