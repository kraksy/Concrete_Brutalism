//
// Created by kraks on 14/08/2024.
//

#ifndef SMOLGAME_CORE_H
#define SMOLGAME_CORE_H

#include "raylib.h"
#include "raymath.h"

class Core {
public:
  struct GameConfig {
    static int ScreenWidth;
    static int ScreenHeight;
    static float Gravity;
    static float PlayerJumpSpeed;
    static float PlayerSpeed;
    static float PlayerEyeHeight;
    static float CameraSensitivity;
  };

  typedef struct {
    double hp;
    Vector3 pos;
    Vector3 velocity;
    float height;
    bool isGrounded;

    Model model;
    Texture2D texture;
  } Player;

  typedef struct {
    bool hostile;
    double hp;
    Vector3 pos;
    Vector3 vel;
    float height;

    Model model;
    Texture2D texture;
  } Entity;

  typedef struct {
    Model model;
    Vector3 pos;
    Color color;
    bool clicked;
  } ButtonObject;

  static void initCore();
  static void delCore(); // idk if needed

  // probably move this into another class someday
  static float GetHeightFromTriangle(Vector3 v1, Vector3 v2, Vector3 v3,
                                     Vector3 pos);
  static float GetTerrainHeightAtPosition(Vector3 pos, Model terrain,
                                          float scale);
};

#endif // SMOLGAME_CORE_H
