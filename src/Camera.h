
#include "Core.h"
#include "raylib.h"

class CBCamera {
public:
  CBCamera() = default;
  CBCamera(CBCamera &&) = default;
  CBCamera(const CBCamera &) = default;
  CBCamera &operator=(CBCamera &&) = default;
  CBCamera &operator=(const CBCamera &) = default;
  ~CBCamera() = default;

  static Camera cam;
  static void init();
  static void del();
  static void move(Vector3 pos);

private:
  static void changeFOV();
  static void getPrevPos();
};
