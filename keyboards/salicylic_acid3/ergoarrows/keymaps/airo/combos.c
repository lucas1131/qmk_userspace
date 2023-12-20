/* Combo defines */
const uint16_t PROGMEM left_hand_enter[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
combo_t key_combos[] = {
    COMBO(left_hand_enter, KC_ENT),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if(get_highest_layer(layer_state) == _GAME) return false;
    return true;
}


/* Testing area 


~a~aã

TD_DOUBLE_SINGLE_TAP))a

*/