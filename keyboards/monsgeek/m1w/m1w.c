// Copyright 2024 (@priyadie)
// Copyright 2024 Su (@isuua)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef WIRELESS_ENABLE
#include "wireless.h"
#endif

#ifdef RGB_MATRIX_ENABLE

const aw20216s_led_t g_aw20216s_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |     R location
 *   |     |          G location
 *   |     |          |          B location
 *   |     |          |          | */
    {0,  SW3_CS1,   SW3_CS2,   SW3_CS3   }, //  0  Esc
    {0,  SW4_CS1,   SW4_CS2,   SW4_CS3   }, //  1  F1
    {0,  SW5_CS1,   SW5_CS2,   SW5_CS3   }, //  2  F2
    {0,  SW6_CS1,   SW6_CS2,   SW6_CS3   }, //  3  F3
    {0,  SW7_CS1,   SW7_CS2,   SW7_CS3   }, //  4  F4
    {0,  SW8_CS1,   SW8_CS2,   SW8_CS3   }, //  5  F5
    {0,  SW9_CS1,   SW9_CS2,   SW9_CS3   }, //  6  F6
    {0, SW10_CS1,  SW10_CS2,  SW10_CS3  },  //  7  F7
    {0, SW11_CS1,  SW11_CS2,  SW11_CS3  },  //  8  F8
    {0, SW12_CS1,  SW12_CS2,  SW12_CS3  },  //  9  F9
    {1,  SW1_CS1,   SW1_CS2,   SW1_CS3   }, //  10 F10
    {1,  SW2_CS1,   SW2_CS2,   SW2_CS3   }, //  11 F11
    {1,  SW3_CS1,   SW3_CS2,   SW3_CS3   }, //  12 F12
    {1,  SW4_CS1,   SW4_CS2,   SW4_CS3   }, //  13 Del

    {0,  SW3_CS4,   SW3_CS5,   SW3_CS6  },  //  14 Esc
    {0,  SW4_CS4,   SW4_CS5,   SW4_CS6  },  //  15 1
    {0,  SW5_CS4,   SW5_CS5,   SW5_CS6  },  //  16 2
    {0,  SW6_CS4,   SW6_CS5,   SW6_CS6  },  //  17 3
    {0,  SW7_CS4,   SW7_CS5,   SW7_CS6  },  //  18 4
    {0,  SW8_CS4,   SW8_CS5,   SW8_CS6  },  //  19 5
    {0,  SW9_CS4,   SW9_CS5,   SW9_CS6  },  //  20 6
    {0, SW10_CS4,  SW10_CS5,  SW10_CS6  },  //  21 7
    {0, SW11_CS4,  SW11_CS5,  SW11_CS6  },  //  22 8
    {0, SW12_CS4,  SW12_CS5,  SW12_CS6  },  //  23 9
    {1,  SW1_CS4,   SW1_CS5,   SW1_CS6  },  //  24 0
    {1,  SW2_CS4,   SW2_CS5,   SW2_CS6  },  //  25 -
    {1,  SW3_CS4,   SW3_CS5,   SW3_CS6  },  //  26 =
    {1,  SW4_CS4,   SW4_CS5,   SW4_CS6  },  //  27 Backspace
    {1,  SW5_CS4,   SW5_CS5,   SW5_CS6  },  //  28 Home

    {0,  SW3_CS7,   SW3_CS8,   SW3_CS9  },  //  29 Tab
    {0,  SW4_CS7,   SW4_CS8,   SW4_CS9  },  //  30 Q
    {0,  SW5_CS7,   SW5_CS8,   SW5_CS9  },  //  31 W
    {0,  SW6_CS7,   SW6_CS8,   SW6_CS9  },  //  32 E
    {0,  SW7_CS7,   SW7_CS8,   SW7_CS9  },  //  33 R
    {0,  SW8_CS7,   SW8_CS8,   SW8_CS9  },  //  34 T
    {0,  SW9_CS7,   SW9_CS8,   SW9_CS9  },  //  35 Y
    {0, SW10_CS7,  SW10_CS8,  SW10_CS9  },  //  36 U
    {0, SW11_CS7,  SW11_CS8,  SW11_CS9  },  //  37 I
    {0, SW12_CS7,  SW12_CS8,  SW12_CS9  },  //  38 O
    {1,  SW1_CS7,   SW1_CS8,   SW1_CS9  },  //  39 P
    {1,  SW2_CS7,   SW2_CS8,   SW2_CS9  },  //  40 [
    {1,  SW3_CS7,   SW3_CS8,   SW3_CS9  },  //  41 ]
    {1,  SW4_CS7,   SW4_CS8,   SW4_CS9  },  //  42 \|
    {1,  SW5_CS7,   SW5_CS8,   SW5_CS9  },  //  43 Del

    {0,  SW3_CS10,  SW3_CS11,  SW3_CS12 },  //  44 Caps Lock
    {0,  SW4_CS10,  SW4_CS11,  SW4_CS12 },  //  45 A
    {0,  SW5_CS10,  SW5_CS11,  SW5_CS12 },  //  46 S
    {0,  SW6_CS10,  SW6_CS11,  SW6_CS12 },  //  47 D
    {0,  SW7_CS10,  SW7_CS11,  SW7_CS12 },  //  48 F
    {0,  SW8_CS10,  SW8_CS11,  SW8_CS12 },  //  49 G
    {0,  SW9_CS10,  SW9_CS11,  SW9_CS12 },  //  50 H
    {0, SW10_CS10, SW10_CS11, SW10_CS12 },  //  51 J
    {0, SW11_CS10, SW11_CS11, SW11_CS12 },  //  52 K
    {0, SW12_CS10, SW12_CS11, SW12_CS12 },  //  53 L
    {1,  SW1_CS10,  SW1_CS11,  SW1_CS12 },  //  54 ;
    {1,  SW2_CS10,  SW2_CS11,  SW2_CS12 },  //  55 '
    {1,  SW3_CS10,  SW3_CS11,  SW3_CS12 },  //  56 Enter
    {1,  SW5_CS10,  SW5_CS11,  SW5_CS12 },  //  57 Home

    {0,  SW3_CS13,  SW3_CS14,  SW3_CS15 },  //  58 Shift_L
    {0,  SW5_CS13,  SW5_CS14,  SW5_CS15 },  //  59 Z
    {0,  SW6_CS13,  SW6_CS14,  SW6_CS15 },  //  60 X
    {0,  SW7_CS13,  SW7_CS14,  SW7_CS15 },  //  61 C
    {0,  SW8_CS13,  SW8_CS14,  SW8_CS15 },  //  62 V
    {0,  SW9_CS13,  SW9_CS14,  SW9_CS15 },  //  63 B
    {0, SW10_CS13, SW10_CS14, SW10_CS15 },  //  64 N
    {0, SW11_CS13, SW11_CS14, SW11_CS15 },  //  65 M
    {0, SW12_CS13, SW12_CS14, SW12_CS15 },  //  66 ,
    {1,  SW1_CS13,  SW1_CS14,  SW1_CS15 },  //  67 .
    {1,  SW2_CS13,  SW2_CS14,  SW2_CS15 },  //  68 /
    {1,  SW3_CS13,  SW3_CS14,  SW3_CS15 },  //  69 Shift_R
    {1,  SW4_CS13,  SW4_CS14,  SW4_CS15 },  //  70 Up
    {1,  SW5_CS13,  SW5_CS14,  SW5_CS15 },  //  71 End

    {0,  SW3_CS16,  SW3_CS17,  SW3_CS18 },  //  72 Ctrl_L
    {0,  SW4_CS16,  SW4_CS17,  SW4_CS18 },  //  73 Win_L
    {0,  SW5_CS16,  SW5_CS17,  SW5_CS18 },  //  74 Alt_L
    {0,  SW9_CS16,  SW9_CS17,  SW9_CS18 },  //  75 Space
    {0, SW12_CS16, SW12_CS17, SW12_CS18 },  //  76 Alt_R
    {1,  SW1_CS16,  SW1_CS17,  SW1_CS18 },  //  77 Ctrl_R
    {1,  SW2_CS16,  SW2_CS17,  SW2_CS18 },  //  78 Fn
    {1,  SW3_CS16,  SW3_CS17,  SW3_CS18 },  //  79 Left
    {1,  SW4_CS16,  SW4_CS17,  SW4_CS18 },  //  80 Down
    {1,  SW5_CS16,  SW5_CS17,  SW5_CS18 },  //  81 Right

    {0, SW10_CS16, SW10_CS17, SW10_CS18 },  //  82

    {0,  SW1_CS1,   SW1_CS2,   SW1_CS3  },  //  83
    {0,  SW1_CS4,   SW1_CS5,   SW1_CS6  },  //  84
    {0,  SW1_CS7,   SW1_CS8,   SW1_CS9  },  //  85
    {0, SW1_CS10, SW1_CS11,   SW1_CS12  },  //  86
    {0, SW1_CS13, SW1_CS14,   SW1_CS15  },  //  87
    {0, SW1_CS16, SW1_CS17,   SW1_CS18  },  //  88

    {0,  SW2_CS1,   SW2_CS2,   SW2_CS3  },  //  89

    {0,  SW2_CS7,   SW2_CS8,   SW2_CS9  },  //  91
    {0, SW2_CS10, SW2_CS11,   SW2_CS12  },  //  92
    {0,  SW2_CS4,   SW2_CS5,   SW2_CS6  },  //  90

    {0, SW2_CS13, SW2_CS14,   SW2_CS15  },  //  93
    {0, SW2_CS16, SW2_CS17,   SW2_CS18  },  //  94

    {1,  SW6_CS1,   SW6_CS2,   SW6_CS3  },  //  95
    {1,  SW6_CS4,   SW6_CS5,   SW6_CS6  },  //  96
    {1,  SW6_CS7,   SW6_CS8,   SW6_CS9  },  //  97
    {1, SW6_CS10, SW6_CS11,   SW6_CS12  },  //  98
    {1, SW6_CS13, SW6_CS14,   SW6_CS15  },  //  99
    {1, SW6_CS16, SW6_CS17,   SW6_CS18  },  //  100
    {1,  SW7_CS1,   SW7_CS2,   SW7_CS3  },  //  101
    {1,  SW7_CS4,   SW7_CS5,   SW7_CS6  },  //  102
    {1,  SW7_CS7,   SW7_CS8,   SW7_CS9  },  //  103
    {1, SW7_CS10, SW7_CS11,   SW7_CS12  },  //  104
    {1, SW7_CS13, SW7_CS14,   SW7_CS15  },  //  105
    {1, SW7_CS16, SW7_CS17,   SW7_CS18  },  //  106
};

