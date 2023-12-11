/* Tap dance defines */
enum tap_dance_definitions {
    TAP_DANCE_TSCLN_HCLN,
    TAP_DANCE_LSQB_LCBR,
    TAP_DANCE_RSQB_RCBR,
    TAP_DANCE_C_CEDL,
    TAP_DANCE_A_ACC,
    TAP_DANCE_E_ACC,
    TAP_DANCE_I_ACC,
    TAP_DANCE_O_ACC,
    TAP_DANCE_U_ACC,

    // not working seems to be incompatible
    TAP_DANCE_BACKSPACE_LCTRL_DEL,
    TAP_DANCE_LPAREN_LSHIFT_CWORD,
    TAP_DANCE_RPAREN_RSHIFT_CWORD,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    // TD_TRIPLE_TAP,
    // TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

typedef struct {
    uint16_t tap;
    uint16_t dtap_accent;
} tap_dance_double_tap_accent_data_t;

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t double_tap;
    uint16_t double_hold;
    uint16_t key;
} tap_dance_quad_action_data_t;

// Function definitions
td_state_t cur_dance(tap_dance_state_t *state);
void tap_dance_quad_action_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_quad_action_reset(tap_dance_state_t *state, void *user_data);

// Action macros
#define TAP_DANCE_QUAD_TAP_ACTION(tap, hold, double_tap, double_hold) \
    { \
        .fn = {NULL, tap_dance_quad_action_finished, tap_dance_quad_action_reset}, \
        .user_data = (void *)&((tap_dance_quad_action_data_t){tap, hold, double_tap, double_hold, 0}), \
    }
 
#define TAP_DANCE_DOUBLE_TAP_ACCENT(tap, dtap_accent) \
    { \
        .fn = {NULL, tap_dance_double_tap_accent_finished, tap_dance_double_tap_accent_reset}, \
        .user_data = (void *)&((tap_dance_double_tap_accent_data_t){tap, dtap_accent}), \
    }

#define TAP_DANCE_TAP_HOLD(tap, hold) TAP_DANCE_QUAD_TAP_ACTION(tap, hold, 0, 0)
#define TAP_DANCE_TAP_DOUBLE_TAP(tap, double_tap) TAP_DANCE_QUAD_TAP_ACTION(tap, 0, double_tap, 0)

// Quad action dance
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    // if (state->count == 3) {
    //     if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
    //     else return TD_TRIPLE_HOLD;
    // } else return TD_UNKNOWN;
}

static td_tap_t tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// NOTE: state->pressed means key is being held, has nothing to do with a tap
void tap_dance_quad_action_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_action_data_t *action = (tap_dance_quad_action_data_t *) user_data;
    tap_state.state = cur_dance(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            // SEND_STRING("TD_SINGLE_TAP") ;
            register_code16(action->tap); 
            action->key = action->tap;
            break;
        case TD_SINGLE_HOLD:
            // SEND_STRING("TD_SINGLE_HOLD") ;
            register_code16(action->hold); 
            action->key = action->hold;
            break;
        case TD_DOUBLE_TAP:
            // SEND_STRING("TD_DOUBLE_TAP") ;
            register_code16(action->double_tap); 
            action->key = action->double_tap;
            break;
        case TD_DOUBLE_HOLD:
            // SEND_STRING("TD_DOUBLE_HOLD") ;
            register_code16(action->double_hold); 
            action->key = action->double_hold;
            break;
        // Double letter typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP:
            // SEND_STRING("TD_DOUBLE_SINGLE_TAP") ;
            tap_code16(action->tap); 
            register_code16(action->tap); 
            action->key = action->tap;
            break;
        default: 
            break;
    }
}

void tap_dance_quad_action_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_quad_action_data_t *action = (tap_dance_quad_action_data_t *) user_data;
    switch (tap_state.state) {
        case TD_SINGLE_TAP: 
            unregister_code16(action->tap); 
            action->key = 0;
            break;
        case TD_SINGLE_HOLD: 
            unregister_code16(action->hold); 
            action->key = 0;
            break;
        case TD_DOUBLE_TAP: 
            unregister_code16(action->double_tap); 
            action->key = 0;
            break;
        case TD_DOUBLE_HOLD: 
            unregister_code16(action->double_hold); 
            action->key = 0;
            break;
        case TD_DOUBLE_SINGLE_TAP: 
            unregister_code16(action->tap); 
            action->key = 0;
            break;
        default: break;
    }
    tap_state.state = TD_NONE;
}

// Accent dance
void tap_dance_double_tap_accent_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_double_tap_accent_data_t *tap_accent = (tap_dance_double_tap_accent_data_t *) user_data;
    unregister_code16(tap_accent->tap);
}

void tap_dance_double_tap_accent_finished(tap_dance_state_t *state, void *user_data){
    tap_dance_double_tap_accent_data_t *tap_accent = (tap_dance_double_tap_accent_data_t *) user_data;
    if(state->pressed) {
        register_code16(tap_accent->tap);
        return;
    }

    if(state->count == 1){
        register_code16(tap_accent->tap);
        reset_tap_dance(state);
    } else if(state->count == 2) {
        if(!state->interrupted){
            tap_code16(tap_accent->dtap_accent);
        }
        register_code16(tap_accent->tap);
        reset_tap_dance(state);
    }
}
/* Tap dance */

/* tesing area


asd

aaããçççãaaaaaaaaaa










*/