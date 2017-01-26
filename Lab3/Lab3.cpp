#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

int main()
{
    Game game(10,"normal",8,"loaded",6);
    game.playGame();
    return 0;
}
