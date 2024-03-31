// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * └───┴───┼───┼───┼───┼───┼───┼───┼───┼───┼───┴───┘
     *         │ C │ D │ E │ F │   │ H │ I │ J │ 
     *         └───┴───┴───┴───┘   └───┴───┴───┘
     */

    /*
    [N] = LAYOUT_ortho_4x12(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,                _______,    _______,    _______
    )
    */

    [0] = LAYOUT_ortho_4x12(
        KC_ESC,     KC_Q,       KC_W,       KC_E,          KC_R,       KC_T,        KC_Y,       KC_U,       KC_I,         KC_O,       KC_P,          KC_LBRC,
        /*KC_LCTL,    LGUI(KC_A), LALT(KC_S), LCTL(KC_D),    LSFT(KC_F), LT(1,KC_G),  LT(2,KC_H), LSFT(KC_J), LCTL(KC_K),   LALT(KC_L), LGUI(KC_SCLN), KC_QUOT,*/
        KC_LCTL,    KC_A,       KC_S,       KC_D,          KC_F,       KC_G,        KC_H,       KC_J,       KC_K,         KC_L,       KC_SCLN,       KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,          KC_V,       KC_B,        KC_N,       KC_M,       KC_COMM,      KC_DOT,     KC_SLSH,       KC_NO,
                                KC_NO,      LT(1,KC_BSPC), KC_SPC,          KC_MPLY,            KC_ENT,     LT(2,KC_TAB), KC_NO
    ),

    [1] = LAYOUT_ortho_4x12(
        KC_TAB,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,           KC_6,       KC_7,         KC_8,         KC_9,       KC_0,       KC_MINS,
        KC_LCTL,    _______,    _______,    _______,    _______,    _______,        KC_LEFT,    KC_DOWN,      KC_UP,        KC_RIGHT,   _______,    _______,
        KC_LSFT,    _______,    _______,    _______,    _______,    _______,        _______,    _______,      _______,      _______,    _______,    _______,
                                _______,    KC_TRNS,    KC_SPC,             KC_TRNS,            KC_ENT,       LT(3,KC_TAB), _______
    ),

    [2] = LAYOUT_ortho_4x12(
        KC_TAB,     KC_EXLM,    KC_AT,      KC_HASH,       KC_DLR,     KC_PERC,        KC_CIRC,    KC_AMPR,      KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_NO,
        KC_LCTL,    _______,    _______,    _______,       _______,    _______,        _______,    _______,      _______,    _______,   _______,    _______,
        KC_LSFT,    _______,    _______,    _______,       _______,    _______,        _______,    _______,      _______,    _______,    _______,    _______,
                                _______,    LT(3,KC_BSPC), KC_SPC,             KC_TRNS,            KC_ENT,       KC_TRNS,     _______
    ),

    [3] = LAYOUT_ortho_4x12(
        QK_BOOT,    _______,    _______,    _______,       _______,    _______,        _______,    _______,      _______,    _______,    _______,    _______,
        KC_LCTL,    _______,    _______,    _______,       _______,    _______,        _______,    _______,      _______,    _______,    _______,    _______,
        KC_LSFT,    _______,    _______,    _______,       _______,    _______,        _______,    _______,      _______,    _______,    _______,    _______,
                                _______,    KC_TRNS,       KC_SPC,             KC_TRNS,            KC_ENT,     KC_TRNS,      _______
    )

};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
	[_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) ]
};
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) { /* First Encoder */
		if (clockwise) {
			tap_code16(KC_VOLU);
		} else {
			tap_code16(KC_VOLD);
		}
	}
	return false;
}
