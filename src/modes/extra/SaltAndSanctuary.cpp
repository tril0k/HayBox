#include "modes/extra/SaltAndSanctuary.hpp"

#define ANALOG_STICK_MIN 1
#define ANALOG_STICK_NEUTRAL 128
#define ANALOG_STICK_MAX 255

SaltAndSanctuary::SaltAndSanctuary(const GameModeConfig &config) : ControllerMode(config) {}

void SaltAndSanctuary::UpdateDigitalOutputs(const InputState &inputs, OutputState &outputs) {
    outputs.dpadRight = inputs.l; // Block
    outputs.b = inputs.b; // Roll
    outputs.a = inputs.a; // Attack
    outputs.y = inputs.z; // Strong
    outputs.dpadDown = inputs.mod_y; // Use
    outputs.x = inputs.x; // Jump

    outputs.buttonL = inputs.r; // Previous item
    outputs.buttonR = inputs.y; // Next item
    outputs.triggerLDigital = inputs.lightshield; // Use item

    outputs.triggerRDigital = inputs.midshield; // Use torch

    outputs.dpadLeft = inputs.up; // Switch loadout

    outputs.start = inputs.start; // Inventory
}

void SaltAndSanctuary::UpdateAnalogOutputs(const InputState &inputs, OutputState &outputs) {
    // Coordinate calculations to make modifier handling simpler.
    UpdateDirections(
        inputs.left,
        inputs.right,
        inputs.down,
        inputs.mod_x,
        inputs.c_left,
        inputs.c_right,
        inputs.c_down,
        inputs.c_up,
        ANALOG_STICK_MIN,
        ANALOG_STICK_NEUTRAL,
        ANALOG_STICK_MAX,
        outputs
    );
}
