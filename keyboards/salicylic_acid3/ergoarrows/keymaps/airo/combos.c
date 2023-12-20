/* Combo defines */
enum combo_events {
  LEFT_ENTER,
};

const uint16_t PROGMEM left_hand_enter[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
combo_t key_combos[] = {
    [LEFT_ENTER] = COMBO(left_hand_enter, KC_ENT),
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