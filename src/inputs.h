//
// Created by kraks on 14/08/2024.
//

#ifndef SMOLGAME_INPUTS_H
#define SMOLGAME_INPUTS_H

#include "raylib.h"

class inputs {
public:
    typedef struct InputPreset
    {
        KeyboardKey forward;
        KeyboardKey back;
        KeyboardKey left;
        KeyboardKey right;
        KeyboardKey  jump;
        KeyboardKey interact;
    }PlayerInputs;

    static InputPreset setupInputs();
};


#endif //SMOLGAME_INPUTS_H
