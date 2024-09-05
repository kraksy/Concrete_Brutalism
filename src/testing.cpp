//
// Created by kraks on 04/08/2024.
//

#include "Core.h"
#include "inputs.h"
#include "raymath.h"
#include <iostream>
#include <raylib.h>

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else
#define GLSL_VERSION 100
#endif

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200
#define GRAVITY 9.81f          // Gravity force
#define PLAYER_JUMP_SPEED 4.0f // Jumping speed
#define PLAYER_SPEED 5.0f      // Movement speed
#define PLAYER_EYE_HEIGHT 2.0f // Player's eye height
#define CAMERA_SENSITIVITY 0.003f

float GetHeightFromTriangle(Vector3 v1, Vector3 v2, Vector3 v3,
                            Vector3 position) {
  float height = (v1.y + v2.y + v3.y) / 3.0f;
  return height;
}

float GetTerrainHeightAtPosition(Vector3 position, Model terrain, float scale) {
  Mesh mesh = terrain.meshes[0];
  Vector3 *vertices = (Vector3 *)mesh.vertices;
  int vertexCount = mesh.vertexCount;

  for (int i = 0; i < vertexCount; i += 3) {
    Vector3 v1 = Vector3Scale(vertices[i], scale);
    Vector3 v2 = Vector3Scale(vertices[i + 1], scale);
    Vector3 v3 = Vector3Scale(vertices[i + 2], scale);

    if (CheckCollisionPointTriangle(
            (Vector2){position.x, position.z}, (Vector2){v1.x, v1.z},
            (Vector2){v2.x, v2.z}, (Vector2){v3.x, v3.z})) {
      float height = GetHeightFromTriangle(v1, v2, v3, position);
      return height;
    }
  }
  return 0.0f;
}

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "smolgame");
  SetConfigFlags(FLAG_MSAA_4X_HINT);

  Camera camera = {0};
  camera.position = (Vector3){0.0f, 2.0f, 3.0f}; // Camera position
  camera.target = (Vector3){0.0f, 2.0f, 0.0f};   // Camera looking at point
  camera.up =
      (Vector3){0.0f, 1.0f, 0.0f}; // Camera up vector (rotation towards target)
  camera.fovy = 60.0f;             // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

  Core::Player player = {0};
  player.pos = camera.position;
  player.velocity = (Vector3){0.0f, 0.0f, 0.0f};
  player.height = PLAYER_EYE_HEIGHT;
  player.isGrounded = false;

  Model map = LoadModel(
      "C:\\Users\\kraks\\Desktop\\smolgame\\resources\\meshes\\base.obj");
  Texture2D texture = LoadTexture(
      "C:\\Users\\kraks\\Desktop\\smolgame\\resources\\textures\\texture.png");
  map.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
  Vector3 pos = {0.0f, 0.0f, 0.0f};

  Model buttonModel = LoadModel(
      "C:\\Users\\kraks\\Desktop\\smolgame\\resources\\meshes\\testing.obj");

  Core::ButtonObject button = {0};
  button.model = buttonModel;
  button.color = WHITE;

  if (map.meshes == NULL) {
    TraceLog(LOG_ERROR, "Failed to load model: %s", "resources/map.obj");
    CloseWindow();
    return -1;
  }

  Shader shader = LoadShader(
      0, TextFormat("C:\\Users\\kraks\\Desktop\\smolgame\\resources\\shader.fs",
                    GLSL_VERSION));

  float pitch = 0.0f; // Vertical rotation angle
  float yaw = 0.0f;   // Horizontal rotation angle

  // setup inputs
  inputs::InputPreset playerInputs = inputs::setupInputs();

  // basic settings
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    DisableCursor();

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

    // Update player position based on input and camera direction
    Vector3 moveDirection = {0.0f, 0.0f, 0.0f};

    if (IsKeyDown(KEY_W))
      moveDirection = Vector3Add(moveDirection, forward);
    if (IsKeyDown(KEY_S))
      moveDirection = Vector3Subtract(moveDirection, forward);
    if (IsKeyDown(KEY_A))
      moveDirection = Vector3Subtract(moveDirection, right);
    if (IsKeyDown(KEY_D))
      moveDirection = Vector3Add(moveDirection, right);
    // Jumping
    if (IsKeyPressed(KEY_SPACE) && player.isGrounded) {
      player.velocity.y = PLAYER_JUMP_SPEED; // Apply upward velocity
      player.isGrounded = false; // Player is no longer on the ground
    }

    player.pos.x += moveDirection.x * PLAYER_SPEED * GetFrameTime();
    player.pos.z += moveDirection.z * PLAYER_SPEED * GetFrameTime();

    // Apply gravity
    player.velocity.y -= GRAVITY * GetFrameTime();
    player.pos.y += player.velocity.y * GetFrameTime();

    // Collision with terrain
    float terrainHeight = GetTerrainHeightAtPosition(player.pos, map, 1.0f);
    if (player.pos.y <= terrainHeight + player.height) {
      player.pos.y = terrainHeight + player.height;
      player.velocity.y = 0.0f;
      player.isGrounded = true;
    } else {
      player.isGrounded = false;
    }

    // Update camera position to match player position
    camera.position = (Vector3){player.pos.x, player.pos.y, player.pos.z};

    Vector3 direction = Vector3Subtract(camera.target, camera.position);
    Vector3Normalize(direction);

    // Check if the ray from camera to direction intersects with the object
    Ray ray = {camera.position, direction};
    RayCollision hitInfo = GetRayCollisionSphere(ray, button.pos, 0.1f);

    if (hitInfo.hit) {
      button.clicked = true;
    } else {
      button.clicked = false;
    }

    BeginDrawing();
    ClearBackground(GRAY);

    BeginMode3D(camera);
    BeginShaderMode(shader);
    DrawModel(map, pos, 1.0f, WHITE);
    DrawModel(button.model, (Vector3){1.0f, 1.0f, 1.0f}, 1.0f,
              button.clicked ? WHITE : BLACK);
    EndShaderMode();
    EndMode3D();
    EndDrawing();
  }
  UnloadTexture(texture);
  UnloadModel(map);
  UnloadShader(shader);
  CloseWindow();
  return 0;
}
