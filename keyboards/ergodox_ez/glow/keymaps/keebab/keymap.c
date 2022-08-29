#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config; // It contains useful keymap configuration. Used for get the swap_lctl_lgui flag

#define KC_NEXT_TAB LCTL(KC_PGDOWN)
#define KC_PREV_TAB LCTL(KC_PGUP)
#define SYM_ENTER LT(SYMBOL,KC_ENTER)
#define CODE_BCK LCTL(KC_O)
#define CODE_FWD LCTL(KC_I)
#define MV_LSPC LGUI(LCTL(KC_LEFT))
#define MV_RSPC LGUI(LCTL(KC_RIGHT))

#define SP_1 LALT(KC_1)
#define SP_2 LALT(KC_2)
#define SP_3 LALT(KC_3)
#define SP_4 LALT(KC_4)
#define SP_5 LALT(KC_5)
#define SP_6 LALT(KC_6)
#define SP_7 LALT(KC_7)
#define SP_8 LALT(KC_8)
#define SP_9 LALT(KC_9)
#define SP_0 LALT(KC_0)

// :::::: QWERTY ::::::
// ==> Left HYPER and MEH
#define ME_W MEH_T(KC_W)   // MT(MOD_LCTL | MOD_LSFT | MOD_LALT, kc) 
#define HY_E HYPR_T(KC_E)  // MT(MOD_LCTL | MOD_LSFT | MOD_LALT | MOD_LGUI, kc)
// ==> Right HYPER and MEH
#define HY_I HYPR_T(KC_I)
#define ME_O MEH_T(KC_O)

// ==> Left homerows
#define HOME_A MT(MOD_LCTL, KC_A)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LSFT, KC_D)
#define HOME_F MT(MOD_LGUI, KC_F)
// ==> Right homerows
#define HOME_J MT(MOD_LGUI, KC_J)
#define HOME_K MT(MOD_RSFT, KC_K)
#define HOME_L MT(MOD_LALT, KC_L)
#define HOME_SCLN MT(MOD_LCTL, KC_SCLN)

// ==> Left Spanish layer
#define SPA_G LT(SPANISH,KC_G)
// ==> Right Spanish layer
#define SPA_H LT(SPANISH,KC_H)

// :::::: COLEMAK ::::::
// ==> Left HYPER and MEH
#define ME_W MEH_T(KC_W)
#define HY_F HYPR_T(KC_F)
// ==> Right HYPER and MEH
#define HY_U HYPR_T(KC_U)
#define ME_Y MEH_T(KC_Y)

// ==> Left homerows
#define CM_A MT(MOD_LCTL, KC_A)
#define CM_R MT(MOD_LALT, KC_R)
#define CM_S MT(MOD_LSFT, KC_S)
#define CM_T MT(MOD_LGUI, KC_T)
// ==> Right homerows
#define CM_N MT(MOD_LGUI, KC_N)
#define CM_E MT(MOD_RSFT, KC_E)
#define CM_I MT(MOD_LALT, KC_I)
#define CM_O MT(MOD_LCTL, KC_O)

// ==> Left Spanish layer
#define SPC_G LT(SPANISH_DH,KC_G)
// ==> Right Spanish layer
#define SPC_M LT(SPANISH_DH,KC_M)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  KC_RESTORE_TAB,
  UMLAU_U = LT(11, KC_U),
  ACUTE_A = LT(10, KC_A),
  ACUTE_E = LT(10, KC_E),
  ACUTE_I = LT(10, KC_I),
  ACUTE_O = LT(10, KC_O),
  ACUTE_U = LT(10, KC_U),
  TILDE_N = LT(10, KC_N),
  SW_LANG,
  SC_UNDO,
  SC_CUT,
  SC_COPY,
  SC_PASTE,
  SC_REDO,
};

#define BASE 0 
#define COLEMAK 1
#define NAV 2
#define SYMBOL 3
#define DIGITS 4
#define SPANISH 5
#define SPANISH_DH 6
#define LAYERS 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// LAYOUT_ergodox_pretty(
//     _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,                                                   _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______,                                                                     _______, _______, _______, _______, _______,
//                                                                   _______, _______, _______, _______,
//                                                                            _______, _______,
//                                                          _______, _______, _______, _______, _______, _______
//   ),

