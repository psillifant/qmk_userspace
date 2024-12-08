/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Space behaviour
  // Windows
  #define W_LSPC LT(1, KC_SPC)
  #define W_RSPC LT(1, KC_SPC)
  // MacOS
  #define M_LSPC LT(3, KC_SPC)
  #define M_RSPC LT(3, KC_SPC)

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
  #define F_GUI LGUI_T(KC_F)
  #define D_ALT LALT_T(KC_D)
  #define S_CTL LCTL_T(KC_S)
  #define L_GUI LGUI_T(KC_L)
  #define K_ALT LALT_T(KC_K)
  #define J_CTL LCTL_T(KC_J)

// Enter triggers the movement layer when held
  #define MV_ENT   LT(4, KC_ENTER)

// 5x3 Layout Schenanigans
  #define Z_SHFT LSFT_T(KC_Z)
  #define N_SHFT LSFT_T(KC_N)

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
    // QWERTYWIN
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         WTAB,  W_QALT,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_A,   S_CTL,   D_ALT,   F_GUI,    KC_G,                         KC_H,   J_CTL,   K_ALT,   L_GUI, KC_SCLN,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,  Z_SHFT,    KC_X,    KC_C,    KC_V,    KC_B,                       N_SHFT,    KC_M, KC_COMM,  KC_DOT, MV_ENT,    KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   MO(5),  W_LSPC,     W_RSPC, KC_MINS,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    // Numbers and symbols (Activate: Either Space on QWERTYWIN)
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,  KC_TAB,KC_GRAVE,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO, KC_QUOT, KC_BSPC,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_NUBS, KC_BTN1, KC_BTN2, AC_CLBR, KC_LBRC,                      KC_RBRC, AC_CRBR,  KC_EQL, KC_BSLS, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // QWERTYMACOS
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         MTAB,  M_QALT,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE,    KC_A,   S_CTL,   D_ALT,   F_GUI,    KC_G,                         KC_H,   J_CTL,   K_ALT,   L_GUI, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  MV_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   MO(5),  M_LSPC,     M_RSPC, KC_MINS,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    // Numbers and symbols (Activate: Either Space on QWERTYMACOS)
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM, MC_QUOT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, KC_BTN1, KC_BTN2, AC_CLBR, KC_LBRC,                      KC_RBRC, AC_CRBR,  KC_EQL, MC_HASH, KC_NO,  MV_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // Movement (Activate: Enter)
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,C(KC_LEFT), KC_UP,C(KC_RGHT), KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,C(KC_DEL), KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,C(KC_BSPC),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME,   KC_NO,  KC_END,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

   // Functions (Activate: Enter + Space)
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(2),   TO(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )

  //  // DEFAULT
  //   [] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, _______,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         _______, _______, _______,    _______, _______, _______
  //                                     //`--------------------------'  `--------------------------'
  // )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, 3, 4, 6);
  state = update_tri_layer_state(state, 1, 3, 6);
  return state;
};


void keyboard_post_init_user(void) {
  // rgb_matrix_mode(RGB_MATRIX_CUSTOM_all_keys_white);
};

#include "features/custom_shift_keys.h" // Source: https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
  {KC_GRAVE   , KC_GRAVE},     // Shift ` is `
  {MC_HASH    , MC_TILD},      // Shift # is ~
  {KC_2       , MC_DBLQ},      // Shift 2 is "
  {KC_QUOT    , MC_AT},        // Shift ' is @
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

    bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  // Nothing else yet defined.

  return true;
}