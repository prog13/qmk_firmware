#include QMK_KEYBOARD_H
#include "prog13.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layer_names {
  _QWERTY,
  _SYMB,
  _NUMB,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_NUMB  LT(_NUMB, KC_ENT)
#define KC_SYMB  LT(_SYMB, KC_SPC)
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_CTLE  CTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
       TAB,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P,  BSPC,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
      CTLE,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,  QUOT,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
      LSFT,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  RSFT,\
  //└──────┴──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┴──────┘
                                  RALT,  LGUI,  SYMB,     NUMB,  BSPC,   TAB \
                              //└──────┴──────┴──────┘  └──────┴──────┴──────┘
  ),

  [_NUMB] = LAYOUT_kc( \
  //┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
     _____,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0, _____,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
     _____,   F1,    F2,    F3,    F4,    F5,                    LEFT,  DOWN,    UP, RIGHT, XXXXX, XXXXX,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
     _____,   F6,    F7,    F8,    F9,   F10,                    MS_L,  MS_D,  MS_U,  MS_R, XXXXX, _____,\
  //└──────┴──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┴──────┘
                                  RALT,  LGUI,  SYMB,     NUMB,  BSPC,   TAB \
                              //└──────┴──────┴──────┘  └──────┴──────┴──────┘
  ),

  [_SYMB] = LAYOUT_kc( \
  //┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
     _____,  EXLM,    AT,  LCBR,  RCBR,  PIPE,                    GRV,  TILD,  BSLS, XXXXX, XXXXX, _____,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
     _____,  HASH,   DLR,  LPRN,  RPRN,  BTN2,                   PLUS,  MINS,  SLSH,  ASTR, XXXXX, XXXXX,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
     _____,  PERC,  CIRC,  LBRC,  RBRC,  BTN1,                   AMPR,   EQL, _____, _____, XXXXX, _____,\
  //└──────┴──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┴──────┘
                                  RALT,  LGUI,  SYMB,     NUMB,  BSPC,   TAB \
                              //└──────┴──────┴──────┘  └──────┴──────┴──────┘
  ),

  [_ADJUST] = LAYOUT_kc( \
  //┌──────┬──────┬──────┬──────┬──────┬──────┐                ┌──────┬──────┬──────┬──────┬──────┬──────┐
     XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
      LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //├──────┼──────┼──────┼──────┼──────┼──────┤                ├──────┼──────┼──────┼──────┼──────┼──────┤
      LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //└──────┴──────┴──────┴──────┼──────┼──────┼──────┐  ┌──────┼──────┼──────┼──────┴──────┴──────┴──────┘
                                  RALT,  LGUI,  SYMB,     NUMB,  BSPC,   TAB \
                              //└──────┴──────┴──────┘  └──────┴──────┴──────┘
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMB, _NUMB, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
