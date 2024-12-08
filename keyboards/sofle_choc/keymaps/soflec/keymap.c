/* Copyright 2023 Brian Low
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
#include "keymap_uk.h"

// Prefixes
//    W - Windows
//    M - MacOS
//    A - Any / All
//    WC / MC / AC - Windows code, etc.  i.e. a single keycode that is custom.
// Space behaviour
  // Windows
  #define W_LSPC LT(1, KC_SPC)
  #define W_RSPC LT(1, KC_SPC)
  // MacOS
  #define M_LSPC LT(3, KC_SPC)
  #define M_RSPC LT(3, KC_SPC)

  #define W_PIPE4 LT(4, KC_NUBS)

// Q becomes CMD or ALT when held
  // Windows
  #define W_QALT LALT_T(KC_Q)
  // MacOS
  #define M_QALT LGUI_T(KC_Q)

// Tab becomes CMD or CTRL when held
  // Windows
  #define WTAB LCTL_T(KC_TAB)
  // MacOS
  #define MTAB LGUI_T(KC_TAB)

// SDF on left hand, and JKL on right, become standard modifiers
  // #define F_GUI LGUI_T(KC_F)
  // #define D_ALT LALT_T(KC_D)
  // #define S_CTL LCTL_T(KC_S)
  // #define L_GUI LGUI_T(KC_L)
  // #define K_ALT LALT_T(KC_K)
  // #define J_CTL LCTL_T(KC_J)

  #define F_GUI KC_F
  #define D_ALT KC_D
  #define S_CTL KC_S
  #define L_GUI KC_L
  #define K_ALT KC_K
  #define J_CTL KC_J

// Enter triggers the movement layer when held
  #define MV_ENT   LT(3, KC_ENTER)

// Custom Keycodes 
  // "
  #define MC_QUOT S(KC_QUOT)
  // #
  #define MC_HASH A(KC_3)
  // ~
  #define MC_TILD S(KC_GRAVE)
  // @
  #define MC_AT S(KC_2)
  // "
  #define MC_DBLQ S(KC_QUOTE)
  // {
  #define AC_CLBR S(KC_LBRC)
  // }
  #define AC_CRBR S(KC_RBRC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// QWERTY
[0] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
    WTAB, W_QALT,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    W_PIPE4,
  KC_GRV,   KC_A,   S_CTL,   D_ALT,   F_GUI,    KC_G,                            KC_H,   J_CTL,   K_ALT,   L_GUI,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_NO,    KC_NO,       KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, MV_ENT,
                     KC_NO, KC_LCTL, KC_LALT, KC_LGUI,  W_LSPC,   W_RSPC, KC_MINS, KC_EQUAL, KC_BSLS, KC_NO
),

// Numbers and Symbols
[1] = LAYOUT(
   KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
   KC_ESC,KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
     KC_0,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______,KC_NUBS, KC_BTN1, KC_BTN2,AC_CLBR,KC_LBRC, _______,       _______,   KC_RBRC,AC_CRBR,KC_MINS,KC_EQUAL, KC_BSLS,LGUI(KC_ENTER),
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

// Games
[2] = LAYOUT(
   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,     KC_I,    KC_O,     KC_P,  W_PIPE4,
   KC_GRV,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,     KC_K,    KC_L,  KC_SCLN,  KC_QUOT,
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_NO,    KC_NO,       KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH, KC_ENTER,
                     KC_NO, KC_LCTL, KC_LALT, KC_NO,  KC_SPC,    KC_SPC, KC_MINS, KC_EQUAL, KC_LGUI, KC_NO
),

// Movement
[3] = LAYOUT(
  _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DEL,
   KC_ESC,C(KC_LEFT),KC_UP,C(KC_RGHT), KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  _______,
    KC_NO,KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
  _______,KC_HOME,   KC_NO,  KC_END,   KC_NO,   KC_NO, _______,       _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  _______,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),

// Functions (Activate: Enter + Space)
[4] = LAYOUT(
  _______,   TO(0),   TO(2),   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(2), _______,
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  _______,  KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO, _______,       _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,
                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
)

};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif
