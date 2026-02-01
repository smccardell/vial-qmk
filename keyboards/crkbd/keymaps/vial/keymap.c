#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

enum totem_layers {
    _COLEMAK,
    _QWERTY,
    _NAV,
    _SYNUM,
    _FUN,
};

enum custom_keycodes {
    C_LEADER = QK_KB_0
};

#define COLEMAK PDF(_COLEMAK)
#define QWERTY PDF(_QWERTY)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define SYNUM_SPC LT(_SYNUM, KC_SPC)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define FUN_TAB LT(_FUN, KC_TAB)
#define RSFT_ENTER MT(MOD_RSFT, KC_ENT)
#define C_UNDO LCTL(KC_Z)
#define C_CUT LCTL(KC_X)
#define C_COPY LCTL(KC_C)
#define C_PASTE LCTL(KC_V)
#define GUI_TAB LGUI(KC_TAB)
#define ALT_TAB LALT(KC_TAB)

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3_ex2(
      ALT_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,  XXXXXXX,       QK_LLCK,  KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOT,   C_LEADER,
      OSM(KC_LSFT),  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  C_LEADER,      CW_TOGG,  KC_M,    KC_N,    KC_E,     KC_I,    KC_O,      MT(MOD_RSFT, KC_ENT),
      OSM(KC_LCTL),  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                           KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,   QK_REP,
                                      FUN_TAB, OSL(_NAV), SYNUM_SPC,           NAV_BSPC, OSL(_SYNUM), OSL(_FUN)

  ),

    [_QWERTY] = LAYOUT_split_3x6_3_ex2(
      ALT_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  XXXXXXX,       QK_LLCK,  KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     C_LEADER,
      OSM(KC_LSFT),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  C_LEADER,      CW_TOGG,     KC_H,    KC_J,    KC_K,     KC_L,    KC_QUOT,  MT(MOD_RSFT, KC_ENT),
      OSM(KC_LCTL),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                              KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,  QK_REP,
                                      FUN_TAB, OSL(_NAV), SYNUM_SPC,           NAV_BSPC, OSL(_SYNUM), OSL(_FUN)
  ),

    [_SYNUM] = LAYOUT_split_3x6_3_ex2(
      _______, KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,  XXXXXXX,  _______,     _______,  KC_KP_ASTERISK, KC_7,  KC_8,  KC_9,  KC_KP_PLUS,  _______,
      _______, KC_SCLN,  KC_QUOTE, KC_PIPE,  KC_UNDS,  KC_BSLS,  _______,     _______,  KC_KP_SLASH,    KC_4,  KC_5,  KC_6,  KC_KP_MINUS, KC_KP_EQUAL,
      _______, KC_LABK,  KC_RABK,  KC_COLN,  KC_EQUAL, XXXXXXX,                         KC_KP_DOT,      KC_1,  KC_2,  KC_3,  KC_KP_0,     _______,
                                                    _______, _______,  _______,       _______, _______, _______
  ),
 
    [_NAV] = LAYOUT_split_3x6_3_ex2(
      _______, XXXXXXX,  GUI_TAB,  ALT_TAB,  XXXXXXX, XXXXXXX,  _______,     _______,  XXXXXXX,  KC_HOME,  KC_UP,   KC_END,   KC_PGUP,   _______,
      _______, C_UNDO,   C_CUT,    C_COPY,   C_PASTE, XXXXXXX,  _______,     _______,  XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RIGHT, KC_PGDN, _______,
      _______, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,                         XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   _______,
                                             _______, _______,  _______,     _______, _______, _______
  ),

    [_FUN] = LAYOUT_split_3x6_3_ex2(
      _______, QK_BOOT, QWERTY,  COLEMAK, XXXXXXX, XXXXXXX,  _______,     _______,  KC_VOLU,  KC_F7,  KC_F8,  KC_F9,  KC_F10, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,     _______,  KC_MUTE,  KC_F4,  KC_F5,  KC_F6,  KC_F11, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_VOLD,  KC_F1,  KC_F2,  KC_F3,  KC_F12, _______,
                                          _______, _______,  _______,     _______, _______, _______
  )
};
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case C_LEADER: 
            if (record->event.pressed) {
                leader_start();
                return false; 
          }

    }
    return true;
}

void leader_end_user(void) {
    if (leader_sequence_three_keys(KC_S, KC_S, KC_F)) {
        // Leader, s, s, f => select * from 
        SEND_STRING("select *\n  from ");
    } else if (leader_sequence_three_keys(KC_S, KC_C, KC_F)) {
        // Leader, s, c, f => select count(*) from 
        SEND_STRING("select count(*)\n  from ");
    } else if (leader_sequence_four_keys(KC_D, KC_O, KC_P, KC_L)) {
        // Leader, d, o, p, l => dbms_output.put_line('');
        SEND_STRING("dbms_output.put_line();");
    }  
    // if (leader_sequence_one_key(KC_F)) {
    //     // Leader, f => Types the below string
    //     SEND_STRING("QMK is awesome.");
    // } else if (leader_sequence_two_keys(KC_D, KC_D)) {
    //     // Leader, d, d => Ctrl+A, Ctrl+C
    //     SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
    //     // Leader, d, d, s => Types the below string
    //     SEND_STRING("https://start.duckduckgo.com\n");
    // } else if (leader_sequence_two_keys(KC_A, KC_S)) {
    //     // Leader, a, s => GUI+S
    //     tap_code16(LGUI(KC_S));
    // }
}