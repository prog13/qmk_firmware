SRC += prog13.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif
