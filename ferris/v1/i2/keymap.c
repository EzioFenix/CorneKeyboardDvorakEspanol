#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// Define layers
enum layers {
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4,
    _LAYER5,
    _LAYER6,
    _LAYER7
};

// Custom keycodes
enum custom_keycodes {
    L1_SPC1 = SAFE_RANGE,
    L1_SPC2
};

// Tap Dance Declarations
enum {
    TD_ENT_MINUS = 0
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ENT_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_MINS)
};

// Define the keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_2(
        ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,       ES_Y,     ES_U,    ES_I,     ES_O,    LT(_LAYER7, ES_P),
        ES_A,    ES_S,    ES_D,    ES_F,    ES_G,       ES_H,     ES_J,    ES_K,     ES_L,    ES_NTIL,
        ES_Z,    ES_X,    ES_C,    ES_V,    ES_B,       ES_N,     ES_M,    ES_COMM,  ES_DOT,  TD(TD_ENT_MINUS),  // Updated here
                                        MO(_LAYER1), L1_SPC1,   L1_SPC2,  MO(_LAYER2)
    ),
    [_LAYER1] = LAYOUT_split_3x5_2(
        ES_1,    ES_2,    ES_3,    ES_4,    ES_5,       ES_6,     ES_7,    ES_8,     ES_9,    ES_0,
        ES_IQUE, ES_LABK, ES_LCBR, ES_LBRC, ES_LPRN,    ES_RPRN,  ES_RBRC, ES_RCBR,  ES_RABK, ES_QUES,
        ES_ASTR, ES_PLUS, ES_HASH, ES_DQUO, ES_QUOT,    ES_EQL,   ES_SCLN, ES_COMM,  ES_DOT,  ES_BSLS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_LAYER2] = LAYOUT_split_3x5_2(
        ES_1,    ES_2,    ES_3,    ES_4,    ES_5,       ES_6,     ES_7,    ES_8,     ES_9,    ES_0,
        ES_IQUE, ES_LABK, ES_LCBR, ES_LBRC, ES_LPRN,    ES_RPRN,  ES_RBRC, ES_RCBR,  ES_RABK, ES_QUES,
        ES_ASTR, ES_PLUS, ES_HASH, ES_DQUO, ES_QUOT,    ES_EQL,   ES_SCLN, ES_COMM,  ES_DOT,  ES_BSLS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_LAYER3] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_BSPC,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,  KC_NO,    KC_NO
    ),
    [_LAYER4] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,  KC_NO,    KC_NO
    ),
    [_LAYER5] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,  KC_NO,    KC_NO
    ),
    [_LAYER6] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,  KC_NO,    KC_NO
    ),
    [_LAYER7] = LAYOUT_split_3x5_2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_DEL,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,  KC_NO,    KC_NO
    )
};

// Optional: define layer switch behavior
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t l1_spc1_timer;
    static uint16_t l1_spc2_timer;

    switch (keycode) {
        case L1_SPC1:
            if (record->event.pressed) {
                l1_spc1_timer = timer_read();
                layer_on(_LAYER1);
            } else {
                layer_off(_LAYER1);
                if (timer_elapsed(l1_spc1_timer) < TAPPING_TERM) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
            }
            return false;

        case L1_SPC2:
            if (record->event.pressed) {
                l1_spc2_timer = timer_read();
                layer_on(_LAYER1);
            } else {
                layer_off(_LAYER1);
                if (timer_elapsed(l1_spc2_timer) < TAPPING_TERM) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                }
            }
            return false;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _LAYER1) && layer_state_cmp(state, _LAYER2)) {
        state |= (1UL << _LAYER3);
    } else {
        state &= ~(1UL << _LAYER3);
    }

    return state;
}
