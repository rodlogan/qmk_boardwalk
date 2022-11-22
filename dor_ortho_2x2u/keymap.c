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

#include QMK_KEYBOARD_H

// Layer shorthand
enum layer {
    _BASE,
    _FN,
	_LWR,
	_RSE
};

enum keycodes {
  BASE = SAFE_RANGE,
  SEARCH,
  LOWER,
  RAISE,
  FN,
  COPYTAB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | MUTE   | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | ESC    | Q      | W      | E      | R      | T      | [/{    | ]/}    | Y      | U      | I      | O      | P      | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | TAB    | A      | S      | D      | F      | G      | PGUP   | INSERT | H      | J      | K      | L      | ENTER  |   \    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | PGDN   | ./>    | N      | M      | ?      | SHIFT  | UP     |SHFT/ENT|
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   |  FN   | LALT    |  LWR   |      SPACE      |  ENT   | RSE    | ALT    | RGUI   | HOME   | END    | CTRL   |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
	[_BASE] = LAYOUT_ortho_2x2u(
		KC_MUTE,    KC_1,      KC_2,      KC_3,      KC_4,        KC_5,        KC_VOLD,      KC_VOLU,		KC_6,      KC_7,       KC_8,       KC_9,       KC_0,        KC_BSPC,
		KC_ESC,     KC_Q,      KC_W,      KC_E,      KC_R,        KC_T,        KC_LBRC,      KC_RBRC,       KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,        KC_DEL,
		KC_TAB,     KC_A,      KC_S,      KC_D,      KC_F,        KC_G,        KC_PGUP,      KC_PSCR,       KC_H,      KC_J,       KC_K,       KC_L,       KC_SCLN,     KC_QUOT,
		KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,        KC_B,        KC_PGDN,      KC_DEL,        KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,     KC_SFTENT,
		KC_LCTL,    KC_LGUI,   KC_LALT,   TT(_FN),   MO(_LWR),          KC_SPACE,                  KC_SFTENT,          MO(_RSE),   KC_RGUI,    KC_HOME,    KC_END,      KC_RCTL
	),

	[_LWR] = LAYOUT_ortho_2x2u(
        KC_MPLY,    KC_F1,        KC_F2,        KC_F3,         KC_F4,        KC_F5,         KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,     KC_F11,      KC_F12,     KC_DEL,
        KC_GRV,     LALT(KC_C),   KC_UP,        SEARCH,        KC_WREF,      LCTL(KC_W),    _______,     _______,     _______,     _______,     KC_PSCR,    _______,     _______,    KC_BSLS,
        KC_CAPS,    KC_LEFT,      KC_DOWN,      KC_RIGHT,      KC_WSCH,      _______,       KC_MYCM,     _______,     _______,     _______,     _______,    _______,     _______,    KC_PGUP, 
        A(KC_RSFT), LCTL(KC_Z),   LCTL(KC_Y),   LCTL(KC_C),    RCS(KC_V),    COPYTAB,       KC_CALC,     KC_MUTE,     KC_VOLD,     KC_VOLU,     _______,    _______,     _______,    KC_RSFT,
        KC_LCTL,    _______,      _______,      _______,       _______,             _______,                   KC_DEL,             _______,     _______,      _______,    _______,    KC_RCTL
    ),

	[_RSE] = LAYOUT_ortho_2x2u(
        KC_GRV,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,      KC_F10,          KC_F11,        KC_F12,    KC_F13,
        _______,   _______,   KC_APP,    _______,   RESET,     _______,   _______,   _______,   _______,   _______,    KC_INS,          _______,       _______,   KC_BSLS,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MINS,    KC_EQL,          _______,       _______,   KC_BSLS,
        _______,   _______,   _______,   KC_CALC,   _______,   _______,   _______,   KC_MUTE,   KC_VOLD,   _______,    LCTL(KC_LSFT),   RCTL(KC_RSFT), _______,   KC_RSFT,
        _______,   _______,   _______,   _______,   _______,       KC_BSPC,               _______,         _______,    LCA(KC_DEL),     _______,       _______,   KC_RCTL
    ),
	
    [_FN] = LAYOUT_ortho_2x2u(
        KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_F3,      KC_F4,      KC_F5,      KC_F6,       KC_NUM,    KC_BACKSLASH,   KC_PAST,    KC_F10,     KC_F11,     KC_F12,    KC_DEL,
        KC_WH_U,    KC_WBAK,    KC_MS_U,    KC_WFWD,    KC_WREF,    _______,    _______,     KC_7,      KC_8,           KC_9,       KC_PSLS,    _______,    _______,   _______,
        KC_WH_D,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WSCH,    GUI_TOG,    KC_MINS,     KC_4,      KC_5,           KC_6,       KC_MINS,    _______,    _______,   _______, 
        KC_BTN1,    KC_ACL0,    KC_ACL1,    KC_ACL2,    LCTL(KC_T),    _______,    KC_PPLS,     KC_1,      KC_2,           KC_3,       KC_PPLS,    _______,    _______,   _______,
        KC_APP,     _______,    _______,    _______,    KC_BTN1,           KC_ENT,               KC_0,                  KC_DOT,     _______,    _______,    _______,   _______
    )
	
	
	
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case BASE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_BASE);
          }
          return false;
          break;
		case SEARCH:
		  if (record->event.pressed) {
			tap_code16(LCTL(KC_C));
			tap_code16(LCTL(KC_T));
			tap_code16(LCTL(KC_V));
			tap_code(KC_ENTER);
		  }
		  return false;
		  break;
		 case COPYTAB:
		  if (record->event.pressed) {
			tap_code16(LCTL(KC_A));
			tap_code16(LCTL(KC_C));
			tap_code16(KC_TAB);
			tap_code16(LCTL(KC_A));
			tap_code16(LCTL(KC_V));
		  }
		  return false;
		  break;
      }
    return true;
};