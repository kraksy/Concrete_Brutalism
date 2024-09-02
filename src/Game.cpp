//
// Created by kraks on 02/09/2024.
//

#include "raylib.h"
#include "Game.h"

#include "Core.h"

Game::Game() = default;
Game::~Game() = default;

bool Game::init() {
    Core::GameConfig::ScreenHeight = 1200;
    Core::GameConfig::ScreenWidth = 1200;
    return true;
}

void Game::run() {

}

void Game::exit() {
    CloseWindow();
}





