
#include "Game.h"

int main()
{
    if (Game::init())
    {
        Game::run();
    }
    Game::exit();
    return 0;
}