/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │  1  │  2  │  3  │  4  │  5  │       │ │       │  6  │  7  │  8  │  9  │  0  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  TAB  │  Q  │ME_W │HY_E │  R  │  T  │RESTORE│ │       │  Y  │  U  │HY_I │ME_O │  P  │  = +  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  ESC  │L⎈/A │L⎇/S │L⇧/D │L◆/F │SPA/G├───────┤ ├───────┤SPA/H│L⎈/J │L⎇/K │L⇧/L │L◆/; │  ' "  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤   ⏎   │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  ` ~  │  Z  │  X  │  C  │  V  │  B  │       │ │       │  N  │  M  │ , < │ . > │ / ? │  - _  │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │ L⎈  │ L⎇  │ L⇧  │ L◆  │                             │ L◆  │ L⇧  │ L⎇  │ L⎈  │LAYERS│
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │ SPC ← │ SPC → │ │ VOL - │ VOL + │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │NAV/SPC│ BSPC  │  ⏮️   │ │  ⏭️   │ SPACE │ SYM/⏎ │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │  DEL  │ │  ⏯️   │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [BASE] = LAYOUT_ergodox_pretty(
    _______,    KC_1,    KC_2,        KC_3,         KC_4,     KC_5,  _______,                                _______, KC_6,  KC_7,     KC_8,          KC_9,         KC_0,      _______,
    KC_TAB,     KC_Q,    ME_W,        HY_E,         KC_R,     KC_T,  KC_RESTORE_TAB,                         _______, KC_Y,  KC_U,     HY_I,          ME_O,         KC_P,      KC_EQL,
    KC_ESC,     HOME_A,  HOME_S,      HOME_D,       HOME_F,   SPA_G,                                                  SPA_H, HOME_J,   HOME_K,        HOME_L,       HOME_SCLN, KC_QUOTE,
    KC_GRAVE,   KC_Z,    KC_X,        KC_C,         KC_V,     KC_B,  KC_ENTER,                               _______, KC_N,  KC_M,     KC_COMM,       KC_DOT,       KC_SLASH,  KC_MINUS,
    _______,    KC_LCTL, KC_LALT,     KC_LSFT,      KC_LGUI,                                                                 KC_LGUI,  KC_LSFT,       KC_LALT,      KC_LCTL,   MO(LAYERS),
                                                                  MV_LSPC, MV_RSPC,      KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP,
                                                               KC_MEDIA_PREV_TRACK,      KC_MEDIA_NEXT_TRACK,
                                            LT(NAV,KC_SPACE), KC_BSPACE ,KC_DELETE,      KC_MEDIA_PLAY_PAUSE,  KC_SPACE,  SYM_ENTER
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │  1  │  2  │  3  │  4  │  5  │       │ │       │  6  │  7  │  8  │  9  │  0  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │  TAB  │  Q  │ME_W │HY_F │  P  │  B  │       │ │       │  J  │  L  │HY_U │ME_Y │ : ; │  = +  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  ESC  │L⎈/A │L⎇/R │L⇧/S │L◆/T │SPA/G├───────┤ ├───────┤SPA/M│L⎈/N │L⎇/E │L⇧/I │L◆/O │  ' "  │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  ` ~  │  Z  │  X  │  C  │  D  │  V  │       │ │       │  K  │  H  │ , < │ . > │ / ? │  - _  │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │ L⎈  │ L⎇  │ L⇧  │ L◆  │                             │ L◆  │ R⇧  │ L⎇  │ L⎈  │LAYERS│
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [COLEMAK] = LAYOUT_ergodox_pretty(
    _______,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5, _______,                                 _______, KC_6,  KC_7,    KC_8,    KC_9,    KC_0,     _______,
    KC_TAB,   KC_Q,    ME_W,    HY_F,    KC_P,   KC_B, _______,                                 _______, KC_J,  KC_L,    HY_U,    ME_Y,    KC_SCLN,  KC_EQL,
    KC_ESC,   CM_A,    CM_R,    CM_S,    CM_T,   SPC_G,                                                  SPC_M, CM_N,    CM_E,    CM_I,    CM_O,     KC_QUOTE,
    KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_D,   KC_V, _______,                                 _______, KC_K,  KC_H,    KC_COMM, KC_DOT,  KC_SLASH, KC_MINUS,
    _______,  KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI,                                                               KC_LGUI, KC_RSFT, KC_LALT, KC_LCTL,  MO(LAYERS),
                                                                  _______, _______, _______, _______,
                                                                           _______, _______,
                                                         _______, _______, _______, _______, _______, _______
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │SP_1 │SP_2 │SP_3 │SP_4 │SP_5 │       │ │       │SP_6 │SP_7 │SP_8 │SP_9 │SP_0 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │SPC ←│TAB ←│TAB →│SPC →│     │   📷   │ │       │SPACE│HOME │  ↑  │ END │CAPSW│       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ L⎈  │ L⎇  │ L⇧  │ L◆  │     ├───────┤ ├───────┤BSPC │  ←  │  ↓  │  →  │ DEL │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤ SFT ⏎ │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │UNDO │ CUT │COPY │PASTE│REDO │       │ │       │  ⏎  │CBCK │PGDOW│PGUP │CFWD │       │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │     │     │     │     │                             │     │     │     │     │      │
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [NAV] = LAYOUT_ergodox_pretty(
    _______, SP_1,    SP_2,        SP_3,        SP_4,     SP_5, _______,                                    _______, SP_6,      SP_7,     SP_8,      SP_9,     SP_0,      _______,
    _______, MV_LSPC, KC_PREV_TAB, KC_NEXT_TAB, MV_RSPC,  _______, LGUI(LCTL(LSFT(KC_4))),                  _______, KC_SPACE,  KC_HOME,  KC_UP,     KC_END,   CAPSWRD,   _______,
    _______, KC_LCTL, KC_LALT,     KC_LSFT,     KC_LGUI,  _______,                                                   KC_BSPACE, KC_LEFT,  KC_DOWN,   KC_RIGHT, KC_DELETE, _______,
    _______, SC_UNDO, SC_CUT,      SC_COPY,     SC_PASTE, SC_REDO, LSFT(KC_ENTER),                          _______, KC_ENTER, CODE_BCK,  KC_PGDOWN, KC_PGUP,  CODE_FWD,  _______,
    _______, _______, _______, _______, _______,                                                            _______, _______, _______,   _______,  _______,
                                                                  _______, _______, _______, _______,
                                                                           _______, _______,
                                                         _______, _______, _______, _______, _______, _______
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │SP_1 │SP_2 │SP_3 │SP_4 │SP_5 │       │ │       │SP_6 │SP_7 │SP_8 │SP_9 │SP_0 │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  ~  │  (  │  )  │  &  │  |  │       │ │       │  %  │  *  │  +  │ - _ │ / ? │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │   "   │  ^  │  {  │  }  │  $  │  @  ├───────┤ ├───────┤  |  │ L◆  │ L⇧  │ L⎇  │ L⎈  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ ? ! │  [  │  ]  │  #  │ ` ~ │       │ │       │ \ | │  !  │  <  │  >  │ = + │       │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │     │     │     │     │                             │     │     │     │     │      │
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [SYMBOL] = LAYOUT_ergodox_pretty(
    _______, SP_1,    SP_2,    SP_3,    SP_4,    SP_5,     _______,                                 _______, SP_6,    SP_7,    SP_8,    SP_9,     SP_0,     _______,
    _______, KC_TILD, KC_LPRN, KC_RPRN, KC_AMPR, KC_PIPE,  _______,                                 _______, KC_PERC, KC_ASTR, KC_PLUS, KC_MINUS, KC_SLASH, _______,
    KC_DQUO, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  KC_AT,                                                      KC_PIPE, KC_LGUI, KC_LSFT, KC_LALT,  KC_LCTL,  _______,
    _______, KC_QUES, KC_LBRC, KC_RBRC, KC_HASH, KC_GRAVE, _______,                                 _______, KC_BSLS, KC_EXLM, KC_LT,   KC_GT,    KC_EQL,   _______,
    _______, _______, _______, _______, _______,                                                                      _______, _______, _______,  _______,  _______,
                                                                  _______, _______, _______, _______,
                                                                           _______, _______,
                                                         _______, _______, _______, _______, _______, _______
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │       │ │       │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ F4  │  7  │  8  │  9  │ , < │       │ │       │  %  │  *  │  +  │ - _ │ / ? │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │  F11  │ F2  │  4  │  5  │  6  │ . > ├───────┤ ├───────┤  |  │ L◆  │ L⇧  │ L⎇  │ L⎈  │   $   │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ F5  │  1  │  2  │  3  │  0  │       │ │       │  &  │  !  │  <  │  >  │ = + │       │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │     │     │     │     │                             │     │     │     │     │      │
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [DIGITS] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______,   _______,
    _______, KC_F4,   KC_7,    KC_8,    KC_9,    KC_COMM, _______,              _______, KC_PERC, KC_ASTR, KC_PLUS, KC_MINUS, KC_SLASH, _______,
    KC_F11,  KC_F2,   KC_4,    KC_5,    KC_6,    KC_DOT,                                 KC_PIPE, KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, KC_DLR,
    _______, KC_F5,   KC_1,    KC_2,    KC_3,    KC_0,    _______,              _______, KC_AMPR, KC_EXLM, KC_LT,   KC_GT,   KC_EQL, _______,
    _______, _______, _______, _______, _______,                                                  _______, _______, _______, _______, _______,
                                                        _______, _______, _______, _______,
                                                                  _______, _______,
                                                _______, _______, _______, _______, _______, _______
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │       │ │       │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │  É  │     │     │       │ │       │  Ü  │  Ú  │  Í  │  Ó  │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  Á  │     │     │     │     ├───────┤ ├───────┤     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │       │ │       │  Ñ  │     │     │     │     │       │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │     │     │     │     │                             │     │     │     │     │      │
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [SPANISH] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, ACUTE_E, _______, _______, _______,                                 _______, UMLAU_U, ACUTE_U, ACUTE_I, ACUTE_O, _______, _______,
    _______, ACUTE_A, _______, _______, _______, _______,                                                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, TILDE_N, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                                     _______, _______, _______, _______, _______,
                                                                  _______, _______, _______, _______,
                                                                           _______, _______,
                                                         _______, _______, _______, _______, _______, _______
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │       │ │       │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │       │ │       │     │     │  Ú  │  Ü  │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  Á  │     │     │     │     ├───────┤ ├───────┤     │  Ñ  │  É  │  Í  │  Ó  │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │       │ │       │     │     │     │     │     │       │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │     │     │     │     │                             │     │     │     │     │      │
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
  [SPANISH_DH] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, ACUTE_U, UMLAU_U, _______, _______,
    _______, ACUTE_A, _______, _______, _______, _______,                                                   _______, TILDE_N, ACUTE_E, ACUTE_I, ACUTE_O, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                                     _______, _______, _______, _______, _______,
                                                                  _______, _______, _______, _______,
                                                                           _______, _______,
                                                         _______, _______, _______, _______, _______, _______
  ),
/* ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐ ┌───────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │       │ │       │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤ ├───────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │LCG_S│     │     │     │       │ │       │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │DF(BA│DF(CO│     ├───────┤ ├───────┤     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┤       │ │       ├─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │     │     │     │     │     │       │ │       │     │LCG_N│     │     │     │       │
 * └┬──────┼─────┼─────┼─────┼─────┼─────┴───────┘ └───────┴─────┼─────┼─────┼─────┼─────┼──────┬┘
 *  │      │     │     │     │     │                             │     │     │     │     │      │
 *  └──────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴──────┘
 *                               ┌───────┬───────┐ ┌───────┬───────┐
 *                               │       │       │ │       │       │
 *                       ┌───────┼───────┼───────┤ ├───────┼───────┼───────┐
 *                       │       │       │       │ │       │       │       │
 *                       │       │       ├───────┤ ├───────┤       │       │
 *                       │       │       │       │ │       │       │       │
 *                       └───────┴───────┴───────┘ └───────┴───────┴───────┘
 *                                                  generated by [keymapviz] */
    [LAYERS] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, LCG_SWP, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, DF(BASE), DF(COLEMAK), _______,                                                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, LCG_NRM, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                                     _______, _______, _______, _______, _______,
                                                                _______, _______, _______, _______,
                                                                        _______, _______,
                                                        _______, _______, _______, _______, _______, _______
  ),
};

enum combos {
  // SD_ALT,
  // KL_ALT,
  // DF_SFTCMD,
  // JK_SFTCMD,
  // JKL_CTL,
  // SDF_CTL,
  DK_CAPSWORD, 
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};

combo_t key_combos[] = {
  // [SD_ALT] = COMBO_ACTION(sd_combo),
  // [KL_ALT] = COMBO_ACTION(kl_combo),
  // [DF_SFTCMD] = COMBO_ACTION(df_combo),
  // [JK_SFTCMD] = COMBO_ACTION(jk_combo),
  // [JKL_CTL] = COMBO_ACTION(jkl_combo),
  // [SDF_CTL] = COMBO_ACTION(sdf_combo),
  [DK_CAPSWORD] = COMBO_ACTION(dk_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    // case SD_ALT:
    // case KL_ALT:
    //   if (pressed) {
    //     register_mods(MOD_LALT);
    //   } else{
    //     unregister_mods(MOD_LALT);
    //   }
    //   break;

    // case DF_SFTCMD:
    // case JK_SFTCMD:
    //   if (pressed) {
    //     register_mods(MOD_LSFT | mod_config(MOD_LGUI));
    //   } else{
    //     unregister_mods(MOD_LSFT | mod_config(MOD_LGUI));
    //   }
    //   break;

    // case JKL_CTL:
    // case SDF_CTL:
    //   if (pressed) {
    //     register_mods(mod_config(MOD_LCTL));
    //   } else{
    //     unregister_mods(mod_config(MOD_LCTL));
    //   }
    //   break;

    case DK_CAPSWORD:
      if (pressed) {
        caps_word_toggle();
      } 
      break;
  }
}

// For this to work:
// - Windows needs to have wincompose: https://github.com/samhocevar/wincompose)
// - Linux has to set the compose key to RALT (A.K.A. AltGr): https://en.wikipedia.org/wiki/Compose_key
void send_letter_with_accent(uint16_t lalt, uint16_t letter, uint16_t ralt_combo, uint16_t keycode, keyrecord_t *record) {
  uint8_t mod_state = get_mods();
  uint16_t combo = (!keymap_config.swap_lctl_lgui) ? RALT(lalt) : ralt_combo;
  del_mods(mod_state);

  if (record->tap.count && record->event.pressed){
    tap_code16(combo);
    tap_code(letter);
  } else if (record->event.pressed) {
    tap_code16(combo);
    add_mods(MOD_LSFT);
    tap_code(letter);
  }
  
  set_mods(mod_state);
}

void update_swapper(
  bool *active,
  uint16_t original_mod,
  uint16_t swapped_mod,
  uint16_t holder,
  uint16_t trigger,
  uint16_t keycode,
  keyrecord_t *record
) {
  if(!keymap_config.swap_lctl_lgui) return; // We don't swap on Mac
  uint8_t mod_state = get_mods();

  if((mod_state & original_mod) && keycode == trigger) {
    // We start swapping if we have the original_mode + trigger being pressed.
    if(record->event.pressed){
      *active = true;
      unregister_mods(original_mod);
      register_mods(swapped_mod);
    }
  }

  if((mod_state & swapped_mod) && *active){
    if(keycode == holder){
      if(!record->event.pressed){ // we reset when we stop holding the holder key
        *active = false;
        unregister_mods(swapped_mod);
        return;
      }
    }

    // we should keep swapped keys when we keep hitting the trigger key
    if(keycode == trigger) return; 

    switch(keycode){
      // let's stack modifiers
      case KC_LEFT_CTRL ... KC_RIGHT_GUI:
        return;
      
      // we reset swapper when we press other keys
      default: 
        if(record->event.pressed){
          *active = false;
          unregister_mods(swapped_mod);
          register_mods(original_mod);
        }
        return;
    }
  }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188} },

    [1] = { {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208} },

    [2] = { {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193} },

    [3] = { {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240} },

    [4] = { {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
    case 5:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool switch_apps = false;
bool switch_tabs = false;

bool sw_lang_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(!switch_tabs) update_swapper(&switch_apps, MOD_LCTL, MOD_LALT, KC_LGUI, KC_TAB, keycode, record);
  if(!switch_apps) update_swapper(&switch_tabs, MOD_LALT, MOD_LCTL, KC_LALT, KC_TAB, keycode, record);

  switch (keycode) {
    // Letter with accute (´)
    case ACUTE_A:
      send_letter_with_accent(KC_E, KC_A, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_E:
      send_letter_with_accent(KC_E, KC_E, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_I:
      send_letter_with_accent(KC_E, KC_I, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_O:
      send_letter_with_accent(KC_E, KC_O, RALT(KC_QUOTE), keycode, record);
      return false;
    case ACUTE_U:
      send_letter_with_accent(KC_E, KC_U, RALT(KC_QUOTE), keycode, record);
      return false;
    // letter with umlaut (¨)
    case UMLAU_U:
      send_letter_with_accent(KC_U, KC_U, LSFT(RALT(KC_QUOTE)), keycode, record);
      return false;
    // letter with tilde (˜)
    case TILDE_N:
      send_letter_with_accent(KC_N, KC_N, LSFT(RALT(KC_GRAVE)), keycode, record);
      return false;

    case KC_RESTORE_TAB:
      if(record->event.pressed){
        register_mods(MOD_LSFT | mod_config(MOD_LGUI));
        tap_code(KC_T);
      }else {
        unregister_mods(MOD_LSFT | mod_config(MOD_LGUI));
      }
      break;

    case SC_UNDO:
      if(record->event.pressed){
        register_mods(mod_config(MOD_LGUI));
        register_code(KC_Z);
      } else {
        unregister_mods(mod_config(MOD_LGUI));
        unregister_code(KC_Z);
      }
      return false;

    case SC_CUT:
      if(record->event.pressed){
        register_mods(mod_config(MOD_LGUI));
        register_code(KC_X);
      } else {
        unregister_mods(mod_config(MOD_LGUI));
        unregister_code(KC_X);
      }
      return false;

    case SC_COPY:
      if(record->event.pressed){
        register_mods(mod_config(MOD_LGUI));
        register_code(KC_C);
      } else {
        unregister_mods(mod_config(MOD_LGUI));
        unregister_code(KC_C);
      }
      return false;

    case SC_PASTE:
      if(record->event.pressed){
        register_mods(mod_config(MOD_LGUI));
        register_code(KC_V);
      } else {
        unregister_mods(mod_config(MOD_LGUI));
        unregister_code(KC_V);
      }
      return false;

    case SC_REDO:
      if(record->event.pressed){
        if(!keymap_config.swap_lctl_lgui){
          register_mods(MOD_LGUI | MOD_LSFT);
          register_code(KC_Z);
        } else{
          register_mods(MOD_LCTL);
          register_code(KC_Y);
        }
      } else {
        if(!keymap_config.swap_lctl_lgui){
          unregister_mods(MOD_LGUI | MOD_LSFT);
          unregister_code(KC_Z);
        } else{
          unregister_mods(MOD_LCTL);
          unregister_code(KC_Y);
        }
      }
      return false;  

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  autoshift_enable();
  
  state = update_tri_layer_state(state, NAV, SYMBOL, DIGITS);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (biton32(state)) {
    case BASE:
      if(keymap_config.swap_lctl_lgui){ // indicator that we have a swapped ctrl && gui
        ergodox_right_led_1_on();
      }
      break;
    case NAV:
      ergodox_right_led_1_on();
      break;
    case SYMBOL:
      ergodox_right_led_2_on();
      break;
    case DIGITS:
      autoshift_disable();
      ergodox_right_led_3_on();
      break;
    case SPANISH:
    case SPANISH_DH:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case LAYERS:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case COLEMAK:
      if(keymap_config.swap_lctl_lgui){ // indicator that we have a swapped ctrl && gui
        ergodox_right_led_1_on();
      }
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
      break;
  }

  return state;
};