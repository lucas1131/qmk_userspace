/*
    Copyright 2021-2023 Salicylic_Acid

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"
#include "keymap_japanese.h"
#include "action_layer.h"

// custom 
enum custom_keycodes {
    CM_MAKE = SAFE_RANGE,
};

#define NO_TOUCH _______
#define KC_SPR KC_LGUI  // super renamed
#define KC_CEDL RALT(KC_COMM)  // ç renamed


// Mod tap defines
#define LALTBSPC LALT_T(KC_BSPC)
#define RALTBSPC RALT_T(KC_BSPC)
#define LALT_DEL LALT_T(KC_DEL)
#define RCT_SPC RCTL_T(KC_SPC)
#define LCT_SPC LCTL_T(KC_SPC)
#define SPR_ENT LGUI_T(KC_ENT)
#define SPR_IJKL LT(SL_IJKL, KC_SPR) // super and set arrows layout
#define SPR_WASD LT(SL_WASD, KC_SPR)

#include "tap_dance.c"

// Tap dance defines
tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_TSCLN_HCLN] = TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLN, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_C_CEDL] = TAP_DANCE_TAP_DOUBLE_TAP(KC_C, KC_CEDL),
    [TAP_DANCE_LPRN_LSFT] = TAP_DANCE_QUAD_TAP_ACTION(KC_LPRN, KC_LSFT, KC_A, 0, TAP_DANCE_INTERRUPT_SEND_HOLD),
    [TAP_DANCE_RPRN_RSFT] = TAP_DANCE_QUAD_TAP_ACTION(KC_RPRN, KC_RSFT, CW_TOGG, 0, TAP_DANCE_INTERRUPT_SEND_HOLD),
    [TAP_DANCE_LSQB_LCBR] = TAP_DANCE_TAP_HOLD(KC_LBRC, KC_LCBR, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_RSQB_RCBR] = TAP_DANCE_TAP_HOLD(KC_RBRC, KC_RCBR, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_C_CEDL] = TAP_DANCE_TAP_DOUBLE_TAP(KC_C, KC_CEDL),
    [TAP_DANCE_A_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_A, KC_TILD),
    [TAP_DANCE_E_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_E, KC_CIRC),
    // [TAP_DANCE_I_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_I, KC_DQUO),
    [TAP_DANCE_O_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_O, KC_TILD),
    // [TAP_DANCE_U_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_U, KC_DQUO),
};

#define SCLN_CLN TD(TAP_DANCE_TSCLN_HCLN)          // tap ; hold :
#define LP_LSFT  TD(TAP_DANCE_LPRN_LSFT)           // tap ( hold lshift
#define RP_RSFT  TD(TAP_DANCE_RPRN_RSFT)           // tap ) hold rshift
#define LSB_LCB  TD(TAP_DANCE_LSQB_LCBR)           // tap [ hold {
#define RSB_RCB  TD(TAP_DANCE_RSQB_RCBR)           // tap ] hold }
#define C_ACC    TD(TAP_DANCE_C_CEDL)              // tap c double tap ç
#define A_ACC    TD(TAP_DANCE_A_ACC)               // tap a double tap ã
#define E_ACC    TD(TAP_DANCE_E_ACC)               // tap e double tap ê
#define I_ACC    TD(TAP_DANCE_I_ACC)               // tap i double tap í
#define O_ACC    TD(TAP_DANCE_O_ACC)               // tap o double tap õ
#define U_ACC    TD(TAP_DANCE_U_ACC)               // tap u double tap ú

// Layers defines 
#define SL_IJKL MO(_ARROWS_IJKL) // MO(_ARROWS_IJKL) switch layer hold
#define SL_WASD MO(_ARROWS_WASD) // MO(_ARROWS_WASD) switch layer hold
#define TL_IJKL TG(_ARROWS_IJKL) // TG(_ARROWS_IJKL) switch layer toggle
#define TL_WASD TG(_ARROWS_WASD) // TG(_ARROWS_WASD) switch layer toggle
#define TT_IJKL TT(_ARROWS_IJKL) // TT(_ARROWS_IJKL) switch layer tap-toggle
#define TT_WASD TT(_ARROWS_WASD) // TT(_ARROWS_WASD) switch layer tap-toggle

#define TL_DFLT TG(_QWERTY)
#define TL_TD   TG(_DANCES)
#define TL_WORK TG(_WORK)
#define TL_GAME TG(_GAME)

#define OS_SLCT OSL(_LAYER_SELECTOR) // One shot layer selector

// Layer is set to 8 and realistically there shouldn't be any need for more than this
enum layer_number {
    _QWERTY = 0,
    _DANCES,
    _WORK,
    _ARROWS_IJKL,
    _ARROWS_WASD,
    _GAME,
    _UNUNSED,
    _LAYER_SELECTOR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(                                                      //acentos
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_GRV,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PAST,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
             KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_BSLS,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            CW_TOGG,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_QUOT,    KC_H,    KC_J,    KC_K,    KC_L,SCLN_CLN,  KC_EQL,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            LP_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     _______, KC_SLSH,    KC_N,    KC_M, KC_COMM,  KC_DOT, RP_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            SL_IJKL, LSB_LCB,   KC_UP, OS_SLCT,LALTBSPC, LCT_SPC, KC_LGUI,      KC_ENT, RCT_SPC,RALTBSPC, KC_PSCR,   KC_UP, RSB_RCB, SL_WASD,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                    KC_LEFT, KC_DOWN, KC_RGHT,                                                           KC_LEFT, KC_DOWN, KC_RGHT    
        //'--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_DANCES] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,   E_ACC, _______, _______, _______,     _______, _______, _______, _______,   O_ACC, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______,   A_ACC, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,   C_ACC, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,NO_TOUCH, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_WORK] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,NO_TOUCH,LALT_DEL, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_ARROWS_IJKL] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_HOME,   KC_UP, KC_PGUP, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______,  KC_END, KC_DOWN, KC_PGDN, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_ARROWS_WASD] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_HOME,   KC_UP, KC_PGUP, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______,  KC_END, KC_DOWN, KC_PGDN, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,NO_TOUCH, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_GAME] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,    KC_E, _______, _______, _______,     _______, _______, _______, _______,    KC_O, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______,    KC_A, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,    KC_C, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,NO_TOUCH, _______, KC_BTN1, KC_BTN2,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_UNUNSED] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,NO_TOUCH, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_LAYER_SELECTOR] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_ESC, TL_DFLT,   TL_TD, TL_WORK, TL_GAME, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CM_MAKE,     CM_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX,NO_TOUCH, XXXXXXX, XXXXXXX,  KC_ENT,      KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                         XXXXXXX, XXXXXXX, XXXXXXX,                                                           XXXXXXX, XXXXXXX, XXXXXXX    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    )
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // for quick alt tab
        case LALTBSPC:
            return 110;
        // for mod taps
        case RCT_SPC:
        case LCT_SPC:
        case KC_SCLN:
            return 150;
        // for black magic dance shenanigans
        case C_ACC:
            return 156;
        case O_ACC:
            return 170;
        case A_ACC:
        case E_ACC:
        case I_ACC:
        case U_ACC: 
            return 160;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    default:
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // tap_dance_action_t *tap_dance_action;

    switch (keycode) {
        case CM_MAKE:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -j 12 -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
            }
            return false;
    }

    return true;
}

void keyboard_post_init_user() {

    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_setrgb(RGB_RED);

#ifdef CONSOLE_ENABLE
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;
#endif
}

// Combo needs some names definitions to work, so leave it here
#include "combos.c"



/* These are two magic functios (with __attribute__((weak))) used to swap keycodes 
 for, respectively, baclslash and backspace; and ctrl and GUI. I don't need these so
 overwrite theses functions with basically do nothing code
*/
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

  