
#include "Game.h"
#include "raylib.h"

#include "Camera.h"
#include "Core.h"
#include "InputHandle.h"
#include "Player.h"

Game::Game() = default;
Game::~Game() = default;

bool Game::init() {
  if (Core::init()) {
    Player::init();
    InputHandle::init();
    CBCamera::init();
  }
  return true;
}

void Game::run() {
  BeginDrawing();
  EndDrawing();
}

void Game::exit() {
  CloseWindow();
  Player::del();
  Core::del();
  CBCamera::del();
}
