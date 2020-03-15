/* A standard layout for the Dactyl Manuform 5x6 Keyboard */
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _FUNCNUM 4

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define FUNCNUM MO(_FUNCNUM)
#define NUMPAD TG(_NUMPAD)

#include "process_keys.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] = LAYOUT_5x6(
     NUMPAD, KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,                        KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,_______,
     KC_GRV , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                        KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_TAB , KC_A  , KC_S  , LT(RAISE, KC_D), LT(LOWER, KC_F), KC_G  ,      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     _______, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                        KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                         MT(MOD_LSFT, KC_ESC),KC_BSPC,                        KC_SPC, MT(MOD_RCTL, KC_ENT),  // enter when tapped, control when held
                //   LT_RAISE_LPRN ,LT(FUNCNUM, KC_LBRC),                        KC_RBRC, LT_LOWER_RPRN,
                   LT_RAISE_LPRN ,LT(FUNCNUM, KC_LBRC),                        KC_RBRC, LT_LOWER_RPRN,
                   MT_LGUI_LBRC,MT(MOD_LALT, KC_LBRC),                        KC_RBRC, MT_RGUI_RBRC
  ),

  [_LOWER] = LAYOUT_5x6(
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        _______,LEFT_PAREN,KC_LBRACKET,LEFT_BRACE,_______,_______,
     _______,_______,_______,_______,_______,_______,                       _______,RIGHT_PAREN,KC_RBRACKET,RIGHT_BRACE,_______,_______,
                                             _______,KC_DEL ,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),


  [_RAISE] = LAYOUT_5x6(
       //  Function keys plus Media                                            // Function keys, arrows, music
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     _______,_______,_______,_______,_______,_______,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_VOLU,
     _______,_______,_______,_______,_______,_______,                        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,KC_VOLD,
     _______,_______,_______,_______,_______,_______,                        KC_MSTP,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,KC_MUTE,
                                               _______,_______,            _______,GOLET  ,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),

  [_NUMPAD] = LAYOUT_5x6(
     //  this side is for misc stuff                                         // This is the numpad
     NUMPAD,_______,_______,_______,_______,_______,                         KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,_______,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,_______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        KC_NLCK, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_DEL ,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_FUNCNUM] = LAYOUT_5x6(
     //  this side is for misc stuff                                         // This is the numpad
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                        KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,_______,
     _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
                                             _______,KC_DEL ,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),
};
// clang-format on
