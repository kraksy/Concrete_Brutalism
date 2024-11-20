
#include "Core.h"
#include "Game.h"

int main()
{
    static int running;

    Game game;


    running = true;

    while(running)
    {
        switch (game.State)
        {
        case Game::GAME:
            game.run();
            break;
        case Game::MENU:

            break;
        default:
            break;
        }
    }
    return 0;
}