#include "modes/extra/DarkSouls.hpp"

#define ANALOG_STICK_MIN 0
#define ANALOG_STICK_NEUTRAL 128
#define ANALOG_STICK_MAX 255

DarkSouls::DarkSouls(const GameModeConfig &config) : ControllerMode(config) {}

void DarkSouls::UpdateDigitalOutputs(const InputState &inputs, OutputState &outputs) {
    outputs.y = inputs.y;
    outputs.x = inputs.r;

    // Base layer.
    bool layer0 = !inputs.x && !inputs.nunchuk_c;
    // Secondary layer when X is held.
    bool layerX = inputs.x && !inputs.nunchuk_c;
    // DPad layer when Nunchuk C is held.
    bool layerC = inputs.nunchuk_c;

    if (layer0) {
        outputs.a = inputs.a;
        outputs.b = inputs.b;
        outputs.buttonR = inputs.z;
        outputs.buttonL = inputs.up;
        outputs.start = inputs.start | inputs.nunchuk_z;
    } else if (layerX) {
        outputs.rightStickClick = inputs.a;
        outputs.triggerRDigital = inputs.z;
        outputs.triggerLDigital = inputs.up;
        outputs.select = inputs.start;
    } else if (layerC) {
        outputs.a = inputs.a;
        outputs.dpadLeft = inputs.b;
        outputs.dpadDown = inputs.x;
        outputs.dpadUp = inputs.z;
        outputs.dpadRight = inputs.up;
        outputs.select = inputs.nunchuk_z;
    }
}

void DarkSouls::UpdateAnalogOutputs(const InputState &inputs, OutputState &outputs) {
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

    // Nunchuk overrides left stick.
    if (inputs.nunchuk_connected) {
        outputs.leftStickX = inputs.nunchuk_x;
        outputs.leftStickY = inputs.nunchuk_y;
    }
}
