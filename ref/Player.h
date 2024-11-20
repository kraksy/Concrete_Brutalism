
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

  struct player {
    static double hp;
    static Vector3 pos;
    static Vector3 velocity;
    static float height;
    static bool isGrounded;

    static Model model;
    static Texture2D texture;
  };

  static void init();
  static void del();

private:
  static Vector3 getPos();
};
