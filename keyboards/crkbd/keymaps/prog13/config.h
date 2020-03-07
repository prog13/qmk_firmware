#pragma once

#define EE_HANDS

// #define SSD1306OLED

#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
  #undef RGBLED_NUM
  #define RGBLED_NUM 27
  #define RGBLIGHT_LIMIT_VAL 120
  #define RGBLIGHT_HUE_STEP 10
  #define RGBLIGHT_SAT_STEP 17
  #define RGBLIGHT_VAL_STEP 12
  // #define RGBLIGHT_SLEEP
  #define RGBLIGHT_SPLIT
  // #define RGBLIGHT_ANIMATIONS
  // #define RGBLIGHT_EFFECT_ALTERNATING
  // #define RGBLIGHT_EFFECT_BREATHING
  // #define RGBLIGHT_EFFECT_CHRISTMAS
  // #define RGBLIGHT_EFFECT_KNIGHT
  // #define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 21
  // #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 6
  // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  // #define RGBLIGHT_EFFECT_RGB_TEST
  // #define RGBLIGHT_EFFECT_SNAKE
  // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif

#ifdef RGB_MATRIX_ENABLE
  #undef RGBLED_NUM
  #define RGBLED_NUM 54
  #define DRIVER_LED_TOTAL RGBLED_NUM
  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
  // #define RGB_MATRIX_LED_PROCESS_LIMIT 5
  // #define RGB_MATRIX_LED_FLUSH_LIMIT 26
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
  #define RGB_MATRIX_HUE_STEP 8
  #define RGB_MATRIX_SAT_STEP 8
  #define RGB_MATRIX_VAL_STEP 5
  #define RGB_MATRIX_SPD_STEP 10
  #define RGB_MATRIX_KEYPRESSES
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_DISABLE_WHEN_USB_SUSPENDED true

  // #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  // #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  // #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #define DISABLE_RGB_MATRIX_BREATHING
  #define DISABLE_RGB_MATRIX_BAND_SAT
  #define DISABLE_RGB_MATRIX_BAND_VAL
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #define DISABLE_RGB_MATRIX_CYCLE_ALL
  #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define DISABLE_RGB_MATRIX_DUAL_BEACON
  #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
  #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define DISABLE_RGB_MATRIX_RAINDROPS

  #ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
    // #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
    #define DISABLE_RGB_MATRIX_DIGITAL_RAIN

    #ifndef DISABLE_RGB_MATRIX_DIGITAL_RAIN
      #define RGB_DIGITAL_RAIN_DROPS 12
    #endif
  #endif

  #ifdef RGB_MATRIX_KEYPRESSES
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define DISABLE_RGB_MATRIX_SPLASH
    #define DISABLE_RGB_MATRIX_MULTISPLASH
    #define DISABLE_RGB_MATRIX_SOLID_SPLASH
    #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
  #endif
#endif

#undef PRODUCT
#define PRODUCT Hacked Corne Keyboard
#undef MANUFACTURER
#define MANUFACTURER prog13
