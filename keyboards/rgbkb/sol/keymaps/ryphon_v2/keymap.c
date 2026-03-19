#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _FN,
    _SYSCTL
};

#define QWERTY   DF(_QWERTY)
#define FN       MO(_FN)
#define SYSCTL   MO(_SYSCTL)

#define FN_ESC   LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,------------------------------------------------.                     ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |                     |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------|------|                     |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                     |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|------|                     |------|------+------+------+------+------+------|
   * |  FN  |   A  |   S  |   D  |   F  |   G  |   O  |                     |  O   |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+  LED |                     | LED  +------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |      |                     |      |   N  |   M  |   ,  |   .  |   /  |FN(CAPS)|
   * |------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------|
   * | Ctrl |  FN  |SYSCTL| Win  | Alt  | Space| DEL  |                     | Enter| Space|  XX  | Prev |Pause | Next | Ctrl |
   * |------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |                     | Enter| Space|
   *                                    `-------------'                     `-------------'
   */
  [_QWERTY] = LAYOUT(
    QK_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_MINS,  KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC, KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
         FN,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, _______, _______,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, FN_CAPS,
    KC_LCTL,      FN,  SYSCTL, KC_LGUI, KC_LALT,  KC_SPC,  KC_DEL,  KC_ENT,  KC_SPC, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_RCTL,
                                                  KC_SPC,  KC_DEL,  KC_ENT,  KC_SPC
  ),

  /* FN
   * ,------------------------------------------------.                     ,------------------------------------------------.
   * |  GRV |  F1  |  F2  |  F3  |  F4  |  F5  |      |                     |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|------|                     |------|------+------+------+------+------+------|
   * |      | PGDN |  UP  | PGUP |      |      | NLCK |                     | SLCK |      | PGDN |  UP  | PGUP | PSCR |  F12 |
   * |------+------+------+------+------|------|------|                     |------|------+------+------+------+------+------|
   * |      | LEFT | DOWN | RIGHT|      |  _   |      |                     |      | HOME | LEFT | DOWN | RIGHT|      | INS  |
   * |------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                     |      | END  |      |      |      |      | VOL+ |
   * |------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                     |      |      |      | Prev |Pause | Next | VOL- |
   * `------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------'
   *                                    |      |      |                     |      |      |
   *                                    `-------------'                     `-------------'
   */
  [_FN] = LAYOUT(
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    _______, KC_PGDN,   KC_UP, KC_PGUP, _______, _______,  KC_NUM, KC_SCRL, _______, KC_PGDN,   KC_UP, KC_PGUP, KC_PSCR,  KC_F12,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_UNDS, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______,  KC_INS,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_END, _______, _______, _______, _______, KC_VOLU,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD,
                                                 _______, _______, _______, _______
  ),

  /* SYSCTL
   * ,------------------------------------------------.                     ,------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |                     |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|------|                     |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                     |      |      |      |      |      | PSCR |      |
   * |------+------+------+------+------+------|------|                     |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                     |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                     |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                     |      |      |      |      |      |      |      |
   * `------+------+------+------+------+------+------|                     |------+------+------+------+------+------+------'
   *                                    |      |      |                     |      |      |
   *                                    `-------------'                     `-------------'
   */
  [_SYSCTL] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                                 _______, _______, _______, _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]     = { ENCODER_CCW_CW(_______, _______) },
    [_SYSCTL] = { ENCODER_CCW_CW(_______, _______) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
    case QK_BOOT:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
  }
  return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return OLED_ROTATION_180;
}

static void render_logo(void) {
  static const char PROGMEM sol_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
  };
  oled_write_P(sol_logo, false);
}

static void render_status(void) {
  static const char PROGMEM sol_icon[] = {
    0x9b,0x9c,0x9d,0x9e,0x9f,
    0xbb,0xbc,0xbd,0xbe,0xbf,
    0xdb,0xdc,0xdd,0xde,0xdf,0
  };
  oled_write_P(sol_icon, false);

  oled_write_P(PSTR("Layer"), false);
  uint8_t layer = get_highest_layer(layer_state|default_layer_state);
  switch (layer) {
    case _QWERTY:
      oled_write_P(PSTR("BASE "), false);
      break;
    case _FN:
      oled_write_P(PSTR("FN   "), false);
      break;
    case _SYSCTL:
      oled_write_P(PSTR("SCTL "), false);
      break;
    default:
      oled_write_P(PSTR("WTF  "), false);
  }

  led_t led_state = host_keyboard_led_state();
  oled_write_P(PSTR("-----"), false);
  oled_write_P(led_state.num_lock    ? PSTR("NUMLK") : PSTR("     "), false);
  oled_write_P(led_state.caps_lock   ? PSTR("CAPLK") : PSTR("     "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCRLK") : PSTR("     "), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
    oled_scroll_left();
  }
  return false;
}
#endif
