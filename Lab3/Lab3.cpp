#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

int main()
{
    Game game(10,"loaded",2,"normal",2);
    game.playGame();
    return 0;
}
