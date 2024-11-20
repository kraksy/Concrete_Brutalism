#include <raylib.h>
#include "raymath.h"
#include <iostream>

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION 330
#else
#define GLSL_VERSION 100
#endif

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

typedef struct Game
{
  static int SCREEN_WIDTH;
  static int SCREEN_HEIGHT;

  static float FOV;
};

typedef struct Player 
{
  static double Health;
  static float height;
  static Vector3 pos;
  static bool isGrounded;
  static Vector3 velocity;
  static float Player_Speed;
  static float Player_Jump_Speed;
};

typedef struct Controlls
{
  static Vector2 mouseDelta;
  static float yaw;
  static float pitch;
  static Vector3 forward;
  static Vector3 right;
};

static Vector3 mapPos;

static Model map;
static Texture2D texture;

static void loadModels()
{
  map = LoadModel("resources/meshes/base.obj");
  texture = LoadTexture("resources/textures/texture.png");
  map.materials[0].maps [MATERIAL_MAP_DIFFUSE].texture = texture;
}

static float CAMERA_SENSITIVITY = 0.003f;
static float PLAYER_EYE_HEIGHT = 2.0f; 

static void cameraHandle()
{
  Controlls::mouseDelta = GetMouseDelta();
  Controlls::yaw += Controlls::mouseDelta.x * CAMERA_SENSITIVITY;
  Controlls::pitch -= Controlls::mouseDelta.y * CAMERA_SENSITIVITY;

  // Clamp the pitch angle to prevent flipping the camera
  Controlls::pitch = Clamp(Controlls::pitch, -PI / 2.0f, PI / 2.0f);

  // Calculate forward and right vectors from the camera's direction
  Controlls::forward = Vector3Subtract(cam.target, cam.position);
  Controlls::forward.y = 0.0f; // Ignore y component for horizontal movement
  Controlls::forward = Vector3Normalize(Controlls::forward);

  Controlls::right = Vector3CrossProduct(Controlls::forward, cam.up);
  Controlls::right = Vector3Normalize(Controlls::right);
}

static Vector3 moveDirection = {0.0f, 0.0f, 0.0f};

static Vector3 inputHandle()
{
  if (IsKeyDown(KEY_W))
    return moveDirection = Vector3Add(moveDirection, Controlls::forward);
  if (IsKeyDown(KEY_S))
    return moveDirection = Vector3Subtract(moveDirection, Controlls::forward);
  if (IsKeyDown(KEY_A))
    return moveDirection = Vector3Subtract(moveDirection, Controlls::right);
  if (IsKeyDown(KEY_D))
    return moveDirection = Vector3Add(moveDirection, Controlls::right);

  // Jumping
  if (IsKeyPressed(KEY_SPACE) && Player::isGrounded) {
    Player::velocity.y = Player::Player_Jump_Speed; // Apply upward velocity
    Player::isGrounded = false; // Player is no longer on the ground
  }
}

static float GRAVITY = 9.81f; 
static Camera cam = { 0 };

static void CameraInit()
{
  cam.position = (Vector3) { 0.0f, 2.0f, 3.0f};
  cam.target = (Vector3) { 0.0f , 0.0f, 0.0f};
  cam.up = (Vector3) { 0.0f, 1.0f, 0.0f };
  cam.fovy = Game::FOV;
  cam.projection = CAMERA_PERSPECTIVE;
}

static void applyGravityOnPlayer()
{
  Player::velocity.y -= GRAVITY * GetFrameTime();
  Player::pos.y += Player::velocity.y * GetFrameTime();
}

static void applyCollisionOnPlayer()
{
  float terrainHeight = GetTerrainHeightAtPosition(Player::pos, map, 1.0f);
  if (Player::pos.y <= terrainHeight + Player::height) {
    Player::pos.y = terrainHeight + Player::height;
    Player::velocity.y = 0.0f;
    Player::isGrounded = true;
  } else {
    Player::isGrounded = false;
  }
}

int main() {
  InitWindow(Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, "smolgame");
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  CameraInit();

  Player::pos.x += moveDirection.x * Player::Player_Speed * GetFrameTime();
  Player::pos.z += moveDirection.z * Player::Player_Speed * GetFrameTime();
  
  Player::pos = cam.position;
  Player::height = PLAYER_EYE_HEIGHT;
  applyGravityOnPlayer();
  applyCollisionOnPlayer();
  while (!WindowShouldClose())  
  {
    inputHandle();
    BeginDrawing();
      BeginMode3D(cam);
        ClearBackground(BLACK);
        DrawModel(map, mapPos, 1.0f, WHITE);
      EndMode3D();
    EndDrawing();
  }
  CloseWindow();
  exit(0);
}
