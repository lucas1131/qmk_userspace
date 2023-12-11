/* Copyright 2021-2023 Salicylic_acid3
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Select hand configuration */

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 160
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 3

#define ENABLE_COMPILE_KEYCODE
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* Led underglow - mainly for layer lightning */
 #define WS2812_DI_PIN D3
 #define BACKLIGHT_PIN D3
 #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
 #define RGBLIGHT_LAYERS
 #define RGBLIGHT_LAYER_BLINK
 #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
 #define RGBLIGHT_MAX_LAYERS 8
  // #define RGBLED_NUM 86
  // #define RGBLED_SPLIT { 43, 43 }
 // #define RGBLIGHT_SAT_STEP 25
 //  #define RGBLIGHT_HUE_STEP 12
 //  #define RGBLIGHT_VAL_STEP 12


 #define RGBLIGHT_DEFAULT_HUE 	0 //(red)
 #define RGBLIGHT_DEFAULT_SAT 	UINT8_MAX //(255)
 #define RGBLIGHT_DEFAULT_VAL 	RGBLIGHT_LIMIT_VAL
 #define RGBLIGHT_DEFAULT_SPD 	0
 #define RGBLIGHT_DEFAULT_ON 	true

 /* WS2812 driver configuration*/
  #define WS2812_TIMING 1250
  #define WS2812_T1H 900
  #define WS2812_T0H 350
  #define WS2812_TRST_US 280
  // #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
 /* END WS2812 driver configuration*/
/* END Led underglow */
