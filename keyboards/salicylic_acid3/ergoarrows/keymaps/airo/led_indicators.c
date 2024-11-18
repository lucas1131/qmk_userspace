#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "rgblight.h"
#include "led_indicators.h"
#include "led_macros.h"
#include "my_colors.h"
#include "definitions.h"

#define GET_LAYER(state, layer) ((state >> layer) & 1)

void init_leds(){
	rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv(DEFAULT_COLOR);
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
