
#include "Input.h"

void Input::HandleInput()
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


    if(IsKeyDown(Forward)){}
    if(IsKeyDown(Back)){}
    if(IsKeyDown(Right)){}
    if(IsKeyDown(Left)){}
}

Input::Input(KeyboardKey forward, KeyboardKey back, KeyboardKey left, KeyboardKey right, KeyboardKey jump,
             KeyboardKey interact) {
    Forward = forward;
    Back = back;
    Left = left;
    Right = right;
    Jump = jump;
    Interact = interact;
}
