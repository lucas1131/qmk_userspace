/*
    Copyright 2021-2024 Salicylic_Acid

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
#include "led_indicators.h"
#include "definitions.h"

#define NO_TOUCH _______
#define KC_SPR KC_LGUI  // super renamed
#define NPAD_DOT KC_KP_DOT
#define KC_CEDL RALT(KC_COMM)  // ç renamed

// For jp layout
#define IME_INPT LGUI(KC_SPACE)
#define HIRAGANA LCTL(KC_CAPS)
#define KATAKANA LALT(KC_CAPS)

// Mod tap defines
#define LALTBSPC LALT_T(KC_BSPC)
#define RALTBSPC RALT_T(KC_BSPC)
#define RALT_SPC RALT_T(KC_SPC)
#define LALT_DEL LALT_T(KC_DEL)
#define RCTLBSCP RCTL_T(KC_BSPC)
#define RCTL_SPC RCTL_T(KC_SPC)
#define LCTL_SPC LCTL_T(KC_SPC)
#define SPR_ENT LGUI_T(KC_ENT)
#define SPR_IJKL LT(SL_IJKL, KC_SPR) // super and set arrows layout
#define SPR_WASD LT(SL_WASD, KC_SPR)

#include "tap_dance.c"

// Tap dance defines
tap_dance_action_t tap_dance_actions[] = {
    [TAP_DANCE_TSCLN_HCLN] = TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLN, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_LSQB_LCBR] = TAP_DANCE_TAP_HOLD(KC_LBRC, KC_LCBR, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_RSQB_RCBR] = TAP_DANCE_TAP_HOLD(KC_RBRC, KC_RCBR, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_QUOT_DQUO] = TAP_DANCE_TAP_HOLD(KC_QUOT, KC_DQUO, TAP_DANCE_INTERRUPT_SEND_TAP),
    [TAP_DANCE_C_CEDL] = TAP_DANCE_TAP_DOUBLE_TAP(KC_C, KC_CEDL),
    [TAP_DANCE_A_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_A, KC_TILD),
    [TAP_DANCE_E_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_E, KC_CIRC),
    [TAP_DANCE_O_ACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_O, KC_TILD),
};

#define SCLN_CLN TD(TAP_DANCE_TSCLN_HCLN)          // tap ; hold :
#define LP_LSFT  TD(TAP_DANCE_LPRN_LSFT)           // tap ( hold lshift
#define RP_RSFT  TD(TAP_DANCE_RPRN_RSFT)           // tap ) hold rshift
#define LSB_LCB  TD(TAP_DANCE_LSQB_LCBR)           // tap [ hold {
#define RSB_RCB  TD(TAP_DANCE_RSQB_RCBR)           // tap ] hold }
#define QUO_DQUO TD(TAP_DANCE_QUOT_DQUO)           // tap ' hold "

#define TTD_IJKL TD(TAP_DANCE_TT_IJKL)             // tap switch layer ijkl hold toggle layer ijkl

#define C_ACC    TD(TAP_DANCE_C_CEDL)              // tap c double tap ç
#define A_ACC    TD(TAP_DANCE_A_ACC)               // tap a double tap ã
#define E_ACC    TD(TAP_DANCE_E_ACC)               // tap e double tap ê
#define I_ACC    TD(TAP_DANCE_I_ACC)               // tap i double tap í
#define O_ACC    TD(TAP_DANCE_O_ACC)               // tap o double tap õ
#define U_ACC    TD(TAP_DANCE_U_ACC)               // tap u double tap ú

// Layers defines 
#define SL_IJKL MO(_ARROWS_IJKL) // MO(_ARROWS_IJKL) switch layer hold
#define SL_NPAD MO(_NUMPAD) // MO(_NUMPAD) switch layer hold
#define TL_IJKL TG(_ARROWS_IJKL) // TG(_ARROWS_IJKL) switch layer toggle
#define TL_NPAD TG(_NUMPAD) // TG(_NUMPAD) switch layer toggle
#define TT_IJKL TT(_ARROWS_IJKL) // TT(_ARROWS_IJKL) switch layer tap-toggle
#define TT_NPAD TT(_NUMPAD) // TT(_NUMPAD) switch layer tap-toggle

#define TL_DFLT TG(_QWERTY)
#define TL_TD   TG(_DANCES)
#define TL_WORK TG(_WORK)
#define TL_GAME TG(_GAME)

#define OS_SLCT OSL(_LAYER_SELECTOR) // One shot layer selector


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(                                                      //acentos
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_GRV,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_PAST,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
             KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     TL_NPAD,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            CW_TOGG,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, _______,    QUO_DQUO,    KC_H,    KC_J,    KC_K,    KC_L,SCLN_CLN,  KC_EQL,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,KC_COMBO,     KC_BSLS, KC_SLSH,    KC_N,    KC_M, KC_COMM,  KC_DOT, SC_RSPC,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            SL_IJKL, LSB_LCB,   KC_UP, OS_SLCT, KC_LALT,LCTL_SPC, SPR_ENT,      KC_ENT,RCTL_SPC,RALTBSPC, KC_PSCR,   KC_UP, RSB_RCB, _______,
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

    [_NUMPAD] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_HOME,   KC_UP, KC_PGUP, _______, _______, _______,     TL_NPAD, _______,    KC_7,    KC_8,    KC_9, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,     _______, _______,    KC_4,    KC_5,    KC_6, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______,  KC_END, KC_DOWN, KC_PGDN, _______, _______, _______,     _______,    KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
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

    [_JAPANESE] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            KC_LSFT, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______,NO_TOUCH, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
                     _______, _______, _______,                                                           _______, _______, _______    
        //|--------------------------------------------------------------|   |--------------------------------------------------------------'
    ),

    [_LAYER_SELECTOR] = LAYOUT(
        //,--------------------------------------------------------------|   |--------------------------------------------------------------.
             KC_ESC, _______,   TL_TD, TL_WORK, TL_GAME, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD,
        //|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
            KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,     QK_BOOT,HIRAGANA,IME_INPT,KATAKANA, XXXXXXX, XXXXXXX, RGB_VAI,
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
        case E_ACC:
        case O_ACC:
        case A_ACC:
        case C_ACC:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_LSFT:
        case KC_RSFT:
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
        case RCTL_SPC:
        case LCTL_SPC:
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

void test_led_matrix(void){
    int val = 0;
    setrgb(255, 255, 255, (rgb_led_t *)&led[0]); val += 8;
    setrgb(8, 4, 2, (rgb_led_t *)&led[ 1]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 2]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 3]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 4]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 5]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 6]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 7]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 8]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[ 9]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[10]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[11]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[12]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[13]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[14]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[15]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[16]); val += 8;

    setrgb(val, val/4, val/8, (rgb_led_t *)&led[17]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[18]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[19]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[20]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[21]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[22]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[23]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[24]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[25]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[26]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[27]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[28]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[29]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[30]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[31]); val += 8;
    setrgb(val, val/4, val/8, (rgb_led_t *)&led[32]); val += 8;

    val = 0;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[33]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[34]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[35]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[36]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[37]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[38]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[39]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[40]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[41]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[42]); val += 8;
    setrgb(255, 255, 255, (rgb_led_t *)&led[43]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[44]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[45]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[46]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[47]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[48]); val += 8;

    setrgb(val/4, val, val/8, (rgb_led_t *)&led[49]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[50]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[51]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[52]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[53]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[54]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[55]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[56]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[57]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[58]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[59]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[60]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[61]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[62]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[63]); val += 8;
    setrgb(val/4, val, val/8, (rgb_led_t *)&led[64]); val += 8;

    val = 0;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[65]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[66]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[67]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[68]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[69]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[70]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[71]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[72]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[73]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[74]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[75]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[76]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[77]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[78]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[79]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[80]); val += 8;

    val = 0;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[81]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[82]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[83]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[84]); val += 8;
    setrgb(val/16, val/8, val/4, (rgb_led_t *)&led[85]); val += 8;

    rgblight_set();
}

layer_state_t layer_state_set_user(layer_state_t state) {

    // process_led_layer_indicators(state);
    test_led_matrix();

    switch (get_highest_layer(state)) {
        case _QWERTY:
        break;

        case _DANCES:
        break;

        case _WORK:
        break;

        case _ARROWS_IJKL:
        break;

        case _NUMPAD:
        break;

        case _GAME:
        break;

        case _JAPANESE:
        break;

        case _LAYER_SELECTOR:
            rgblight_sethsv(DEFAULT_COLOR);
        break;

        default:
        break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CM_MAKE:
        if (record->event.pressed) {
            SEND_STRING("qmk compile -j 8 -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
        }
        return false;
    }

    return true;
}

void keyboard_post_init_user() {

    init_leds();
    test_led_matrix();

#ifdef CONSOLE_ENABLE
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
#endif
}

// Combo needs some names definitions to work, so leave it here
#include "combos.c"



/* These are two magic functions (with __attribute__((weak))) used to swap keycodes
 for, respectively, baclslash and backspace; and ctrl and GUI. I don't need these so
 overwrite theses functions with basically do nothing code
*/
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

  