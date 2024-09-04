//
// Created by kraks on 02/09/2024.
//

#ifndef SMOLGAME_INPUTHANDLE_H
#define SMOLGAME_INPUTHANDLE_H

#include "Core.h"
#include "raymath.h"
#include <raylib.h>

class InputHandle {
public:
  struct InputPreset {
    static KeyboardKey forward;
    static KeyboardKey back;
    static KeyboardKey left;
    static KeyboardKey right;
    static KeyboardKey jump;
    static KeyboardKey interact;
  };

  static bool grounded;
  static Vector2 mouseDelta; // mouse data
  static Vector3 forward;    // for camera walking dir
  static Vector3 right;      // also camera walking dir
  static Vector3 moveDirections;

  static bool init();
  static void HandleInput();
};

#endif // SMOLGAME_INPUTHANDLE_H
