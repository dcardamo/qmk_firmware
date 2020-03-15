#include QMK_KEYBOARD_H

// Custom keycodes can be mapped into the keycodes table
enum custom_keycodes {
    GOLET = SAFE_RANGE,  // For golang:  ':='
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    MT_LGUI_LBRC,   // Left GUI hold, tap = {
    LT_RAISE_LPRN,  // RAISE on hold, tap = '('
    MT_RGUI_RBRC,   // Right GUI hold, tap = }
    LT_LOWER_RPRN   // LOWER on hold, tap = ')'
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
        case LEFT_PAREN:
            if (record->event.pressed) {
                SEND_STRING("(");
            }
            return false;
        case RIGHT_PAREN:
            if (record->event.pressed) {
                SEND_STRING(")");
            }
            return false;
        case LEFT_BRACE:
            if (record->event.pressed) {
                SEND_STRING("{");
            }
            return false;
        case RIGHT_BRACE:
            if (record->event.pressed) {
                SEND_STRING("}");
            }
            return false;
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
