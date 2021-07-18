/* Copyright 2021 Kyle McCreery
 *
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _FN1,
	_FN2,
	_FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                  KC_F1,   KC_F2,   KC_F3,   KC_F4,
				          KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
                  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_MUTE,  KC_P4,   KC_P5,   KC_P6,   _______,
        MO(_FN1), KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_BSPC,  KC_P0,   _______, KC_PDOT, _______,
		
				          KC_F5,   KC_F6,   KC_F7

    ),
    [_FN1] = LAYOUT(
                 _______,  _______, _______, _______,				
                 _______,  _______, _______, _______,
                 RGB_HUD,  RGB_SPI, RGB_HUI, _______,
        _______, RGB_RMOD, RGB_TOG, RGB_MOD, _______,
        _______, RGB_VAD,  RGB_SPD, RGB_VAI, _______,
        _______, RGB_SAD,  _______, RGB_SAI, _______,
		
                 _______,  _______, _______

    ),
    [_FN2] = LAYOUT(
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
						   
                  _______, _______, _______

    ),
	  [_FN3] = LAYOUT(
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
                  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
        _______,  _______, _______, _______, _______,
		
                  _______, _______, _______

    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
		case 1:
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
	oled_rotation_t oled_init_user(oled_rotation_t rotation) {
		return OLED_ROTATION_270;       // flips the display 270 degrees
	}

	static void render_logo(void) {     // Render MechWild "MW" Logo
		static const char PROGMEM hundredT[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 
0x0c, 0xf8, 0xf8, 0xfc, 0x1e, 0x1c, 0x78, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
0xf0, 0xc0, 0x7f, 0xff, 0xc4, 0x10, 0xf3, 0x87, 0x0f, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x87, 0xce, 0x7c, 0x78, 0x70, 0x70, 0xf1, 0xe3, 0xe7, 0xff, 0xfe, 0x3c, 0x00, 0x00, 0x08, 0x10, 
0x31, 0x7f, 0x7e, 0x43, 0xcf, 0xfe, 0x80, 0x9f, 0x3c, 0x30, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x47, 0xee, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf1, 0x73, 0x7f, 0xfe, 0xfc, 0x08, 0x00, 0x00, 
0x01, 0x03, 0x1f, 0xff, 0xe3, 0xb7, 0xc3, 0x03, 0xc3, 0x03, 0x03, 0x07, 0xfc, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x01, 0x03, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x1f, 0x78, 0x20, 0x00, 
0x08, 0x0e, 0xce, 0xd9, 0x9b, 0x13, 0x23, 0x26, 0x48, 0x47, 0x0c, 0x00, 0x00, 0x0f, 0xf8, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x38, 0xf8, 0xcc, 0x88, 0x91, 0x33, 0x3f, 0x76, 0xc6, 0xc4, 0x80, 0x80, 0x00, 0x00, 0x00, 0x03, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x03, 0x0f, 0x09, 0x03, 0x02, 0x06, 0x04, 0x0c, 0x08, 0x01, 0x03, 0x02, 0x00, 0x00,
    };
		oled_write_raw_P(hundredT, sizeof(hundredT));
	}

	void oled_task_user(void) {
		oled_set_cursor(0,0);
		render_logo();
    oled_scroll_set_speed(2);
    oled_scroll_left();
	}
#endif
