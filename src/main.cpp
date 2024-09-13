
#include "Game.h"

int main() {
  if (Game::init()) {
    Game::loadModels();
    Game::run();
  }
  Game::exit();
  return 0;
}