#endif  // #ifdef RGB_MATRIX_ENABLE

typedef union {
    uint32_t raw;
    struct {
        uint8_t flag : 1;
        uint8_t devs : 3;
        uint8_t wasd_enable : 1;
    };
} confinfo_t;
confinfo_t confinfo;

uint32_t post_init_timer = 0x00;
bool inqbat_flag         = false;

void eeconfig_confinfo_update(uint32_t raw) {

    eeconfig_update_kb(raw);
}

uint32_t eeconfig_confinfo_read(void) {

    return eeconfig_read_kb();
}

void eeconfig_confinfo_default(void) {

    confinfo.flag = true;
    confinfo.wasd_enable = false;
#ifdef WIRELESS_ENABLE
    confinfo.devs = DEVS_USB;
#endif

    eeconfig_confinfo_update(confinfo.raw);
}

void eeconfig_confinfo_init(void) {

    confinfo.raw = eeconfig_confinfo_read();
    if (!confinfo.raw) {
        eeconfig_confinfo_default();
    }
}

void keyboard_post_init_kb(void) {

#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif

    eeconfig_confinfo_init();

#ifdef LED_POWER_EN_PIN
    gpio_set_pin_output(LED_POWER_EN_PIN);
    gpio_write_pin_high(LED_POWER_EN_PIN);
#endif

#ifdef USB_POWER_EN_PIN
    gpio_write_pin_low(USB_POWER_EN_PIN);
    gpio_set_pin_output(USB_POWER_EN_PIN);
#endif

#ifdef WIRELESS_ENABLE
    wireless_init();
    wireless_devs_change(!confinfo.devs, confinfo.devs, false);
    post_init_timer = timer_read32();
#endif

    keyboard_post_init_user();
}

