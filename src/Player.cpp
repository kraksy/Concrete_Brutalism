
#include "Player.h"
#include "Core.h"
#include <raylib.h>

static void init() { Core::Player::hp = 30; }

static Vector3 getPos() { return Core::Player::pos; }
