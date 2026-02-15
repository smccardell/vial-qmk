#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _COLEMAK,
    _QWERTY,
    _NAV,
    _SYNUM,
    _FUN,
};

enum customzKeycodes {
    C_LEAD = QK_KB_0
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    ALT_DEL,
    NAV_SPC,
    SYN_ENT,
    NAV_ENT,
    SYN_BSPC,
    OS_NAV,
    OS_SYNUM,
    OS_FUN,
    C_UNDO,
    C_REDO,
    C_CUT,
    C_COPY,
    C_PASTE,
    OS_LSFT,
    OS_RSFT,
    OS_LCTL,
    OS_RCTL,
    OS_LALT,
    OS_RALT,
    GUI_V
};

#define C_LEAD QK_LEADER
#define COLEMAK PDF(_COLEMAK)
#define QWERTY PDF(_QWERTY)
#define ALT_DEL ALT_T(KC_DELETE)
#define NAV_SPC LT(_NAV, KC_SPC)
#define SYN_ENT LT(_SYNUM, KC_ENTER)
#define NAV_ENT LT(_NAV, KC_ENTER)
#define SYN_BSPC LT(_SYNUM, KC_BSPC)
#define OS_NAV OSL(_NAV)
#define OS_SYNUM OSL(_SYNUM)
#define OS_FUN OSL(_FUN)
#define C_UNDO LCTL(KC_Z)
#define C_REDO LCTL(KC_Y)
#define C_CUT LCTL(KC_X)
#define C_COPY(KC_C)
#define C_PASTE LCTL(KC_V)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define GUI_V LGUI(KC_V)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
      KC_ESC,     KC_1,    KC_2,    KC_3,      KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,     KC_9,    KC_0,      KC_LGUI,
      KC_TAB,     KC_Q,    KC_W,    KC_F,      KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,     KC_Y,    KC_QUOT,   QK_REP,
      OS_LSFT,    KC_A,    KC_R,    KC_S,      KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,     KC_I,    KC_O,      OS_RSFT,
      OS_LCTL,    KC_Z,    KC_X,    KC_C,      KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,   OS_RCTL,
                           KC_UNDS, OS_LALT,                                                            OS_RALT,  KC_UNDS, 
                                               ALT_DEL, NAV_SPC,  SYN_ENT,  NAV_ENT,  SYN_BSPC,  OS_FUN,
                                                        OS_FUN,   GUI_V,    C_LEAD,   OS_RSFT
  ),

    [_QWERTY] = LAYOUT(
      KC_ESC,    KC_1,  KC_2,       KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,     KC_9,    KC_0,      KC_LGUI,
      KC_TAB,    KC_Q,  KC_W,       KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,      QK_REP,
      OS_LCTL,   KC_A,  KC_S,       KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,     KC_L,    KC_QUOT,   OS_RSFT,
      OS_LSFT,   KC_Z,  KC_X,       KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,   OS_RCTL,
                           KC_UNDS, OS_LALT,                                                           OS_RALT,  KC_UNDS, 
                                             ALT_DEL, NAV_SPC,  SYN_ENT,  NAV_ENT,  SYN_BSPC,  OS_FUN,
                                                      OS_FUN,   GUI_V,    C_LEAD,   OS_RSFT
  ),
 
    [_NAV] = LAYOUT(
      _______, _______,   _______,  _______,  _______,   _______,                     _______,         _______,  _______,    _______,  _______,      _______,
      _______, XXXXXXX,   KC_HOME,  KC_UP,    KC_END,    KC_PGUP,                     KC_KP_ASTERISK,  KC_7,     KC_8,       KC_9,     KC_KP_PLUS,   _______,
      _______, KC_DELETE, KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_PGDN,                     KC_KP_SLASH,     KC_4,     KC_5,       KC_6,     KC_KP_MINUS,  _______,
      _______, C_UNDO,    C_CUT,    C_COPY,   C_PASTE,   C_REDO,                      KC_COMM,         KC_1,     KC_2,       KC_3,     KC_EQUAL,     _______,
                          _______,  _______,                                                                     KC_0,       KC_KP_DOT, 
                                              _______,   _______,  _______,  _______, _______,         _______,
                                                         _______,  _______,  _______, _______
  ),

    [_SYNUM] = LAYOUT(
      _______, _______,  _______,   _______,  _______,   _______,                     _______,         _______,     _______,     _______,     _______,      _______,
      _______, KC_LBRC,  KC_RBRC,   KC_LPRN,  KC_RPRN,   KC_GRAVE,                    KC_KP_ASTERISK,  LSFT(KC_7),  LSFT(KC_8),  XXXXXXX,     KC_KP_PLUS,   _______,
      _______, KC_SCLN,  KC_QUOTE,  KC_PIPE,  KC_UNDS,   KC_BSLS,                     KC_KP_SLASH,     LSFT(KC_4),  LSFT(KC_5),  LSFT(KC_6),  KC_KP_MINUS,  _______,
      _______, KC_LABK,  KC_RABK,   KC_COLN,  KC_EQUAL,  XXXXXXX,                     KC_COMM,         LSFT(KC_1),  LSFT(KC_2),  LSFT(KC_3),  KC_KP_EQUAL,  _______,
                         _______,   _______,                                                                        KC_KP_0,     KC_KP_DOT, 
                                              _______,   _______,  _______,  _______, _______,         _______,
                                              _______,   _______,                     _______,         _______
  ),

    [_FUN] = LAYOUT(
      _______, _______,    _______,  _______,  _______,  _______,                     _______,    _______,  _______,  _______,  _______,  _______,
      _______, QK_BOOT,    QWERTY,   COLEMAK,  KC_VOLU,  XXXXXXX,                     QK_BOOT,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
      _______, QK_REBOOT,  KC_CAPS,  KC_PSCR,  KC_MUTE,  XXXXXXX,                     QK_REBOOT,  KC_F4,    KC_F5,    KC_F6,    KC_F11,   _______,
      _______, XXXXXXX,    XXXXXXX,  XXXXXXX,  KC_VOLD,  XXXXXXX,                     XXXXXXX,    KC_F1,    KC_F2,    KC_F3,    KC_F12,   _______,
                           _______,  _______,                                                               _______,  _______, 
                                              _______,   _______, _______,  _______,  _______,    _______,
                                              _______,   _______,                     _______,    _______
    )
};

void leader_end_user(void) {
    if (leader_sequence_three_keys(KC_S, KC_S, KC_F)) {
        // Leader, s, s, f => select * from 
        SEND_STRING("select *\n  from ");
    } else if (leader_sequence_three_keys(KC_S, KC_C, KC_F)) {
        // Leader, s, c, f => select count(*) from 
        SEND_STRING("select count(*)\n  from ");
    } else if (leader_sequence_four_keys(KC_D, KC_O, KC_P, KC_L)) {
        // Leader, d, o, p, l => dbms_oupput.put_line('');
        SEND_STRING("dbms_output.put_line('');");
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
void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
}