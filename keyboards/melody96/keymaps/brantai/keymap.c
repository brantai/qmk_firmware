#include QMK_KEYBOARD_H
#define KC_MCTL LCTL(KC_UP)

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    LOCK_SCREEN,
    BRT_UP,
    BRT_DN,
    EMOJI
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case LOCK_SCREEN:
                SEND_STRING(SS_LGUI(SS_LCTRL("q")));
            case BRT_UP:
                SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_F1))));
            case BRT_DN:
                SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_F2))));
            case EMOJI:
                SEND_STRING(SS_LCTRL(SS_LGUI(" ")));
        return false;
        }
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0, default layer
____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| ESC*   |   F1   |   F2   |   F3   |   F4   |  MRWD  |  MPLY  |  MFFD  |  MCTL  |   F9   |  F10   |  F14   |  F15   |  MUTE  | VOLDWN | VOLUP  |  HOME  |  END   |LCK_SCR |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        | BACK   |        |        |        |        |
|  ~`    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   |   \    | SPACE  |    +   |   /    |  *     |   -    |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |             |        |        |        |   PG   |
|    TAB     |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \      |   7    |   8    |   9    |   UP   |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |   ;    |   '    |                    |        |        |        |   PG   |
|   MO(1)      |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |       ENTER        |   4    |   5    |   6    |   DN   |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |   ,    |    .   |   /    |                |        |        |        |        |        |
|  SHIFT  |  SHIFT |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |       SHIFT    |   UP   |   1    |   2    |   3    | ENTER  |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
| CTRL     |   L ALT  | L GUI    |                      SPACE                             | R GUI  | R ALT  |  DEL   |  LEFT  |  DOWN  | RIGHT  |   0    |   .    | ENTER  |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
*/



	LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_MRWD,   KC_MPLY,   KC_MFFD,   KC_MCTL,   KC_F9,   KC_F10,  KC_F14,  KC_F15,  KC__MUTE, KC__VOLDOWN, KC__VOLUP,  KC_HOME, KC_END, LOCK_SCREEN,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_PPLS, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_7,   KC_8,   KC_9,   KC_PGUP,
    MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_4,   KC_5,   KC_6,   KC_PGDN,
    LSFT_T(KC_CAPS), LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_1,   KC_2,   KC_3,   KC_PENT,
    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT,   KC_DEL,   KC_LEFT, KC_DOWN, KC_RGHT, KC_0,   KC_DOT, KC_PENT),



  /* Layer 1, function layer
____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| RESET  |        |        |        |        |   F5   |   F6   |   F7   |   F8   |        |        |  F11   |  F12   |        |        |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |        |        |        |        |        |        | DEL    |        |        |        |  BUP   |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |        |        |        |        |        |        |        |        |        |        |        |        |             |        |        |        |        |
|            |        |        |        |        |        |        |        |        |        |        |        |        |             |        |        |        |  BDN   |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
|              |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |        |        |        |                |   PG   |        |        |        |        |
|         |        |        |        |        |        |        |        |        |        |        |        |                |   UP   |        |        |        |        |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |   PG   |        |        |        |        |
|          |          |          |                                                        |        |        |  EMOJI |  HOME  |   DN   |   END  |        |        |        |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
BL_TOGG, BL_DEC, BL_INC changes the in-switch LEDs
*/


	LAYOUT(
    RESET,   _______, _______, _______, _______, KC_F5, KC_F6, KC_F7, KC_F8, _______, _______, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, _______, _______, _______, M(BRT_UP),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M(BRT_DN),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,  KC_PGUP, _______, _______, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, EMOJI, KC_HOME, KC_PGDN, KC_END, _______, _______, _______),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	return MACRO_NONE;
}
