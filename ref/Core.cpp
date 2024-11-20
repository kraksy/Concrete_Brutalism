//
// Created by kraks on 14/08/2024.
//

#include "Core.h"
#include "GameConfig.h"

static void init() {
  GameConfig::ScreenHeight = 1200;
  GameConfig::ScreenWidth = 1200;
  GameConfig::PlayerEyeHeight = 2.0f;
  GameConfig::PlayerJumpSpeed = 4.0f;
  GameConfig::PlayerSpeed = 5.0f;
  GameConfig::Gravity = 9.81;
  GameConfig::CameraSensitivity = 0.003f;
}

static float GetHeightFromTriangle(Vector3 v1, Vector3 v2, Vector3 v3,
                                   Vector3 pos) {
  float height = (v1.y + v2.y + v3.y) / 3.0f;
  return height;
}

static float GetTerrainHeightAtPosition(Vector3 pos, Model terrain,
                                        float scale) {
  Mesh mesh = terrain.meshes[0];
  Vector3 *vertices = (Vector3 *)mesh.vertices;
  int vertexCount = mesh.vertexCount;

  for (int i = 0; i < vertexCount; i += 3) {
    Vector3 v1 = Vector3Scale(vertices[i], scale);
    Vector3 v2 = Vector3Scale(vertices[i + 1], scale);
    Vector3 v3 = Vector3Scale(vertices[i + 2], scale);

    if (CheckCollisionPointTriangle(
            (Vector2){pos.x, pos.z}, (Vector2){v1.x, v1.z},
            (Vector2){v2.x, v2.z}, (Vector2){v3.x, v3.z})) {
      float height = GetHeightFromTriangle(v1, v2, v3, pos);
      return height;
    }
  }
  return 0.0f;
}
