#include <raylib.h>
#include "raymath.h"
#include <iostream>

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else
#define GLSL_VERSION 100
#endif

typedef struct Game
{
  static int SCREEN_WIDTH;
  static int SCREEN_HEIGHT;
};

typedef struct Player 
{
  static double Health;

  static bool isGrounded;
  static Vector3 velocity;
  static float Player_Speed;
  static float Player_Jump_Speed;
};

static Model map;
static Texture2D texture;

static void loadModels()
{
  map = LoadModel("resources/meshes/base.obj");
  texture = LoadTexture("resources/textures/texture.png");
}

static void cameraHandle()
{
  Vector2 mouseDelta = GetMouseDelta();
  yaw += mouseDelta.x * CAMERA_SENSITIVITY;
  pitch -= mouseDelta.y * CAMERA_SENSITIVITY;

  // Clamp the pitch angle to prevent flipping the camera
  pitch = Clamp(pitch, -PI / 2.0f, PI / 2.0f);

  // Calculate forward and right vectors from the camera's direction
  Vector3 forward = Vector3Subtract(camera.target, camera.position);
  forward.y = 0.0f; // Ignore y component for horizontal movement
  forward = Vector3Normalize(forward);

  Vector3 right = Vector3CrossProduct(forward, camera.up);
  right = Vector3Normalize(right);
}

static Vector3 moveDirection = {0.0f, 0.0f, 0.0f};

static Vector3 inputHandle()
{
  if (IsKeyDown(KEY_W))
    return moveDirection = Vector3Add(moveDirection, forward);
  if (IsKeyDown(KEY_S))
    return moveDirection = Vector3Subtract(moveDirection, forward);
  if (IsKeyDown(KEY_A))
    return moveDirection = Vector3Subtract(moveDirection, right);
  if (IsKeyDown(KEY_D))
    return moveDirection = Vector3Add(moveDirection, right);

  // Jumping
  if (IsKeyPressed(KEY_SPACE) && Player::isGrounded) {
    Player::velocity.y = Player::Player_Jump_Speed; // Apply upward velocity
    Player::isGrounded = false; // Player is no longer on the ground
  }
}

int main() {
  InitWindow(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, "smolgame");
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  while (!WindowShouldClose())
  {
    inputHandle();
    BeginDrawing();
      ClearBackground(BLACK);

    EndDrawing();
  }
  CloseWindow();
  exit(0);
}