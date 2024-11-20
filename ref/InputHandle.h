//
// Created by kraks on 02/09/2024.
//

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
  } PlayerPreset;

  static bool grounded;
  static Vector2 mouseDelta; // mouse data
  static Vector3 forward;    // for camera walking dir
  static Vector3 right;      // also camera walking dir
  static Vector3 moveDirections;

  static bool init();
  static void HandleInput();

  // experimental
  // I dont think I will implement mobile port

  static void HandleControllerInput();
  static void HandleMobileInput();

  typedef struct TouchInfo {
    int x;
    int y;
  } Tinfo;
  static void getTouch();

private:
  typedef struct MouseInfo {
    float yaw;
    float pitch;
  } Minfo;
  static MouseInfo getInfo();
  static void delInfo();
};
