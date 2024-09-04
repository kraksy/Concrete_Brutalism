//
// Created by kraks on 14/08/2024.
//

#include "Core.h"

static void initCore() {
  Core::GameConfig::ScreenHeight = 1200;
  Core::GameConfig::ScreenWidth = 1200;
  Core::GameConfig::PlayerEyeHeight = 2.0f;
  Core::GameConfig::PlayerJumpSpeed = 4.0f;
  Core::GameConfig::PlayerSpeed = 5.0f;
  Core::GameConfig::Gravity = 9.81;
  Core::GameConfig::CameraSensitivity = 0.003f;
}

static Core::GetHeightFromTriangle(Vector3 v1, Vector3 v2, Vector3 v3,
                                   Vector3 pos) {
  float height = (v1.y + v2.y + v3.y) / 3.0f;
  return height;
}
