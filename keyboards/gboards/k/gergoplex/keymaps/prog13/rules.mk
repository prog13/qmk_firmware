#----------------------------------------------------------------------------
# make gboards/k/gergoplex:prog13:dfu
#----------------------------------------------------------------------------

# Firmware options
MOUSEKEY_ENABLE = no

# Debug options
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE = no
DEBUG_MATRIX = no
CONSOLE_ENABLE = no

# Combos!
VPATH += keyboards/gboards/

# No touchy, capiche?
SRC += matrix.c i2c_master.c
ifeq ($(strip $(DEBUG_MATRIX)), yes)
	OPT_DEFS += -DDEBUG_MATRIX
endif
