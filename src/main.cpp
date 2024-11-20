
#include <Core.h>
#include "Game.h"

int main()
{
    static int running;

    Game game;
    
    game.State = game.GAME;
    running = true;

    while(running)
    {
        switch (game.State)
        {
        case game.GAME:
            game.run();
            break;
        default:
            break;
        }
    }
    return 0;
}