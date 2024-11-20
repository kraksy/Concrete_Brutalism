//
// Created by kraks on 14/08/2024.
//

#ifndef SMOLGAME_CORE_H
#define SMOLGAME_CORE_H

#include "raylib.h"
#include "raymath.h"

class Core {
public:
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

  static bool init();

  static float GetHeightFromTriangle(Vector3 v1, Vector3 v2, Vector3 v3,
                                     Vector3 pos);
  static float GetTerrainHeightAtPosition(Vector3 pos, Model terrain,
                                          float scale);
};

#endif // SMOLGAME_CORE_H
