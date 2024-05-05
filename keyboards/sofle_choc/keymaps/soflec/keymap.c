


#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _NUMSYM,
    _MOVEMENT
    // _HELLDIVERS,
    // _ADMIN
};

#define LEFT_SPC LT(1, KC_SPC)
#define RGHT_SPC LT(1, KC_SPC)
#define MINSGUI  LGUI_T(KC_MINS)
// #define MINSMED  LT(3, KC_MINS)
#define QUOTMED  LT(3, KC_QUOT)
#define MV_ENT   LT(2, KC_ENTER)
#define GRVMSE   LT(4, KC_GRAVE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BKSPC|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LWR  |  GUI  |     |  ALT | / Space /       \ ENT  \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_GRV,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MUTE,     KC_NO,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MV_ENT,
                 KC_LCTL, KC_LGUI, KC_LGUI, KC_LCTL, LEFT_SPC,      RGHT_SPC, KC_LALT, KC_LALT, KC_RALT, MINSGUI
),

[_NUMSYM] = LAYOUT(
   KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
   KC_ESC,KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
     KC_0,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______,KC_NUBS, KC_BTN1, KC_BTN2,S(KC_LBRC),KC_LBRC, _______,       _______,   KC_RBRC,S(KC_RBRC),KC_MINS,KC_EQUAL, KC_BSLS,LGUI(KC_ENTER),
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

[_MOVEMENT] = LAYOUT(
  _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,
   KC_ESC,C(KC_LEFT),KC_UP,C(KC_RGHT), KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,C(KC_DEL), KC_DEL,
    KC_NO,KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,C(KC_BSPC),
  _______,KC_HOME,   KC_NO,  KC_END,   KC_NO,   KC_NO, _______,       _______,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
)

};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif
