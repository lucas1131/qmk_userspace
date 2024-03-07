#pragma once

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "my_colors.h"

#define DEFAULT_COLOR MY_HSV_OFF

void init_leds(void);
void process_led_layer_indicators(layer_state_t state);
