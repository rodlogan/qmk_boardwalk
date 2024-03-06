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

bool is_rtl=false;

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
  COPYTAB,
  PWD,
  EMAIL,
  WEMAIL,
  BR,
  PAREN,
  DQT,
  BS,
  LANG,
  BSWORD,
  DELWORD,
  DELBCPS,
  BRACKETS,
  CURLBRACKETS,
  LINEDEL,
  LINESELECT,
  SQOUTES,
  CAPSWORDKEY
  
};

enum tapdance {
	__START,
	CT_CLN,
	QMARK,
	REDO_CUT,
	UNDO_SELALL,
	PASTE,
	MUTE_PLY, 
	I_EXLM, 
	O_AT,
	SFTHOME,
	SFTEND,
	__END
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .--------------------------------------------------------------------------------------------------------------------------------.
     * | MUTE     | 1      | 2      | 3      | 4      | 5      |   VOL- |   VOL+ | 6      | 7      | 8      | 9      | 0      | BACKSP  |
     * |----------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | ESC      | Q      | W      | E      | R      | T      |  PGDN  | PGUP   | Y      | U      | I      | O      | P      | DEL     |
     * |----------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | TAB      | A      | S      | D      | F      | G      |XXXXXXXX|XXXXXXXX| H      | J      | K      | L      |   :;   |   "'    |
     * |----------+-- ------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LANG/SFT | Z      | X      | C      | V      | B      |  BSPC  |  DEL   | N      | M      |   <,   |   .>   |   ?/   |SHFT/ENT |
     * |-----------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL    | LGUI   |  LALT   | FN    |  LWR   |      SPACE      |   ENTER/SHIFT   |  RSE   | RGUI   |PRNTSCRN|CAPSWORD| CTRL    |
     * '--------------------------------------------------------------------------------------------------------------------------------'
     */
	[_BASE] = LAYOUT_ortho_2x2u(
		TD(MUTE_PLY),  	KC_1,      KC_2,      KC_3,      KC_4,        KC_5,        KC_VOLD,      		KC_VOLU,		 KC_6,      KC_7,       KC_8,       KC_9,       KC_0,        KC_BSPC,
		KC_ESC,     	KC_Q,      KC_W,      KC_E,      KC_R,        KC_T,        KC_PGDN,      		KC_PGUP,       KC_Y,      KC_U,        KC_I,       KC_O,       KC_P,        KC_DEL,
		KC_TAB,     	KC_A,      KC_S,      KC_D,      KC_F,        KC_G,        _______,      		_______,       KC_H,      KC_J,       KC_K,       KC_L,       TD(CT_CLN),     KC_QUOT,
		LT(0,KC_NO),  	KC_Z,      KC_X,      KC_C,      KC_V,        KC_B,        CTL_T(KC_BSPC),      KC_DEL,          KC_N,      KC_M,       KC_COMM,    KC_DOT,     TD(QMARK),     SC_SENT,
		KC_LCTL,    	KC_LGUI,   KC_LALT,   TT(_FN),   MO(_LWR),          KC_SPACE,                  			SC_SENT,          MO(_RSE),   KC_RGUI,    LSG(KC_S),    CAPSWORDKEY,      KC_RCTL
	),

    /* LWR Layer
     * .---------------------------------------------------------------------------------------------------------------------------------.
     * |Play/Pause| F1      |F2     |F3      |F4      | F5      |  F11   |  F12   | F6     | F7     | F8     | F9     | F10    | BACKSP  |
     * |----------+---------+--------+--------+--------+--------+---------+--------+--------+--------+--------+--------+-----------------|
     * | CAPSLOCK |  ALT+C |   UP   |WEBSRCH | NEWTAB |CLOSETAB |    [   |    ]   |PRNTSCRN |       |   INS  |        |        |    \	 |
     * |----------+---------+--------+--------+--------+--------+--------+--------+--------+--------+--------+------------------+--------|
     * | ALT+TAB  |  LEFT  |  DOWN  |  RIGHT |  FIND  |REOPENTAB|XXXXXXXX|XXXXXXXX|        |        |   ''   |   <>   |   ()   |   ""    |
     * |----------+-- ------+--------+--------+--------+--------+--------+--------+--------+--------+---------------------------+--------|
     * |SFT+ENTER |  UNDO  |  REDO  |  COPY  |  PASTE | COPYTAB | BSWORD |  DEL   |        |        |    ,   |   []   |   {}   |  BS+DEL |
     * |-----------+--------+--------+--------+--------+------------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL    | LSFT   |        |       |        |                   |   DELETE LINE   |        |        |        |        | CTRL    |
     * '---------------------------------------------------------------------------------------------------------------------------------'
     */