bool dip_switch_update_kb(uint8_t index, bool active) {

    if (dip_switch_update_user(index, active) != true) {
        return false;
    }

    switch (index) {
        case 0: { // Win
            set_single_persistent_default_layer(0);
        } break;
        case 1: { // Mac
            set_single_persistent_default_layer(2);
        } break;
        default: break;
    }

    return true;
}

#ifdef WIRELESS_ENABLE

void usb_power_connect(void) {

#    ifdef USB_POWER_EN_PIN
    gpio_write_pin_low(USB_POWER_EN_PIN);
#    endif
}

void usb_power_disconnect(void) {

#    ifdef USB_POWER_EN_PIN
    gpio_write_pin_high(USB_POWER_EN_PIN);
#    endif
}

void suspend_power_down_kb(void) {

#    ifdef LED_POWER_EN_PIN
    gpio_write_pin_low(LED_POWER_EN_PIN);
#    endif
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {

#    ifdef LED_POWER_EN_PIN
    gpio_write_pin_high(LED_POWER_EN_PIN);
#    endif

    wireless_devs_change(wireless_get_current_devs(), wireless_get_current_devs(), false);
    suspend_wakeup_init_user();
}

bool lpwr_is_allow_timeout_hook(void) {

    if (wireless_get_current_devs() == DEVS_USB) {
        return false;
    }

    return true;
}

void wireless_post_task(void) {

    // auto switching devs
    if (post_init_timer && timer_elapsed32(post_init_timer) >= 100) {
        md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_BT_EN);  // timeout 30min to sleep in bt mode, enable
        md_send_devctrl(MD_SND_CMD_DEVCTRL_SLEEP_2G4_EN); // timeout 30min to sleep in 2.4g mode, enable
        wireless_devs_change(!confinfo.devs, confinfo.devs, false);
        post_init_timer = 0x00;
    }
}

