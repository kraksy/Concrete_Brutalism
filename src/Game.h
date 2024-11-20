
#ifndef CB_GAME_H
#define CB_GAME_H

#pragma once

class Game
{
public:
    Game();
    ~Game() = default;
    void run();
    void end();
    void Update(); // game logic
    enum GameState
    {
        GAME,
        MENU,
        LOADING,
        SETTINGS,
    }State;
};

Game::Game()
= default;

void Game::run()
{
    
}

void Game::end()
{

}

void Game::Update() {

}

#endif // CB_GAME_H