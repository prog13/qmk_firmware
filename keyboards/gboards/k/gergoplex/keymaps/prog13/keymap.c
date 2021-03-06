#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define BASE 0
#define WINS 1
#define SYMB 2
#define NUMB 3

/*
 * ┌──────┬──────┬──────┬──────┬──────┐                     ┌──────┬──────┬──────┬──────┬──────┐
 * │      │     ESC     │      │      │                     │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┤                     ├──────┼──────┼──────┼──────┼──────┤
 * │      │     BSPC   TAB     │      │                     │     LES    COLN   GRT     │      |
 * ├──────┼──────┼──────┼──RMB─┼──LMB─┤                     ├──────┼──────┼──────┼──────┼──────┤
 * │      │     MINS   ENT     │      │                     │     QUO    UNDR    │      │      │
 * └──────┴──────┴──────┴──────┴──────┘                     └──────┴──────┴──────┴──────┴──────┘
 *         ┌────────┬────────┬────────┐                     ┌────────┬────────┬────────┐
 *         │        │        │        │                     │        │        │        │
 *         └────────┴────────┴────────┘                     └────────┴────────┴────────┘
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┐
     * │   Q  │   W  │   E  │   R  │   T  │                 │   Y  │   U  │   I  │   O  │   P  │
     * ├──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┤
     * │CTRL/A│   S  │   D  │   F  │   G  │                 │   H  │   J  │   K  │   L  │CTRL/;|
     * ├──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┤
     * │SHFT/Z│   X  │   C  │   V  │   B  │                 │   N  │   M  │   ,  │   .  │SHFT/?│
     * └──────┴──────┴──────┴──────┴──────┘                 └──────┴──────┴──────┴──────┴──────┘
     *         ┌────────┬────────┬────────┐                 ┌────────┬────────┬────────┐
     *         │  RALT  │  LGUI  │SPC(SYM)│                 │ENT(NUM)│  BSPC  │SHFT/TAB│
     *         └────────┴────────┴────────┘                 └────────┴────────┴────────┘
     */
    [BASE] = LAYOUT_gergoplex(
        KC_Q,               KC_W, KC_E, KC_R, KC_T,         KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        MT(MOD_LCTL, KC_A), KC_S, KC_D, KC_F, KC_G,         KC_H, KC_J, KC_K,    KC_L,   MT(MOD_RCTL, KC_SCLN),
        MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_V, KC_B,         KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

        KC_RALT, KC_LGUI, LT(SYMB, KC_SPC),                 LT(NUMB, KC_ENT), KC_BSPC, MT(MOD_RSFT, KC_TAB)
    ),

    /*
     * ┌──────┬──────┬──────┬──────┬──────┐                 ┌──────┬──────┬──────┬──────┬──────┐
     * │   Q  │   W  │   E  │   R  │   T  │                 │   Y  │   U  │   I  │   O  │   P  │
     * ├──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┤
     * │LGUI/A│   S  │   D  │   F  │   G  │                 │   H  │   J  │   K  │   L  │CTRL/;|
     * ├──────┼──────┼──────┼──────┼──────┤                 ├──────┼──────┼──────┼──────┼──────┤
     * │SHFT/Z│   X  │   C  │   V  │   B  │                 │   N  │   M  │   ,  │   .  │SHFT/?│
     * └──────┴──────┴──────┴──────┴──────┘                 └──────┴──────┴──────┴──────┴──────┘
     *         ┌────────┬────────┬────────┐                 ┌────────┬────────┬────────┐
     *         │  RALT  │  CTRL  │SPC(SYM)│                 │ENT(NUM)│  BSPC  │SHFT/TAB│
     *         └────────┴────────┴────────┘                 └────────┴────────┴────────┘
     */
    [WINS] = LAYOUT_gergoplex(
        KC_Q,               KC_W, KC_E, KC_R, KC_T,         KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        MT(MOD_LGUI, KC_A), KC_S, KC_D, KC_F, KC_G,         KC_H, KC_J, KC_K,    KC_L,   MT(MOD_RCTL, KC_SCLN),
        MT(MOD_LSFT, KC_Z), KC_X, KC_C, KC_V, KC_B,         KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

        KC_RALT, KC_LCTL, LT(SYMB, KC_SPC),                 LT(NUMB, KC_ENT), KC_BSPC, MT(MOD_RSFT, KC_TAB)
    ),

    /*
    * ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
    * │   !  │   @  │   {  │   }  │   |  │                  │   `  │   ~  │   \  │      │ WINS │
    * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
    * │   #  │   $  │   (  │   )  │  LMB │                  │   +  │   -  │   /  │   *  │   '  |
    * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
    * │   %  │   ^  │   [  │   ]  │  RMB │                  │   &  │   =  │   ,  │   .  │SHFT/?│
    * └──────┴──────┴──────┴──────┴──────┘                  └──────┴──────┴──────┴──────┴──────┘
    *         ┌────────┬────────┬────────┐                  ┌────────┬────────┬────────┐
    *         │  RALT  │  LGUI  │        │                  │ SCOLON │  BSPC  │SHFT/TAB│
    *         └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    */
    [SYMB] = LAYOUT_gergoplex(
        KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,        KC_GRV,  KC_TILD, KC_BSLS, KC_NO,   TG(WINS),
        KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_BTN2,        KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_QUOT,
        KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BTN1,        KC_AMPR, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,                          KC_SCLN, KC_TRNS, KC_TRNS
    ),

    /*
    * ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
    * │   1  │   2  │   3  │   4  │   5  │                  │   6  │   7  │   8  │   9  │   0  │
    * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
    * │  F1  │  F2  │  F3  │  F4  │  F5  │                  │ LEFT │ DOWN │  UP  │ RIGHT│VOL_UP|
    * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
    * │  F6  │  F7  │  F8  │  F9  │  F10 │                  │M_LEFT│M_DOWN│ M_UP │M_RGHT│VOL_DN│
    * └──────┴──────┴──────┴──────┴──────┘                  └──────┴──────┴──────┴──────┴──────┘
    *         ┌────────┬────────┬────────┐                  ┌────────┬────────┬────────┐
    *         │   F11  │   F12  │SPC(SYM)│                  │        │  PLAY  │  SKIP  │
    *         └────────┴────────┴────────┘                  └────────┴────────┴────────┘
    */
    [NUMB] = LAYOUT_gergoplex(
        KC_1,   KC_2,   KC_3,  KC_4,  KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLU,
        KC_F6,  KC_F7,  KC_F8, KC_F9, KC_F10,               KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_VOLD,

        KC_F11, KC_F12, KC_TRNS,                            KC_TRNS, KC_MPLY, KC_MNXT
    ),
};

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();

  switch (keycode) {
    case KC_H:
      if (mod_state & MOD_MASK_SG) {
        if (record->event.pressed) {
          // Key pressed
          register_code(KC_LEFT);
        } else {
          // Key released
          unregister_code(KC_LEFT);
        }
      }
      return false; // Skip all further processing of this key

    case KC_J:
      if (mod_state & MOD_MASK_SG) {
        if (record->event.pressed) {
          register_code(KC_DOWN);
        } else {
          unregister_code(KC_DOWN);
        }
      }
      return false;

    case KC_K:
      if (mod_state & MOD_MASK_SG) {
        if (record->event.pressed) {
          register_code(KC_UP);
        } else {
          unregister_code(KC_UP);
        }
      }
      return false;

    case KC_L:
      if (mod_state & MOD_MASK_SG) {
        if (record->event.pressed) {
          register_code(KC_RIGHT);
        } else {
          unregister_code(KC_RIGHT);
        }
      }
      return false;

    default:
      return true; // Process all other keycodes normally
  }
};
