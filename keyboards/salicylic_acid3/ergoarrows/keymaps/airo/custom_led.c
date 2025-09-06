#include "quantum.h"
#include "custom_led.h"
#include "definitions.h"

#ifdef RGB_MATRIX_ENABLE

#define XX NO_LED
led_config_t g_led_config = { {

    // Left half (38–75)
    // 1   2   3   4   5   6   7
    {  0,  1,  2,  3,  4,  5,  6 }, // 1
    { 13, 12, 11, 10,  9,  8,  7 }, // 2
    { 14, 15, 16, 17, 18, 19, 20 }, // 3
    { 27, 26, 25, 24, 23, 22, 21 }, // 4
    { 28, 29, 34, 30, 31, 32, 33 }, // 5
    { 35, 36, 37, XX, XX, XX, XX }, // 5

    // Right half (38–75) - columns are mirrored
    // 7   6   5   4   3   2   1
    { 38, 39, 40, 41, 42, 43, 44 }, // 1
    { 51, 50, 49, 48, 47, 46, 45 }, // 2
    { 52, 53, 54, 55, 56, 57, 58 }, // 3
    { 65, 64, 63, 62, 61, 60, 59 }, // 4
    { 66, 67, 70, 68, 69, 71, 72 }, // 5
    { XX, XX, XX, XX, 73, 74, 75 }  // 6
}, {
    // LED Index to Physical Position (x, y)
    // Left half
    {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0},
    {6,1}, {5,1}, {4,1}, {3,1}, {2,1}, {1,1}, {0,1},
    {0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2},
    {6,3}, {5,3}, {4,3}, {3,3}, {2,3}, {1,3}, {0,3},
    {0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}, {6,4},
    {2,5}, {1,5}, {0,5},

    // Right half
    {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0},
    {6,1}, {5,1}, {4,1}, {3,1}, {2,1}, {1,1}, {0,1},
    {0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2},
    {6,3}, {5,3}, {4,3}, {3,3}, {2,3}, {1,3}, {0,3},
    {0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}, {6,4},
    {2,5}, {1,5}, {0,5}
}, {
    // Flags – all per-key (4)
    [0 ... 75] = 4
} };

// Some verbose name for my key indexes
#define OSL_LAYER_DEFINES
 #define KC_OSL_INDEX 30
 #define KC_ENT_INDEX 33
 #define KC_CAPSWORD_INDEX 14
 #define KC_ESC_KEY_INDEX 0
 #define QMK_CUSTOM_COMMAND_INDEX1 20
 #define QMK_CUSTOM_COMMAND_INDEX2 21
 #define QMK_CUSTOM_COMMAND_INDEX3 58
 #define QMK_CUSTOM_COMMAND_INDEX4 59
 #define KC_RECORD_MACRO_1 38
 #define KC_RECORD_MACRO_2 51
 #define KC_PLAY_MACRO_1 52
 #define KC_PLAY_MACRO_2 65

#define LAYER_INDICATORS_DEFINES
 #define KC_2_KEY_INDEX 2
 #define KC_3_KEY_INDEX 3
 #define KC_4_KEY_INDEX 4

#define ARROWS_IJKL_LAYER_DEFINES
 #define KC_I_INDEX 48
 #define KC_J_INDEX 54
 #define KC_K_INDEX 55
 #define KC_L_INDEX 56

#define NUMPAD_LAYER_DEFINES
 #define KC_NUMPAD_INDEX 51
 #define KC_NUM0_INDEX 53
 #define KC_NUM0_INDEX_ALT 64
 #define KC_NUM0_INDEX_ALT2 70
 #define KC_NUM1_INDEX 63
 #define KC_NUM2_INDEX 62
 #define KC_NUM3_INDEX 61
 #define KC_NUM4_INDEX 54
 #define KC_NUM5_INDEX 55
 #define KC_NUM6_INDEX 56
 #define KC_NUM7_INDEX 49
 #define KC_NUM8_INDEX 48
 #define KC_NUM9_INDEX 47