uint32_t wls_process_long_press(uint32_t trigger_time, void *cb_arg) {
    uint16_t keycode = *((uint16_t *)cb_arg);

    switch (keycode) {
        case KC_BT1: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT1, true);
        } break;
        case KC_BT2: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT2, true);
        } break;
        case KC_BT3: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT3, true);
        } break;
        case KC_BT4: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT4, true);
        } break;
        case KC_BT5: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_BT5, true);
        } break;
        case KC_2G4: {
            wireless_devs_change(wireless_get_current_devs(), DEVS_2G4, true);
        } break;
        default:
            break;
    }

    return 0;
}

bool process_record_wls(uint16_t keycode, keyrecord_t *record) {
    static uint16_t keycode_shadow                     = 0x00;
    static deferred_token wls_process_long_press_token = INVALID_DEFERRED_TOKEN;

    keycode_shadow = keycode;

#    ifndef WLS_KEYCODE_PAIR_TIME
#        define WLS_KEYCODE_PAIR_TIME 3000
#    endif

#    define WLS_KEYCODE_EXEC(wls_dev)                                                                                          \
        do {                                                                                                                   \
            if (record->event.pressed) {                                                                                       \
                wireless_devs_change(wireless_get_current_devs(), wls_dev, false);                                             \
                if (wls_process_long_press_token == INVALID_DEFERRED_TOKEN) {                                                  \
                    wls_process_long_press_token = defer_exec(WLS_KEYCODE_PAIR_TIME, wls_process_long_press, &keycode_shadow); \
                }                                                                                                              \
            } else {                                                                                                           \
                cancel_deferred_exec(wls_process_long_press_token);                                                            \
                wls_process_long_press_token = INVALID_DEFERRED_TOKEN;                                                         \
            }                                                                                                                  \
        } while (false)

    switch (keycode) {
        case KC_BT1: {
            WLS_KEYCODE_EXEC(DEVS_BT1);
        } break;
        case KC_BT2: {
            WLS_KEYCODE_EXEC(DEVS_BT2);
        } break;
        case KC_BT3: {
            WLS_KEYCODE_EXEC(DEVS_BT3);
        } break;
        case KC_BT4: {
            WLS_KEYCODE_EXEC(DEVS_BT4);
        } break;
        case KC_BT5: {
            WLS_KEYCODE_EXEC(DEVS_BT5);
        } break;
        case KC_2G4: {
            WLS_KEYCODE_EXEC(DEVS_2G4);
        } break;
        case KC_USB: {
            if (record->event.pressed) {
                wireless_devs_change(wireless_get_current_devs(), DEVS_USB, false);
            }
        } break;
        case KC_BATQ: {
            inqbat_flag    = record->event.pressed;
        } break;
        default:
            return true;
    }

    return false;
}
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

    if (process_record_user(keycode, record) != true) {
        return false;
    }

