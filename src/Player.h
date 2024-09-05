
#include "Core.h"
#include "raylib.h"

class Player {
public:
  Player();
  Player(Player &&) = default;
  Player(const Player &) = default;
  Player &operator=(Player &&) = default;
  Player &operator=(const Player &) = default;
  ~Player();

  static void init();
  static void del();

private:
  static Vector3 getPos();
};
