/* Copyright 2021-2024 Salicylic_acid3
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
#define ONESHOT_TIMEOUT 500
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 65

#define ENABLE_COMPILE_KEYCODE
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD // This isn't working very well with modtap on shifts

/* Optimization flags */
#define LAYER_STATE_8BIT
// #define EXTRA_SHORT_COMBOS // 6 keys combos -- no relevant size reduction
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE



/* Led configs */
	#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
	#undef RGBLIGHT_HUE_STEP
	#define RGBLIGHT_HUE_STEP 8
	#undef RGBLIGHT_SAT_STEP
	#define RGBLIGHT_SAT_STEP 5
	#undef RGBLIGHT_VAL_STEP
	#define RGBLIGHT_VAL_STEP 5
	#undef RGBLIGHT_LIMIT_VAL
	#define RGBLIGHT_LIMIT_VAL 100
	#define RGBLIGHT_DEFAULT_HUE 0
	#define RGBLIGHT_DEFAULT_SAT 128
	#define RGBLIGHT_DEFAULT_VAL 75
	#define RGBLIGHT_DEFAULT_SPD 0

	#define RGBLIGHT_DEFAULT_ON false

	#define RGBLIGHT_DISABLE_KEYCODES
	#define RGBLIGHT_SLEEP

	#define RGBLIGHT_SPLIT
	#define RGBLIGHT_LED_COUNT 86

	// RGB indicators on split keyboards will require state information synced to the slave half (e.g. #define SPLIT_LAYER_STATE_ENABLE). See data sync options for more details.
	// https://docs.qmk.fm/#/feature_split_keyboard?id=data-sync-options
	#define SPLIT_TRANSPORT_MIRROR
	#define SPLIT_LAYER_STATE_ENABLE
	#define SPLIT_MODS_ENABLE
/* END Led configs */