#define FKEYS_LAYER_DEFINES
 #define KC_F1_INDEX 1
 #define KC_F2_INDEX 2
 #define KC_F3_INDEX 3
 #define KC_F4_INDEX 4
 #define KC_F5_INDEX 5
 #define KC_F6_INDEX 6
 #define KC_F7_INDEX 44
 #define KC_F8_INDEX 43
 #define KC_F9_INDEX 42
 #define KC_F10_INDEX 41
 #define KC_F11_INDEX 40
 #define KC_F12_INDEX 39

#define FKEYS_LAYER_GRADIENT_DEFINES
 #define KC_F1_GRADIENT_RGB  MY_RGB_RED
 #define KC_F2_GRADIENT_RGB  MY_RGB_RED
 #define KC_F3_GRADIENT_RGB  MY_RGB_RED
 #define KC_F4_GRADIENT_RGB  MY_RGB_BLUE
 #define KC_F5_GRADIENT_RGB  MY_RGB_BLUE
 #define KC_F6_GRADIENT_RGB  MY_RGB_BLUE
 #define KC_F7_GRADIENT_RGB  MY_RGB_GREEN
 #define KC_F8_GRADIENT_RGB  MY_RGB_GREEN
 #define KC_F9_GRADIENT_RGB  MY_RGB_GREEN
 #define KC_F10_GRADIENT_RGB MY_RGB_MAGENTA
 #define KC_F11_GRADIENT_RGB MY_RGB_MAGENTA  // Frequently used as shortcuts, need a stronger color
 #define KC_F12_GRADIENT_RGB MY_RGB_MAGENTA

#define LAYER_LED_INDICATOR(KeyIndex, Layer, Color) \
    if(layer_state & (1UL << Layer)){ rgb_matrix_set_color(KeyIndex, Color); }

