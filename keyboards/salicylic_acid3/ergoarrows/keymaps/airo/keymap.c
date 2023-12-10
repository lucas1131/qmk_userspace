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

#include "tap_dance.c"

#define KC_SPR KC_LGUI  // super renamed
#define KC_CEDL RALT(KC_COMM)  // super renamed
enum custom_keycodes {
	CM_MAKE = SAFE_RANGE,
};

// Layers defines 
#define SL_IJKL MO(_ARROWS_IJKL) // MO(_ARROWS_IJKL) switch layer hold
#define SL_WASD MO(_ARROWS_WASD) // MO(_ARROWS_WASD) switch layer hold
#define TL_IJKL TG(_ARROWS_IJKL) // TG(_ARROWS_IJKL) switch layer toggle
#define TL_WASD TG(_ARROWS_WASD) // TG(_ARROWS_WASD) switch layer toggle

#define OS_SLCT OSL(_LAYER_SELECTOR)


// Mod tap defines
#define LALTBSPC LALT_T(KC_BSPC)
#define RALTBSPC RALT_T(KC_BSPC)
#define LALT_DEL LALT_T(KC_DEL)
#define RCT_SPC RCTL_T(KC_SPC)
#define LCT_SPC LCTL_T(KC_SPC)
#define SPR_ENT LGUI_T(KC_ENT)
#define SPR_IJKL LT(SL_IJKL, KC_SPR) // super and set arrows layout
#define SPR_WASD LT(SL_WASD, KC_SPR)

// Tap dance defines
#define SCLN_CLN TD(TAP_DANCE_TSCLN_HCLN)
#define SFTCPS TD(TAP_DANCE_LSHIFT_CAPS)
#define BSPDEL TD(TAP_DANCE_BSPC_DEL)
#define AACC TD(TAP_DANCE_A_AACC)
#define EACC TD(TAP_DANCE_E_EACC)
#define IACC TD(TAP_DANCE_I_IACC)
#define OACC TD(TAP_DANCE_O_OACC)
#define UACC TD(TAP_DANCE_U_UACC)
#define CACC TD(TAP_DANCE_C_CACC)

tap_dance_action_t tap_dance_actions[] = {
	[TAP_DANCE_TSCLN_HCLN] = TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLN),

    [TAP_DANCE_A_AACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_A, KC_TILD, 0),
	[TAP_DANCE_E_EACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_E, KC_CIRC, 0),
	[TAP_DANCE_I_IACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_I, KC_DQUO, 0),
	[TAP_DANCE_O_OACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_O, KC_TILD, 0),
	[TAP_DANCE_U_UACC] = TAP_DANCE_DOUBLE_TAP_ACCENT(KC_U, KC_DQUO, 0),
	[TAP_DANCE_C_CACC] = TAP_DANCE_TAP_DOUBLE_TAP(KC_C, KC_CEDL)
};

enum layer_number {
	_QWERTY = 0,
	_WORK,
	_GAME,
	_LAYER_SELECTOR,
	_ARROWS_IJKL,
	_ARROWS_WASD,
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
			SC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,     _______, KC_SLSH,    KC_N,    KC_M, KC_COMM,  KC_DOT, SC_RSPC,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
		    SL_IJKL, KC_LBRC,   KC_UP, OS_SLCT,LALT_DEL, LCT_SPC, SPR_ENT,      KC_ENT, RCT_SPC,RALTBSPC, KC_PSCR,   KC_UP, KC_RBRC,SPR_WASD,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
				     KC_LEFT, KC_DOWN, KC_RGHT,                                                           KC_LEFT, KC_DOWN, KC_RGHT    
		//'--------------------------------------------------------------|   |--------------------------------------------------------------'
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
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
					 _______, _______, _______,                                                           _______, _______, _______    
		//|--------------------------------------------------------------|   |--------------------------------------------------------------'
	),

	[_GAME] = LAYOUT(
		//,--------------------------------------------------------------|   |--------------------------------------------------------------.
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
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
			_______, AACC, _______, _______, _______, _______, _______,     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			_______, _______, _______, CACC, _______, _______, _______,     _______, _______,  KC_END, KC_DOWN, KC_PGDN, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			TL_IJKL, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
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
			_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
					 _______, _______, _______,                                                           _______, _______, _______    
		//|--------------------------------------------------------------|   |--------------------------------------------------------------'
	),

	[_LAYER_SELECTOR] = LAYOUT(
		//,--------------------------------------------------------------|   |--------------------------------------------------------------.
			 KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CM_MAKE,     CM_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, OS_SLCT, XXXXXXX, XXXXXXX,  KC_ENT,      KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
						 XXXXXXX, XXXXXXX, XXXXXXX,                                                           XXXXXXX, XXXXXXX, XXXXXXX    
		//|--------------------------------------------------------------|   |--------------------------------------------------------------'
	)
};

// void persistent_default_layer_set(uint16_t default_layer) {
//     eeconfig_update_default_layer(default_layer);
//     default_layer_set(default_layer);
// }

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
		case LALTBSPC:
		case RCT_SPC:
		case LCT_SPC:
		case KC_SCLN:
		    return 160;
        default:
            return TAPPING_TERM;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
	// rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
    switch (get_highest_layer(state)) {
    case _QWERTY:
        // rgblight_setrgb (0x00,  0x00, 0xFF);
    	break;
	case _WORK:
		break;
	case _GAME:
		break;
	case _LAYER_SELECTOR:
		break;
	case _ARROWS_IJKL:
		break;
	case _ARROWS_WASD:
		break;
    default: //  for any other layers, or the default layer
        // rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	tap_dance_action_t *tap_dance_action;

    switch (keycode) {
        case CM_MAKE:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -j 4 -kb " QMK_KEYBOARD " -km " QMK_KEYMAP);
            }
            return false;

        // tap dance for accents
        case TAP_DANCE_A_AACC:
		case TAP_DANCE_E_EACC:
		case TAP_DANCE_I_IACC:
		case TAP_DANCE_O_OACC:
		case TAP_DANCE_U_UACC:
        	tap_dance_action = &tap_dance_actions[TD_INDEX(keycode)];
        	if(!record->event.pressed && tap_dance_action->state.count && !tap_dance_action->state.finished){
        		tap_dance_double_tap_accent_data_t *tap_accent = (tap_dance_double_tap_accent_data_t *) tap_dance_action->user_data;
        		tap_code16(tap_accent->tap);
           	}
        	break;
    }

    return true;
}

void keyboard_post_init_user() {

#ifdef CONSOLE_ENABLE
	// Customise these values to desired behaviour
	debug_enable=true;
	debug_matrix=true;
	//debug_keyboard=true;
	//debug_mouse=true;
#endif
}
  