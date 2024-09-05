//
// Created by kraks on 02/09/2024.
//

#include "Game.h"
#include "raylib.h"

#include "Core.h"

#include "Camera.h"
#include "InputHandle.h"

Game::Game() = default;
Game::~Game() = default;

bool Game::init() {
  Core::initCore();
  InputHandle::init();
  CBCamera::init();
  return true;
}

void Game::run() {
  BeginDrawing();
  EndDrawing();
}

void Game::exit() {
  CloseWindow();
  Core::delCore();
  CBCamera::del();
}
