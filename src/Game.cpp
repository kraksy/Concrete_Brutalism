
#include "Game.h"
#include "raylib.h"

#include "Camera.h"
#include "Core.h"
#include "InputHandle.h"
#include "ModelLoad.h"
#include "Player.h"

Game::Game() = default;
Game::~Game() = default;

// load all data
bool Game::init() {
  if (Core::init()) {
    static Model base = ModelLoad::load("resources/meshes/base.obj");
    Player::init();
    InputHandle::init();
    CBCamera::init();
  }
  return true;
}

// rendering operations
void Game::run() {
  BeginDrawing();
  EndDrawing();
}

// unload all data and exit
void Game::exit() {
  CloseWindow();
  Player::del();
  Core::del();
  CBCamera::del();
}
