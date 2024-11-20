
#include "Player.h"

static bool init() {
  Player::player::hp = 30;
  return true;
}

static void del(Player::player *player) { delete (player); }

static Vector3 getPos() { return Player::player::pos; }
