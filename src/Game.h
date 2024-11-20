
#ifndef CB_GAME_H
#define CB_GAME_H

#pragma once

#include "Core.h"

class Game
{
public:
    Game();
    ~Game();
    void run();
    void end();
    void Update(); // game logic
};

Game::Game()
{
}

Game::~Game()
{
}

void Game::run()
{
    
}

void Game::end()
{

}

#endif // CB_GAME_H