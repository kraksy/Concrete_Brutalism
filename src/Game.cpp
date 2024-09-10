
#include "Game.h"
#include "raylib.h"

#include "Camera.h"
#include "Core.h"
#include "InputHandle.h"
#include "ModelLoad.h"
#include "Player.h"
#include "Render.h"

Game::Game() = default;
Game::~Game() = default;

// load all data
bool Game::init() {
  if (Core::init()) {
    static Model base = ModelLoad::loadMesh("resources/meshes/base.obj  ");
    static Model button = ModelLoad::loadMesh("resources/meshes/testing.obj");
    Player::init();
    InputHandle::init();
    CBCamera::init();
    Render::init();
  }
  return true;
}

// rendering operations
void Game::run() { Render::startRendering(); }

// unload all data and exit
void Game::exit() {
  CloseWindow();
  Player::del();
  Core::del();
  CBCamera::del();
}
