#include QMK_KEYBOARD_H

#define BASE 0
#define FN1 1

enum custom_keycodes {
  RGB_PLAIN_RED = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_60_iso(
    KC_GESC, KC_1,      KC_2,          KC_3,       KC_4,     KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,       KC_MINS, KC_EQL,  _______,  KC_BSPC,
    KC_TAB,  KC_Q,      KC_W,          KC_E,       KC_R,     KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,       KC_LBRC, KC_RBRC,
    KC_CAPS, KC_A,      KC_S,          KC_D,       KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,    KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_BSLASH, KC_Z,          KC_X,       KC_C,     KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,     KC_SLSH, KC_RSFT, _______,
    KC_LCTL, KC_LGUI,   KC_LALT,       KC_SPC,     MO(FN1),          MO(FN1), KC_SPC,  KC_RALT, MO(FN1),  _______,    _______, KC_RCTL
  ),

  [FN1] = LAYOUT_60_iso(
    KC_TILD, KC_F1,         KC_F2,       KC_F3,      KC_F4,    KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,     KC_F11,  KC_F12,  KC_DEL,   KC_BSPC,
    RGB_TOG, RGB_MOD,       KC_BSPACE,   KC_UP,      KC_DEL,   _______, _______,  KC_PGUP, KC_UP,   KC_PGDOWN, KC_PSCREEN, _______, _______,
    _______, RGB_PLAIN_RED, KC_LEFT,     KC_DOWN,    KC_RGHT,  _______, _______,  KC_LEFT, KC_DOWN, KC_RGHT,   _______,    _______, _______, _______,
    _______, _______,       KC__VOLDOWN, KC__VOLUP,  KC__MUTE, _______, _______,  _______, _______, _______,   _______,    _______, _______, _______,
    KC_TILD, _______,       _______,     _______,    _______,           _______,  _______, _______, _______,   _______,    _______, _______
  )
};

void set_plain_red(void) {
  rgblight_enable();
  rgblight_setrgb(RGB_RED);
  rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}

void keyboard_post_init_user(void) {
  set_plain_red();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_PLAIN_RED:
      if (record->event.pressed) {
        set_plain_red();
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
