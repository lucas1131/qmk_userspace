#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

/* Combo defines */
enum combo_events {
	LEFT_ENTER,
	LEFT_DEl,
	SWITCH_LANGUAGE,
	JP_SET_HIRAGANA,
	JP_SET_KATAKANA,
};

const uint16_t PROGMEM left_hand_enter[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM left_hand_del[]   = {KC_Q, KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM switch_language[] = {KC_COMBO, KC_J, COMBO_END};
const uint16_t PROGMEM jp_set_hiragana[] = {KC_COMBO, KC_H, COMBO_END};
const uint16_t PROGMEM jp_set_katakana[] = {KC_COMBO, KC_K, COMBO_END};
combo_t key_combos[] = {
    [LEFT_ENTER] = COMBO(left_hand_enter, KC_ENT),
    [LEFT_DEl] = COMBO(left_hand_del, KC_DEL),
    [SWITCH_LANGUAGE] = COMBO(switch_language, IME_INPT),
    [JP_SET_HIRAGANA] = COMBO(jp_set_hiragana, HIRAGANA),
    [JP_SET_KATAKANA] = COMBO(jp_set_katakana, KATAKANA),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if(get_highest_layer(layer_state) == _GAME) return false;
    return true;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  	switch(combo_index) {
	default: 
  		break;
  	}
}


/* Testing area 









*/