	[_LWR] = LAYOUT_ortho_2x2u(
        KC_MPLY,      KC_F1,        	 KC_F2,        KC_F3,         KC_F4,        KC_F5,         KC_F11,      KC_F12,      KC_F6,        KC_F7,       KC_F8,      KC_F9,        KC_F10,     		KC_BSPC,	
        KC_CAPS, 	  LALT(KC_C),   	 KC_UP,        SEARCH,        _______,   	_______,    KC_LBRC,     KC_RBRC,     KC_PSCR,      _______,     KC_INS,     _______,      _______,    		KC_BSLS,
        A(KC_TAB),    KC_LEFT,      	 KC_DOWN,      KC_RIGHT,      C(KC_F),      _______,     _______,     _______,     _______,      _______,     SQOUTES,    BS,     	     PAREN,      		DQT, 
        S(KC_ENTER),  TD(UNDO_SELALL),   TD(REDO_CUT), LCTL(KC_C),    TD(PASTE),    COPYTAB,       BSWORD,     KC_MYCM,     _______,      _______,     _______,    BRACKETS,	   CURLBRACKETS,    DELBCPS,
        KC_LCTL,      KC_LSFT,      	 _______,      _______,       _______,              _______,                    LINEDEL,            _______,     _______,    _______,      _______,    	    	KC_RCTL
    ),

	    /* FN Layer
     * .-------------------------------------------------------------------------------------------------------------------------------------.
     * |Play/Pause|MEDIA PRV|MEDIA NXT|  F3   | ALT+F4 | CTRL+F5 |        | NUMLOCK|    /   |   \    |    *    |         |         |BACKSPACE|
     * |----------+---------+---------+--------+--------+--------+---------+--------+--------+--------+--------+---------+-------------------|
     * | WHEELUP  |SFT+HOME |CTL+HOME |SFT+END| TABLEFT|         |        |   +    |    7   |    8   |     9   |    +    |         | DELETE  |
     * |----------+---------+---------+--------+--------+--------+--------+--------+--------+--------+---------+-------------------+---------|
     * | WHEELDWN |  HOME   | CTL+END |  END  |TABRIGHT|         |XXXXXXXX|XXXXXXXX|    4   |    5   |    6    |   -     |         |   |     |
     * |----------+-- ------+---------+--------+--------+--------+--------+--------+--------+--------+---------+-------------------+---------|
     * |   SHIFT  |  CTL+A  |  CTL+X  |LINESLC|CTLSFT+V|         |        |   -    |    1   |   2    |    3    |    .    |         |         |
     * |----------+---------+---------+--------+--------+-----------------+--------+--------+--------+------------------+----------+---------|
     * |   MENU   |         |SLCTLEFT |       |SLCTRGHT|       ENTER      |       NUM0      |   .    |         |         |         |         |
     * '-------------------------------------------------------------------------------------------------------------------------------------'
     */

	[_FN] = LAYOUT_ortho_2x2u(
        KC_MPLY,    KC_MPRV,    	KC_MNXT,    	  KC_F3,      	  A(KC_F4),        	C(KC_F5),      	_______,      KC_NUM,	 KC_PSLS,    	 KC_BACKSLASH,   KC_PAST,    _______,    	 _______,   KC_BSPC,
        KC_WH_U,    LSFT(KC_HOME),  LCTL(KC_HOME),    LSFT(KC_END),   _______,          _______,    	_______,      KC_PPLS,   KC_7,           KC_8,           KC_9,       KC_PPLS,        _______,   KC_DEL,
        KC_WH_D,    TD(SFTHOME),    LCTL(KC_END),     TD(SFTEND),     	  LINESELECT,       _______,        _______,      _______,   KC_4,      	 KC_5,           KC_6,       KC_MINS,        _______,   _______, 
        KC_LSFT, 	RCS(KC_TAB),    LCTL(KC_TAB),     LCTL(KC_T),     LCTL(KC_W),    	RCS(KC_T),    	_______,      KC_MINS,   KC_1,     	 	 KC_2,           KC_3,       _______,        _______,   _______,
        KC_APP,     _______,        RCS(KC_LEFT),     _______,        RCS(KC_RIGHT),             KC_ENT,           KC_0,         KC_DOT,    	 _______,    	 _______,    _______,    	 _______
    ),
	
