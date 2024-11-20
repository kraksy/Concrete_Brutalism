
#include "Render.h"
#include "Camera.h"
#include <raylib.h>

static void startRendering() {
  BeginDrawing();
  BeginMode3D(CBCamera::cam);
  EndMode3D();
  EndDrawing();
}

static void del() {}
