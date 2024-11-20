
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
    InitWindow(1200, 1200, "CB");
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    CBCamera::init();
    Player::init();
    InputHandle::init();
    SetTargetFPS(60);
    DisableCursor();
    Render::init();
  }
  return true;
}

// rendering operations
void Game::run() {
  Render::startRendering();
  InputHandle::HandleInput();
}

// unload all data and exit
void Game::exit() {
  CloseWindow();
  Player::del();
  CBCamera::del();
}

static bool loadModels() {
  // load modells and textures
  // static Model base = ModelLoad::loadMesh('resources/meshes/base.obj');
  return false;
}
