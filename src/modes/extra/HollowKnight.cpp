#include "modes/extra/HollowKnight.hpp"

#define ANALOG_STICK_MIN 1
#define ANALOG_STICK_NEUTRAL 128
#define ANALOG_STICK_MAX 255

HollowKnight::HollowKnight(const GameModeConfig &config) : ControllerMode(config) {}

void HollowKnight::UpdateDigitalOutputs(const InputState &inputs, OutputState &outputs) {
    outputs.a = inputs.a; // Attack
    outputs.b = inputs.b; // Dash
    outputs.x = inputs.x; // Jump
    outputs.y = inputs.mod_y; // Quick Cast
    outputs.triggerLDigital = inputs.r; // Focus / Cast
    outputs.triggerRDigital = inputs.z; // C-Dash
    outputs.buttonR = inputs.up; // Dream Nail

    outputs.buttonL = inputs.lightshield; // Map
    outputs.select = inputs.midshield; // Inventory
    outputs.start = inputs.start; // Pause
}

void HollowKnight::UpdateAnalogOutputs(const InputState &inputs, OutputState &outputs) {
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
