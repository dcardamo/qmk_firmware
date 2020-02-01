/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_QWERTY] = LAYOUT_5x6(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,_______,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     _______, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                      KC_LSFT,KC_BSPC,                        KC_SPC, KC_ENT,
                                      RAISE  ,LOWER  ,                        _______, KC_RCTL,
                                      KC_LGUI,KC_LALT,                        _______, LOWER
  ),

  [_LOWER] = LAYOUT_5x6(
     //  this side is for misc stuff                                         // This is the numpad
     _______,_______,_______,_______,_______,_______,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,_______,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,_______,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        KC_NLCK, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,_______,            _______, KC_P0,
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
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
  
};
