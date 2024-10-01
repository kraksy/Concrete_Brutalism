
#include "Core.h"
#include "raylib.h"

class CBCamera {
public:
  static Camera cam;
  static void init();
  static void del();
  static void move(Vector3 pos);

private:
  static void changeFOV();
  static void getPrevPos();
};