bool rgb_matrix_indicators_user(void){

    rgb_matrix_set_color_all(MY_RGB_OFF);

    //rgb_matrix_set_color(0, MY_RGB_RED);
    //rgb_matrix_set_color(51, MY_RGB_RED);

    if (is_caps_word_on() || host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(KC_CAPSWORD_INDEX, MY_RGB_RED);
    }

    // Indexes < 38 are causing mirroring and I dont know why yet, so for now im manuallyn turning off the mirrored leds

    if(get_oneshot_layer() == _LAYER_SELECTOR){

        rgb_matrix_set_color(KC_OSL_INDEX, MY_RGB_AZURE);
        rgb_matrix_set_color(KC_ENT_INDEX, MY_RGB_AZURE);
        rgb_matrix_set_color(KC_ESC_KEY_INDEX, MY_RGB_AZURE);

        rgb_matrix_set_color(KC_2_KEY_INDEX, MY_RGB_GREEN);
        rgb_matrix_set_color(KC_2_KEY_INDEX+38, MY_RGB_OFF);
        rgb_matrix_set_color(KC_3_KEY_INDEX, MY_RGB_AZURE);
        rgb_matrix_set_color(KC_3_KEY_INDEX+38, MY_RGB_OFF);
        rgb_matrix_set_color(KC_4_KEY_INDEX, MY_RGB_PINK);
        rgb_matrix_set_color(KC_4_KEY_INDEX+38, MY_RGB_OFF);

        rgb_matrix_set_color(QMK_CUSTOM_COMMAND_INDEX1, MY_RGB_LIGHT_PURPLE);
        rgb_matrix_set_color(QMK_CUSTOM_COMMAND_INDEX2, MY_RGB_LIGHT_PURPLE);
        rgb_matrix_set_color(QMK_CUSTOM_COMMAND_INDEX3, MY_RGB_LIGHT_PURPLE);
        rgb_matrix_set_color(QMK_CUSTOM_COMMAND_INDEX4, MY_RGB_LIGHT_PURPLE);

        rgb_matrix_set_color(KC_RECORD_MACRO_1, MY_RGB_RED);
        rgb_matrix_set_color(KC_RECORD_MACRO_2, MY_RGB_RED);
        rgb_matrix_set_color(KC_PLAY_MACRO_1, MY_RGB_RED);
        rgb_matrix_set_color(KC_PLAY_MACRO_2, MY_RGB_RED);

    } else {

        // Be sure to keep this in the same order as the layers so priority is correctly respected
        // Tap dances layer
        LAYER_LED_INDICATOR(KC_2_KEY_INDEX, _DANCES, MY_RGB_GREEN);

        // Work  layer
        LAYER_LED_INDICATOR(KC_3_KEY_INDEX, _WORK, MY_RGB_AZURE);

        // IJKL arrows layer
        LAYER_LED_INDICATOR(KC_I_INDEX,   _ARROWS_IJKL, MY_RGB_CYAN);
        LAYER_LED_INDICATOR(KC_J_INDEX,   _ARROWS_IJKL, MY_RGB_CYAN);
        LAYER_LED_INDICATOR(KC_K_INDEX,   _ARROWS_IJKL, MY_RGB_CYAN);
        LAYER_LED_INDICATOR(KC_L_INDEX,   _ARROWS_IJKL, MY_RGB_CYAN);
        // F1-F12
        LAYER_LED_INDICATOR(KC_F1_INDEX,  _ARROWS_IJKL, KC_F1_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F2_INDEX,  _ARROWS_IJKL, KC_F2_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F3_INDEX,  _ARROWS_IJKL, KC_F3_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F4_INDEX,  _ARROWS_IJKL, KC_F4_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F5_INDEX,  _ARROWS_IJKL, KC_F5_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F6_INDEX,  _ARROWS_IJKL, KC_F6_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F7_INDEX,  _ARROWS_IJKL, KC_F7_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F8_INDEX,  _ARROWS_IJKL, KC_F8_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F9_INDEX,  _ARROWS_IJKL, KC_F9_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F10_INDEX, _ARROWS_IJKL, KC_F10_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F11_INDEX, _ARROWS_IJKL, KC_F11_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F12_INDEX, _ARROWS_IJKL, KC_F12_GRADIENT_RGB);

        // Numpad layer
        LAYER_LED_INDICATOR(KC_NUMPAD_INDEX,    _NUMPAD, MY_RGB_RED);
        LAYER_LED_INDICATOR(KC_NUM0_INDEX,      _NUMPAD, MY_RGB_ORANGE2);
        LAYER_LED_INDICATOR(KC_NUM0_INDEX_ALT,  _NUMPAD, MY_RGB_ORANGE2);
        LAYER_LED_INDICATOR(KC_NUM0_INDEX_ALT2, _NUMPAD, MY_RGB_ORANGE2);
        LAYER_LED_INDICATOR(KC_NUM1_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM2_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM3_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM4_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM5_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM6_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM7_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM8_INDEX,      _NUMPAD, MY_RGB_GOLD);
        LAYER_LED_INDICATOR(KC_NUM9_INDEX,      _NUMPAD, MY_RGB_GOLD);
        // Numpad layer F1-F12
        LAYER_LED_INDICATOR(KC_F1_INDEX,  _NUMPAD, KC_F1_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F2_INDEX,  _NUMPAD, KC_F2_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F3_INDEX,  _NUMPAD, KC_F3_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F4_INDEX,  _NUMPAD, KC_F4_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F5_INDEX,  _NUMPAD, KC_F5_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F6_INDEX,  _NUMPAD, KC_F6_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F7_INDEX,  _NUMPAD, KC_F7_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F8_INDEX,  _NUMPAD, KC_F8_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F9_INDEX,  _NUMPAD, KC_F9_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F10_INDEX, _NUMPAD, KC_F10_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F11_INDEX, _NUMPAD, KC_F11_GRADIENT_RGB);
        LAYER_LED_INDICATOR(KC_F12_INDEX, _NUMPAD, KC_F12_GRADIENT_RGB);

        // Gayming layer
        LAYER_LED_INDICATOR(KC_4_KEY_INDEX, _GAME, MY_RGB_PINK);
    }

    return false;
}

void init_leds(void){
    rgb_matrix_enable_noeeprom();
    rgb_matrix_set_color_all(MY_RGB_OFF);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}

#else

void init_leds(void){}

#endif
