
#include "Camera.h"
#include <raylib.h>

CBCamera::~CBCamera(){

};

CBCamera::CBCamera(vec3 pos, vec3 target, vec3 up, float fov,
                   CameraProjection projection) {
  CBCamera::pos = pos;
  CBCamera::target = target;
  CBCamera::up = up;
  CBCamera::fov = fov;
  CBCamera::projection = projection;
};

static void move(Vector3 pos) { CBCamera::cam.position = pos; }
static void changeFOV(float fov) { CBCamera::fov = fov; }
