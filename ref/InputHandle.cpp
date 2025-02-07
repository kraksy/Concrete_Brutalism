
#include "InputHandle.h"
#include "GameConfig.h"
#include "Player.h"

bool InputHandle::init() {
  InputHandle::InputPreset::interact = KEY_E;
  InputHandle::InputPreset::jump = KEY_SPACE;
  InputHandle::InputPreset::right = KEY_D;
  InputHandle::InputPreset::left = KEY_A;
  InputHandle::InputPreset::forward = KEY_W;
  InputHandle::InputPreset::back = KEY_S;
  return true;
}

void InputHandle::HandleInput() {
  if (IsKeyDown(InputPreset::forward))
    InputHandle::moveDirections =
        Vector3Add(InputHandle::moveDirections, InputHandle::forward);
  if (IsKeyDown(InputPreset::back))
    InputHandle::moveDirections =
        Vector3Subtract(InputHandle::moveDirections, InputHandle::forward);
  if (IsKeyDown(InputPreset::left))
    InputHandle::moveDirections =
        Vector3Subtract(InputHandle::moveDirections, InputHandle::right);
  if (IsKeyDown(InputPreset::right))
    InputHandle::moveDirections =
        Vector3Add(InputHandle::moveDirections, InputHandle::right);
  // Jumping
  if (IsKeyPressed(InputPreset::jump) && Player::player::isGrounded) {
    Player::player::velocity.y =
        GameConfig::PlayerJumpSpeed;    // Apply upward velocity
    Player::player::isGrounded = false; // Player is no longer on the ground
  }
  if (IsKeyPressed(InputPreset::interact)) {
  }
}