	    /* RSE Layer
     * .-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |         |         |      | ALT+F4 |         |BRIGHTDN|BRIGHTUP|        |    [   |    ]    |    (    |    )    | BPWORD |
     * |----------+---------+--------+--------+--------+--------+---------+--------+--------+--------+--------+---------+------------------|
     * |          |         |WRKEMAIL| EMAIL |   BR   |         |    {   |   }    |    ~   |    `   |     !   |    @    |         | DELWORD|
     * |----------+---------+--------+--------+--------+--------+--------+--------+--------+--------+---------+-------------------+--------|
     * |QMKREBOOT |         |        |WINRGHT|        | GUI TOG |XXXXXXXX|XXXXXXXX|    _   |    -   |    +    |   =     |   *     |   |    |
     * |----------+-- ------+--------+--------+--------+--------+--------+--------+--------+--------+---------+-------------------+--------|
     * | QMKDEBUG |         |        |       |        |         |  CALC  | MYCMPTR|    $   |   #    |    &    |    %    |    \    |  CALC  |
     * |-----------+--------+--------+--------+--------+-----------------+--------+--------+--------+------------------+----------+--------|
     * | QMK BOOT |         |        |       |        |     BACKSPACE    |       PWD       |        |CTLALTDEL|LCTL+LSFT|RCTL+RSFT|        |
     * '-----------------------------------------------------------------------------------------------------------------------------------'
     */
	
	[_RSE] = LAYOUT_ortho_2x2u(
        _______,      _______,   	  _______,   	  _______,   		A(KC_F4),   _______,     	KC_BRID,  		 KC_BRIU,     		  _______,    KC_LBRC,     	 KC_RBRC,       KC_LPRN,        KC_RPRN,   		BSWORD,
        _______,     _______,    	  WEMAIL,    	  EMAIL,     		BR,         _______,		KC_LCBR,     	 KC_RCBR,       	  KC_TILD,    KC_GRV,   	 KC_EXLM,       KC_AT,         _______,     	DELWORD,
        QK_RBT,      _______,   	  _______,  	  LGUI(KC_RIGHT),   _______,    GUI_TOG,   	    _______,   		 _______,             KC_UNDS,    KC_MINS, 		 KC_PLUS,       KC_EQL,        KC_ASTR,  		KC_PIPE,
        DB_TOGG,     _______,   	  _______,   	  _______,   		_______,    _______,   		KC_CALC,         DELWORD,             KC_DLR,    KC_HASH,        KC_AMPR,   	KC_PERC, 	   KC_BSLS,   		KC_CALC,
        QK_BOOT,     _______,   	  _______,   	  _______,   		_______,           KC_BSPC,                             PWD,            _______,       LCA(KC_DEL),  LCTL(KC_LSFT),  RCTL(KC_RSFT),   _______
    )
};



void langchange(void) {
				is_rtl = !is_rtl;
				tap_code16(A(KC_RSFT));
};


