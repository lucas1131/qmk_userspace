
// 0 -- 37 keys
// 38 -- 42 led tape

#define LEFT_LED_INDEX(i) i
#define RIGHT_LED_INDEX(i) (i+43)
#define LED_BUFFER_AT(idx) (rgb_led_t *)&led[idx]

#define CAPS_WORD_LED_INDEX LEFT_LED_INDEX(14)

#define LAYER_0_LED_INDICATOR_INDEX       1 // LEFT_LED_INDEX(1)
#define LAYER_1_LED_INDICATOR_INDEX       45//(2+43) // RIGHT_LED_INDEX(2)
#define LAYER_2_LED_INDICATOR_INDEX       3 // LEFT_LED_INDEX(3)
#define LAYER_3_LED_INDICATOR_INDEX       4 // LEFT_LED_INDEX(4)
#define LAYER_4_LED_INDICATOR_INDEX       5 // LEFT_LED_INDEX(5)
#define LAYER_5_LED_INDICATOR_INDEX       6 // LEFT_LED_INDEX(6)
#define LAYER_5_LED_INDICATOR_INDEX_RIGHT 49//(6+43) // RIGHT_LED_INDEX(6)
#define LAYER_6_LED_INDICATOR_INDEX       48//(5+43) // RIGHT_LED_INDEX(5)
#define LAYER_7_LED_INDICATOR_INDEX       47//(4+43) // RIGHT_LED_INDEX(4)


//     9 10 11
//    18 17 16
// 22 23 24 25
#define SET_NUMPAD_LED_INDICATORS(color_mode, rgb) SET_NUMPAD_LED_INDICATORS_EXPANDED(color_mode, rgb)
#define SET_NUMPAD_LED_INDICATORS_EXPANDED(color_mode, r, g, b)                  \
    set##color_mode(r, g, b, LED_BUFFER_AT(9));                 \
    set##color_mode(r, g, b, LED_BUFFER_AT(10));                \
    set##color_mode(r, g, b, LED_BUFFER_AT(11));                \
                                                                                 \
    set##color_mode(r, g, b, LED_BUFFER_AT(18));                \
    set##color_mode(r, g, b, LED_BUFFER_AT(17));                \
    set##color_mode(r, g, b, LED_BUFFER_AT(16));                \
                                                                                 \
    set##color_mode(r, g, b, LED_BUFFER_AT(22));                \
    set##color_mode(r, g, b, LED_BUFFER_AT(23));                \
    set##color_mode(r, g, b, LED_BUFFER_AT(24));                \
    set##color_mode(r, g, b, LED_BUFFER_AT(25));


#define SET_IJKL_LED_INDICATORS(color_mode, rgb_arrows, rgb_control) \
    SET_IJKL_LED_INDICATORS_EXPANDED(color_mode, rgb_arrows, rgb_control)
#define SET_IJKL_LED_INDICATORS_EXPANDED(color_mode, r_arrows, g_arrows, b_arrows, r_control, g_control, b_control) \
    set##color_mode(r_arrows, g_arrows, b_arrows, LED_BUFFER_AT(10));    \
    set##color_mode(r_arrows, g_arrows, b_arrows, LED_BUFFER_AT(16));    \
    set##color_mode(r_arrows, g_arrows, b_arrows, LED_BUFFER_AT(17));    \
    set##color_mode(r_arrows, g_arrows, b_arrows, LED_BUFFER_AT(18));    \
    set##color_mode(r_arrows, g_arrows, b_arrows, LED_BUFFER_AT(24));    \
                                                                         \
    set##color_mode(r_control, g_control, b_control, LED_BUFFER_AT(18)); \
    set##color_mode(r_control, g_control, b_control, LED_BUFFER_AT(17)); \
    set##color_mode(r_control, g_control, b_control, LED_BUFFER_AT(16)); \
    set##color_mode(r_control, g_control, b_control, LED_BUFFER_AT(25));
