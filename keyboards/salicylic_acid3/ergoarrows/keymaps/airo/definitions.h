#pragma once

#include QMK_KEYBOARD_H

// custom
enum custom_keycodes {
    CM_MAKE = SAFE_RANGE,
    KC_COMBO,
};

// Currently set to 8 maximum layers
enum layer_number {
    _QWERTY = 0,
    _DANCES,
    _WORK,
    _ARROWS_IJKL,
    _NUMPAD,
    _GAME,
    _JAPANESE,
    _LAYER_SELECTOR,
};
