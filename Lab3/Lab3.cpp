#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

int main()
{
    Game game(10,"loaded",6,"normal",6);
    game.playGame();
    return 0;
}