#ifdef WIRELESS_ENABLE
    if (process_record_wls(keycode, record) != true) {
        return false;
    }
#endif

    switch (keycode) {
        case KC_WASD: {
            if (record->event.pressed) {
                confinfo.wasd_enable = !confinfo.wasd_enable;
                eeconfig_confinfo_update(confinfo.raw);
            }
            return false;
        } break;
        case KC_W: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_UP);
                } else {
                    unregister_code(KC_UP);
                }
                return false;
            }
            return true;
        } break;
        case KC_A: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_LEFT);
                } else {
                    unregister_code(KC_LEFT);
                }
                return false;
            }
            return true;
        } break;
        case KC_S: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_DOWN);
                } else {
                    unregister_code(KC_DOWN);
                }
                return false;
            }
            return true;
        } break;
        case KC_D: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_RGHT);
                } else {
                    unregister_code(KC_RGHT);
                }
                return false;
            }
            return true;
        } break;
        case KC_UP: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_W);
                } else {
                    unregister_code(KC_W);
                }
                return false;
            }
            return true;
        } break;
        case KC_LEFT: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_A);
                } else {
                    unregister_code(KC_A);
                }
                return false;
            }
            return true;
        } break;
        case KC_DOWN: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_S);
                } else {
                    unregister_code(KC_S);
                }
                return false;
            }
            return true;
        } break;
        case KC_RGHT: {
            if (confinfo.wasd_enable) {
                if (record->event.pressed) {
                    register_code(KC_D);
                } else {
                    unregister_code(KC_D);
                }
                return false;
            }
            return true;
        } break;
        default:
            return true;
    }

    return false;
}

#ifdef RGB_MATRIX_ENABLE

#    ifdef WIRELESS_ENABLE
bool wls_rgb_indicator_reset        = false;
uint32_t wls_rgb_indicator_timer    = 0x00;
uint32_t wls_rgb_indicator_interval = 0;
uint32_t wls_rgb_indicator_times    = 0;
uint32_t wls_rgb_indicator_index    = 0;
RGB wls_rgb_indicator_rgb           = {0};

