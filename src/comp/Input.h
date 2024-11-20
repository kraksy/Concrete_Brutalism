
#include "../Core.h"

#define CAMERA_SENSITIVITY 0.003f

class Input
{
public:
    static KeyboardKey Forward;
    static KeyboardKey Back;
    static KeyboardKey Left;
    static KeyboardKey Right;
    static KeyboardKey Jump;
    static KeyboardKey Interact;

    static float yaw;
    static float pitch;

    Input(
            KeyboardKey forward,
            KeyboardKey back,
            KeyboardKey left,
            KeyboardKey right,
            KeyboardKey jump,
            KeyboardKey interact
    );
    ~Input() = default;

    void HandleInput();
};


