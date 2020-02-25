/* A standard layout for the Dactyl Manuform 5x6 Keyboard */
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Custom keycodes can be mapped into the keycodes table
enum custom_keycodes {
    GOLET = SAFE_RANGE,  // For golang:  ':='
    MT_LGUI_LBRC,        // Left GUI hold, tap = {
    LT_RAISE_LPRN,       // RAISE on hold, tap = '('
    MT_RGUI_RBRC,        // Right GUI hold, tap = }
    LT_LOWER_RPRN        // LOWER on hold, tap = ')'
};

// When clicks happen this function takes care of custom handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_mt_lgui_lbrc_timer;
    static uint16_t my_lt_raise_lprn_timer;
    static uint16_t my_mt_rgui_rbrc_timer;
    static uint16_t my_lt_lower_rprn_timer;

    // these flags are there to ensure that if you press CMD-v quickly it doesn't also send a bracket
    static bool mt_lgui_lbrc_exclusive;
    static bool lt_raise_lprn_exclusive;
    static bool mt_rgui_rbrc_exclusive;
    static bool lt_lower_rprn_exclusive;

    switch (keycode) {
        case GOLET:
            if (record->event.pressed) {
                SEND_STRING(":=");
            }
            return false;  // keypress handled
        case MT_LGUI_LBRC:
            if (record->event.pressed) {
                my_mt_lgui_lbrc_timer  = timer_read();
                mt_lgui_lbrc_exclusive = true;
                register_code(KC_LGUI);

                lt_raise_lprn_exclusive = false;
                mt_rgui_rbrc_exclusive  = false;
                lt_lower_rprn_exclusive = false;
            } else {
                unregister_code(KC_LGUI);
                if (timer_elapsed(my_mt_lgui_lbrc_timer) < TAPPING_TERM && mt_lgui_lbrc_exclusive) {
                    SEND_STRING("{");
                }
            }
            return false;  // keypress handled
        case LT_RAISE_LPRN:
            if (record->event.pressed) {
                my_lt_raise_lprn_timer  = timer_read();
                lt_raise_lprn_exclusive = true;
                layer_off(_QWERTY);
                layer_off(_LOWER);
                layer_on(_RAISE);
                mt_lgui_lbrc_exclusive  = false;
                mt_rgui_rbrc_exclusive  = false;
                lt_lower_rprn_exclusive = false;
            } else {
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_on(_QWERTY);
                if (timer_elapsed(my_lt_raise_lprn_timer) < TAPPING_TERM && lt_raise_lprn_exclusive) {
                    SEND_STRING("(");
                }
            }
            return false;  // keypress handled
        case MT_RGUI_RBRC:
            if (record->event.pressed) {
                my_mt_rgui_rbrc_timer  = timer_read();
                mt_rgui_rbrc_exclusive = true;
                register_code(KC_RGUI);
                mt_lgui_lbrc_exclusive  = false;
                lt_raise_lprn_exclusive = false;
                lt_lower_rprn_exclusive = false;
            } else {
                unregister_code(KC_RGUI);
                if (timer_elapsed(my_mt_rgui_rbrc_timer) < TAPPING_TERM && mt_rgui_rbrc_exclusive) {
                    SEND_STRING("}");
                }
            }
            return false;  // keypress handled
        case LT_LOWER_RPRN:
            if (record->event.pressed) {
                my_lt_lower_rprn_timer  = timer_read();
                lt_lower_rprn_exclusive = true;
                layer_off(_QWERTY);
                layer_off(_RAISE);
                layer_on(_LOWER);
                mt_lgui_lbrc_exclusive  = false;
                lt_raise_lprn_exclusive = false;
                mt_rgui_rbrc_exclusive  = false;
            } else {
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_on(_QWERTY);
                if (timer_elapsed(my_lt_lower_rprn_timer) < TAPPING_TERM && lt_lower_rprn_exclusive) {
                    SEND_STRING(")");
                }
            }
            return false;  // keypress handled
        default:
            mt_lgui_lbrc_exclusive  = false;
            lt_raise_lprn_exclusive = false;
            mt_rgui_rbrc_exclusive  = false;
            lt_lower_rprn_exclusive = false;
    }
    return true;
};

/* Leader support
LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_S) {
            // Anything you can do in a macro.
            SEND_STRING("spotify");
        }
    }
}
*/

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] = LAYOUT_5x6(
     _______, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,_______,
     KC_GRV , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_TAB , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     _______, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                         MT(MOD_LSFT, KC_ESC),KC_BSPC,                        KC_SPC, MT(MOD_RCTL, KC_ENT),  // enter when tapped, control when held
                    LT_RAISE_LPRN ,LT(LOWER, KC_LBRC),                        KC_RBRC, LT_LOWER_RPRN,
                   MT_LGUI_LBRC,MT(MOD_LALT, KC_LBRC),                        KC_RBRC, MT_RGUI_RBRC
  ),

  [_LOWER] = LAYOUT_5x6(
     //  this side is for misc stuff                                         // This is the numpad
     _______,_______,_______,_______,_______,_______,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,_______,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,_______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        KC_NLCK, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_DEL ,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       //  Function keys plus Media                                            // Function keys plus arrows
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_VOLU,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,_______,
       _______,KC_MSTP,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,                        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,_______,
       _______,_______,_______,_______,_______,KC_MUTE,                        _______,_______,_______,_______,_______,_______,
                                               _______,_______,            _______,GOLET  ,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};
// clang-format on
