
#include "Render.h"
#include <raylib.h>

static void startRendering() {
  BeginDrawing();
  BeginMode3D(...);

  EndMode3D();
  EndDrawing();
}

static void del() {}
