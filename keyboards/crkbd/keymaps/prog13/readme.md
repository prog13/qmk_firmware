# prog13 crkbd keymap

## What has changed

- use QMK DFU bootloader
- handedness!
- add HJKL cursor keys to the Lower layer
- unbind all `KC_F*` keys
- replace `KC_ESC` with `KC_TAB`
- replace `CTL_T(KC_TAB)` with `CTL_T(KC_ESC)`
- unbind `KC_SLSH`, `KC_BSLS` and `KC_PIPE`, use `SLASH_PIPE` tap-dance instead

## Build

```
make crkbd:prog13:dfu-split-<side>
```
