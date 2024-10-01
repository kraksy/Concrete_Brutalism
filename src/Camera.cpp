
#include "Camera.h"
#include <raylib.h>

Camera CBCamera::cam;

void init() {
  CBCamera::cam.position = (Vector3){0.0f, 0.0f, 0.0f};
  CBCamera::cam.target = (Vector3){0.0f, 0.0f, 0.0f};
  CBCamera::cam.up = (Vector3){0.0f, 0.0f, 0.0f};
  CBCamera::cam.fovy = 60.0f;
  CBCamera::cam.projection = CAMERA_PERSPECTIVE;
}

void del() {
  // delete(CBCamera::cam);
}

void move(Vector3 pos) { CBCamera::cam.position = pos; }
