/*
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

// Layer tapping toggle 
#define TAPPING_TOGGLE 2

// Layer limit - test
#define LAYER_STATE_8BIT

// mouse keys
#define MK_3_SPEED
#define MK_C_OFFSET_UNMOD 6
#define MK_C_INTERVAL_UNMOD 0
#define MK_C_OFFSET_0 8
#define MK_C_INTERVAL_0 0
#define MK_C_OFFSET_1 16
#define MK_C_INTERVAL_1 0
#define MK_C_OFFSET_2 22
#define MK_C_INTERVAL_2 0

// Caps Word 
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// disabling stuff
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

// disabling rgb

#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE