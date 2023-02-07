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
	_RSE,
	_GM
};

enum keycodes {
  BASE = SAFE_RANGE,
  SEARCH,
  LOWER,
  RAISE,
  FN,
  COPYTAB,
  PWD,
  EMAIL,
  WEMAIL,
  BR,
  PAREN,
  DQT,
  BS,
  LANG,
  PARCHECK
  
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
		KC_LCTL,    KC_LGUI,   KC_LALT,   TT(_FN),   MO(_LWR),          KC_SPACE,                  KC_SFTENT,          MO(_RSE),    KC_RGUI,    KC_HOME,    KC_END,      KC_RCTL
	),

	[_LWR] = LAYOUT_ortho_2x2u(
        KC_MEDIA_PLAY_PAUSE,    KC_F1,        KC_F2,        KC_F3,         KC_F4,        KC_F5,         KC_F11,      KC_F12,      KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,    KC_BSPC,
        KC_GRV,     			LALT(KC_C),   KC_UP,        SEARCH,        LCTL(KC_T),   LCTL(KC_W),    _______,     _______,     KC_INS,      _______,     KC_PSCR,    _______,     _______,    KC_BSLS,
        KC_CAPS,    			KC_LEFT,      KC_DOWN,      KC_RIGHT,      KC_WREF,      RCS(KC_T),     KC_MYCM,     _______,     _______,     _______,     _______,    _______,     _______,    KC_PGUP, 
        KC_LSFT,    			LCTL(KC_A),   LCTL(KC_X),   LCTL(KC_C),    LCTL(KC_V),    COPYTAB,       KC_CALC,     KC_MUTE,     KC_VOLD,    KC_VOLU,     BS,   		PARCHECK,   	 DQT,        KC_RSFT,
        KC_LCTL,    			_______,      _______,      _______,       _______,             _______,                   KC_DEL,             _______,     _______,    _______,     _______,    KC_RCTL
    ),

	[_RSE] = LAYOUT_ortho_2x2u(
        KC_GRV,      _______,   _______,   _______,   _______,   _______,     	_______,  		 _______,     		   _______,    _______,     		 _______,     _______,        _______,   		KC_BSPC,
        _______,     _______,   WEMAIL,    EMAIL,     BR,        _______,			LCTL(KC_LSFT),   RCTL(KC_RSFT),        _______,    _______,   		 KC_INS,          _______,        PWD,       		KC_BSLS,
        _______,     BS,   		PAREN,     DQT,   	  _______,   TG(_GM),   		_______,   		 _______,              KC_PLUS,    KC_MINS,   		 KC_EQL,          KC_HASH,        KC_AMPR,   		KC_PERC,
        QK_RBT,      _______,   _______,   KC_CALC,   _______,   GUI_TOG,   		_______,    	 KC_MUTE,              KC_ASTR,    KC_UNDS,          KC_DQT,   		  KC_PIPE, 	      KC_BSLS,   		KC_RSFT,
        QK_BOOT,     _______,   _______,   _______,   TG(_GM),           KC_BSPC,                             _______,           _______,    LCA(KC_DEL),               LCTL(KC_LSFT),  RCTL(KC_RSFT),    KC_RCTL
    ),
	
	[_FN] = LAYOUT_ortho_2x2u(
        KC_MPLY,    KC_MPRV,    	KC_MNXT,    	  KC_F3,      	  KC_F4,        	KC_F5,      	KC_F6,        KC_NUM,    KC_BACKSLASH,   KC_PAST,    KC_F10,     KC_F11,     KC_F12,    KC_BSPC,
        KC_WH_U,    LSFT(KC_HOME),  LCTL(KC_HOME),    LSFT(KC_END),   KC_WREF,      	_______,    	_______,      KC_7,      KC_8,           KC_9,       KC_PSLS,    _______,    _______,   KC_DEL,
        KC_WH_D,    KC_HOME,    	LCTL(KC_END),     KC_END,     	  RCS(KC_TAB),      LCTL(KC_TAB),   KC_MINS,      KC_4,      KC_5,           KC_6,       KC_MINS,    _______,    _______,   _______, 
        LANG, LCTL(KC_Z),     LCTL(KC_Y),   	  LCTL(KC_C),     RCS(KC_V),    	_______,    	KC_PPLS,     KC_1,      KC_2,           KC_3,       KC_PPLS,    _______,    _______,   _______,
        KC_APP,     _______,        RCS(KC_LEFT),         _______,            RCS(KC_RIGHT),           KC_ENT,      KC_0,                KC_DOT,     _______,    _______,    _______,   _______
    ),
	
	[_GM] = LAYOUT_ortho_2x2u(
        KC_MUTE,    KC_1,      KC_2,      KC_3,      KC_4,        KC_5,        KC_VOLD,      KC_VOLU,		KC_6,      KC_7,       KC_8,       KC_9,       KC_0,        KC_BSPC,
		KC_ESC,     KC_Q,      KC_W,      KC_E,      KC_R,        KC_T,        KC_LBRC,      KC_RBRC,       KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,        KC_DEL,
		KC_TAB,     KC_A,      KC_S,      KC_D,      KC_F,        KC_G,        KC_PGUP,      KC_HOME,       KC_H,      KC_J,       KC_K,       KC_L,       KC_SCLN,     KC_QUOT,
		KC_LSFT,    KC_Z,      KC_X,      KC_C,      KC_V,        KC_B,        KC_PGDN,      KC_END,        KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,     KC_SFTENT,
		KC_LCTL,    KC_F13,    KC_RCTL,   KC_LALT,   MO(_LWR),          KC_SPACE,                  KC_SFTENT,          MO(_RSE),   KC_RGUI,    KC_HOME,    TG(_GM),      KC_RCTL
    )

};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	bool eng=true;
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
			tap_code16(KC_ENTER);
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
		   case WEMAIL:
		   if (record->event.pressed) {
			   SEND_STRING("______");
		   }
		   return false;
		   break;
		  case EMAIL:
		   if (record->event.pressed) {
			   SEND_STRING("______");
		   }
		   return false;
		   break;
		  case PWD:
		   if (record->event.pressed) {
			  SEND_STRING("______");
		   }
		   return false;
		   break;
		  case BR:
		   if (record->event.pressed) {
			   SEND_STRING("Best regards,");
		   }
		   return false;
		   break;
		  case PAREN:
		   if (record->event.pressed) {
			   SEND_STRING("()");
			   tap_code16(KC_LEFT);
			   
		   }
		   return false;
		   break;
		  case DQT:
		   if (record->event.pressed) {
			   SEND_STRING("\"\"");
			   tap_code16(KC_LEFT);
		   }
		   return false;
		   break;
		  case BS:
		   if (record->event.pressed) {
			   SEND_STRING("<>");
			   tap_code16(KC_LEFT);
		   }
		   return false;
		   break;
		 
		 case LANG:
		  if (record->event.pressed) {
			  if (eng){
				tap_code16(A(KC_RSFT));
				eng=false;
			} else {
				tap_code16(A(KC_RSFT));
				eng=true;
			}
		  }
		  return false;
		  break;
		 case PARCHECK:
		  if (record->event.pressed) {
			  if (eng) {
				SEND_STRING("()");
			   tap_code16(KC_LEFT);
		  } else {
			  SEND_STRING("()");
			  tap_code16(KC_LEFT);
			  eng=true;
			}
		  }
		  return false;
		}
      
    return true;
};
