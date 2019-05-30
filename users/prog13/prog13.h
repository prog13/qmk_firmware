#include "quantum.h"

#ifdef TAP_DANCE_ENABLE
  #include "tap_dance.h"
#endif

#ifdef TAP_DANCE_ENABLE
  #define KC_SLPI TD(SLASH_PIPE)
#else
  #define KC_SLPI KC_SLSH
#endif
