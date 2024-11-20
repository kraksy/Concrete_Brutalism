
#include "Core.h"
#include "raylib.h"

using vec3 = Vector3;

class CBCamera {
public:
  static vec3 pos;
  static vec3 target;
  static vec3 up;
  static float fov;
  static CameraProjection projection;

  CBCamera(vec3 pos, vec3 target, vec3 up, float fov,
           CameraProjection projection);
  ~CBCamera();

  static Camera cam;

private:
  static void move(Vector3 pos);
  static void changeFOV(float fov);
};
