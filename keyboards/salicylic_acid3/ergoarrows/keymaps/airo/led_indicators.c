#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "rgblight.h"
#include "led_indicators.h"
#include "led_macros.h"
#include "my_colors.h"
#include "definitions.h"

#define GET_LAYER(state, layer) ((state >> layer) & 1)

#ifdef RGB_MATRIX_ENABLE

// this here is just example, need to set correct config for my kb
led_config_t g_led_config = { {
    {  17,  12,  11,   5,   4 },
    {  16,  13,  10,   6,   3 },
    {  15,  14,   9,   7,   2 },
    { NO_LED, NO_LED, NO_LED,  8, 1 },
    {  33,  28,  27,  22,  21 },
    {  32,  29,  26,  23,  20 },
    {  31,  30,  25,  24,  19 },
    { NO_LED, NO_LED, NO_LED, 33, 18 }
}, {
    { 95,   64 }, { 81,   39 }, { 81,   23 }, { 81,    7 }, {  60,   5 }, {  60,  21 },
    { 60,   37 }, { 73,   56 }, { 40,   32 }, { 40,   16 }, {  40,   0 }, {  20,   6 },
    { 20,   22 }, { 20,   38 }, {  0,   49 }, {  0,   33 }, {   0,  18 }, { 129,  64 },
    { 143,  39 }, { 143,  23 }, { 143,   7 }, { 164,   5 }, { 164,  21 }, { 164,  37 },
    { 151,  56 }, { 184,  32 }, { 184,  16 }, { 184,   0 }, { 204,   6 }, { 204,  22 },
    { 204,  38 }, { 224,  49 }, { 224,  33 }, { 224,  18 }
}, {
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4
} };

#endif

void init_leds(){
	rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv(MY_HSV_RED);
    rgblight_setrgb(MY_RGB_GREEN);
}

void process_led_layer_indicators(layer_state_t state){

	if(GET_LAYER(state, _DANCES)){
        sethsv(MY_HSV_CYAN, LED_BUFFER_AT(LAYER_1_LED_INDICATOR_INDEX));
    } /*else {
        sethsv(DEFAULT_COLOR, LED_BUFFER_AT(LAYER_1_LED_INDICATOR_INDEX));
    }*/


    if(GET_LAYER(state, _WORK)){
        sethsv(MY_HSV_CYAN, LED_BUFFER_AT(LAYER_2_LED_INDICATOR_INDEX));
    }/* else {
        sethsv(DEFAULT_COLOR, LED_BUFFER_AT(LAYER_2_LED_INDICATOR_INDEX));
    }*/


    if(GET_LAYER(state, _ARROWS_IJKL)){
        // SET_NUMPAD_LED_INDICATORS(hsv, MY_HSV_GOLD);
        SET_IJKL_LED_INDICATORS(hsv, MY_HSV_CYAN, MY_HSV_RED);
    }/* else {
        // SET_NUMPAD_LED_INDICATORS(hsv, DEFAULT_COLOR);
        SET_IJKL_LED_INDICATORS(hsv, MY_HSV_GREEN, MY_HSV_GREEN);
    }*/


    if(GET_LAYER(state, _NUMPAD)){
        SET_NUMPAD_LED_INDICATORS(hsv, MY_HSV_GOLD);
        // SET_IJKL_LED_INDICATORS(hsv, MY_HSV_CYAN, MY_HSV_RED);
    }/* else {
        SET_NUMPAD_LED_INDICATORS(hsv, DEFAULT_COLOR);
        // SET_IJKL_LED_INDICATORS(hsv, MY_HSV_GREEN, MY_HSV_GREEN);

        sethsv(DEFAULT_COLOR, LED_BUFFER_AT(LAYER_4_LED_INDICATOR_INDEX));
    }*/


    if(GET_LAYER(state, _GAME)){
        sethsv(MY_HSV_CYAN, LED_BUFFER_AT(LAYER_5_LED_INDICATOR_INDEX));
    }/* else {
        sethsv(DEFAULT_COLOR, LED_BUFFER_AT(LAYER_5_LED_INDICATOR_INDEX));
    }*/


    if(GET_LAYER(state, _GAME)){
        sethsv(MY_HSV_CYAN, LED_BUFFER_AT(LAYER_5_LED_INDICATOR_INDEX_RIGHT));
    }/* else {
        sethsv(DEFAULT_COLOR, LED_BUFFER_AT(LAYER_5_LED_INDICATOR_INDEX_RIGHT));
    }*/

    rgblight_set();
}
