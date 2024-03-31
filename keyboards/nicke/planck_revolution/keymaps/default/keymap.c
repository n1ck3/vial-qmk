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
    [0] = LAYOUT_ortho_4x12(
        KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       KC_F,       KC_G,       KC_H,       KC_I,       KC_J,       KC_K,       KC_L,
        KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       KC_F,       KC_G,       KC_H,       KC_I,       KC_J,       KC_K,       KC_L,
        KC_A,       KC_B,       KC_C,       KC_D,       KC_E,       KC_F,       KC_G,       KC_H,       KC_I,       KC_J,       KC_K,       KC_L,
                                KC_C,       KC_D,       KC_E,       KC_F,                   KC_H,       KC_I,       KC_J
    ),

    [1] = LAYOUT_ortho_4x12(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
                                _______,    _______,    _______,    _______,                _______,    _______,    _______
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