void langcheck(const char *str) {
			  if (is_rtl) {
				langchange();
				send_string(str);			
				langchange();
			  } else {
				send_string(str);
			  }
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	 tap_dance_action_t *action;
	 
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
		 case BSWORD:
		   if (record->event.pressed) {
			   tap_code16(RCS(KC_LEFT));
			   tap_code16(KC_BSPC);
		   }
		   return false; 
		   break;
		 case DELWORD:
		   if (record->event.pressed) {
			   tap_code16(RCS(KC_RIGHT));
			   tap_code16(KC_DEL);
		   }
		   return false; 
		   break;
		 case DELBCPS:
		   if (record->event.pressed) {
			   tap_code16(KC_BSPC);
			   tap_code16(KC_DEL);
		   }
		   return false; 
		   break;
		 case WEMAIL:
		   if (record->event.pressed) {
			   langcheck("dorgol@checkpoint.com");
		   }
		   return false;
		   break;
		 case EMAIL:
		   if (record->event.pressed) {
			   langcheck("dor.golan@gmail.com");
		   }
		   return false;
		   break;
		 case BR:
		   if (record->event.pressed) {
			   langcheck("Best regards,");
		   }
		   return false;
		   break;
		 case PWD:
		   if (record->event.pressed) {
			  langcheck("fillme");
		  }
		  return false;
		  break;
		 case PAREN:
		   if (record->event.pressed) {
			   langcheck("()");
			   if (is_rtl) {
				   tap_code16(KC_RIGHT);
			   } else {
				   tap_code16(KC_LEFT);
			   }
		   }
		   return false;
		   break;
		   case BRACKETS:
		   if (record->event.pressed) {
			   langcheck("[]");
			   if (is_rtl) {
				   tap_code16(KC_RIGHT);
			   } else {
				   tap_code16(KC_LEFT);
				   
			   }
		   }
		   return false;
		   break;
		   case CURLBRACKETS:
		   if (record->event.pressed) {
			   langcheck("{}");
			   if (is_rtl) {
				   tap_code16(KC_RIGHT);
			   } else {
				   tap_code16(KC_LEFT);
				   
			   }
		   }
		   return false;
		   break;
		  case DQT:
		   if (record->event.pressed) {
			   langcheck("\"\"");
			   if (is_rtl) {
				   tap_code16(KC_RIGHT);
			   } else {
				   tap_code16(KC_LEFT);
			   }
		   }
		   return false;
		   break;
		  case BS:
		   if (record->event.pressed) {
			   langcheck("<>");
			   if (is_rtl) {
				   tap_code16(KC_RIGHT);
			   } else {				   
				   tap_code16(KC_LEFT);
			   }
		   }
		   return false;
		   break;
		  case SQOUTES:
		   if (record->event.pressed) {
			   langcheck("''");
			   if (is_rtl) {
				   tap_code16(KC_RIGHT);
			   } else {				   
				   tap_code16(KC_LEFT);
			   }
		   }
		   return false;
		   break;
		 case LINEDEL:
		   if (record->event.pressed) {
				   tap_code16(KC_HOME);	   
				   tap_code16(LSFT(KC_END));
				   tap_code16(KC_DEL);	
			   }
		   return false;
		   break;
		   case LINESELECT:
		   if (record->event.pressed) {
				   tap_code16(KC_HOME);	   
				   tap_code16(LSFT(KC_END));
			   }
		   return false;
		   break;
		 case LANG:
			if (record->event.pressed) {
				is_rtl = !is_rtl;
				tap_code16(A(KC_RSFT));
			}
		  
		  return false;
		  break;
		case LT(0,KC_NO):
            if (record->event.pressed) {
                if (record->tap.count) {
                    langchange(); // On tap
                } else {
                    register_code16(KC_LSFT); // On hold
                }
            } else {
                unregister_code16(KC_LSFT); // On release
            }
            return false;
			break;
		case CAPSWORDKEY:
			if (record->event.pressed) {
				   caps_word_on();
			   }
		   return false;
		   break;
        case TD(__START) ... TD(__END):  
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}


// TAP DANCE code 

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_SCLN),
	[QMARK] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUES, KC_SLSH),
	[SFTHOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, LSFT(KC_HOME)),
	[SFTEND] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, LSFT(KC_END)),
	[REDO_CUT] = ACTION_TAP_DANCE_TAP_HOLD(C(KC_Y), C(KC_X)),
	[UNDO_SELALL] = ACTION_TAP_DANCE_TAP_HOLD(C(KC_Z), C(KC_A)),
	[PASTE] = ACTION_TAP_DANCE_TAP_HOLD(C(KC_V), RCS(KC_V)),
	[MUTE_PLY] = ACTION_TAP_DANCE_TAP_HOLD(KC_MUTE, KC_MPLY),
	[I_EXLM] = ACTION_TAP_DANCE_TAP_HOLD(KC_I, KC_EXLM),
	[O_AT] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, KC_AT),
};
