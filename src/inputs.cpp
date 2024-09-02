//
// Created by kraks on 14/08/2024.
//

#include "inputs.h"

inputs::InputPreset
inputs::setupInputs() {
    auto preset = new InputPreset;
    preset->forward = KEY_W;
    preset->back = KEY_S;
    preset->left = KEY_A;
    preset->right = KEY_D;
    preset->jump = KEY_SPACE;
    preset->interact = KEY_E;
    return *preset;
}