void rgb_matrix_wls_indicator_set(uint8_t index, RGB rgb, uint32_t interval, uint8_t times) {

    wls_rgb_indicator_timer = timer_read32();

    wls_rgb_indicator_index    = index;
    wls_rgb_indicator_interval = interval;
    wls_rgb_indicator_times    = times * 2;
    wls_rgb_indicator_rgb      = rgb;
}

void wireless_devs_change_kb(uint8_t old_devs, uint8_t new_devs, bool reset) {

    wls_rgb_indicator_reset = reset;

    if (confinfo.devs != wireless_get_current_devs()) {
        confinfo.devs = wireless_get_current_devs();
        eeconfig_confinfo_update(confinfo.raw);
    }

    switch (new_devs) {
        case DEVS_BT1: {
            if (reset) {
                rgb_matrix_wls_indicator_set(32, (RGB){RGB_BLUE}, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(32, (RGB){RGB_BLUE}, 500, 1);
            }
        } break;
        case DEVS_BT2: {
            if (reset) {
                rgb_matrix_wls_indicator_set(33, (RGB){RGB_BLUE}, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(33, (RGB){RGB_BLUE}, 500, 1);
            }
        } break;
        case DEVS_BT3: {
            if (reset) {
                rgb_matrix_wls_indicator_set(34, (RGB){RGB_BLUE}, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(34, (RGB){RGB_BLUE}, 500, 1);
            }
        } break;
        case DEVS_2G4: {
            if (reset) {
                rgb_matrix_wls_indicator_set(35, (RGB){RGB_GREEN}, 200, 1);
            } else {
                rgb_matrix_wls_indicator_set(35, (RGB){RGB_GREEN}, 500, 1);
            }
        } break;
        default:
            break;
    }
}

bool rgb_matrix_wls_indicator_cb(void) {

    if (*md_getp_state() != MD_STATE_CONNECTED) {
        wireless_devs_change_kb(wireless_get_current_devs(), wireless_get_current_devs(), wls_rgb_indicator_reset);
        return true;
    }

    // refresh led
    led_wakeup();

    return false;
}

void rgb_matrix_wls_indicator(void) {

    if (wls_rgb_indicator_timer) {

        if (timer_elapsed32(wls_rgb_indicator_timer) >= wls_rgb_indicator_interval) {
            wls_rgb_indicator_timer = timer_read32();

            if (wls_rgb_indicator_times) {
                wls_rgb_indicator_times--;
            }

            if (wls_rgb_indicator_times <= 0) {
                wls_rgb_indicator_timer = 0x00;
                if (rgb_matrix_wls_indicator_cb() != true) {
                    return;
                }
            }
        }

        if (wls_rgb_indicator_times % 2) {
            rgb_matrix_set_color(wls_rgb_indicator_index, wls_rgb_indicator_rgb.r, wls_rgb_indicator_rgb.g, wls_rgb_indicator_rgb.b);
        } else {
            rgb_matrix_set_color(wls_rgb_indicator_index, 0x00, 0x00, 0x00);
        }
    }

    if (inqbat_flag) {
        for (uint8_t i = 0; i < 10; i++) {
            uint8_t mi_index[10] = RGB_MATRIX_BAT_INDEX_MAP;
            if (i < (*md_getp_bat() / 10)) {
                if (*md_getp_bat() >= 50) {
                    rgb_matrix_set_color(mi_index[i], RGB_GREEN);
                } else if (*md_getp_bat() >= 30) {
                    rgb_matrix_set_color(mi_index[i], RGB_GREEN);
                } else {
                    rgb_matrix_set_color(mi_index[i], RGB_RED);
                }
            } else {
                rgb_matrix_set_color(mi_index[i], 0x00, 0x00, 0x00);
            }
        }
    }
}
#    endif

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {

    if (rgb_matrix_indicators_advanced_user(led_min, led_max) != true) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(44, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    }

    if (keymap_config.no_gui) {
        rgb_matrix_set_color(73, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS, RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    }

#    ifdef WIRELESS_ENABLE
    rgb_matrix_wls_indicator();
#    endif

    return true;
}
#endif
