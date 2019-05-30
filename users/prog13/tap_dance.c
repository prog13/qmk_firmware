/*
 * Original tap-dance code and comments by users/gordon.
*/

#include "tap_dance.h"

int cur_dance (qk_tap_dance_state_t *state);

void slash_finished (qk_tap_dance_state_t *state, void *user_data);
void slash_reset (qk_tap_dance_state_t *state, void *user_data);

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    // Key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
     */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  /*
   * Assumes no one is trying to type the same letter three times (at least not quickly).
   * If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
   * an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
   */
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; // Magic number. At some point this method will expand to work for more presses.
}

// Instanalize an instance of 'tap' for the 'slash' tap dance.
static tap slash_tap_state = {
  .is_press_action = true,
  .state = 0
};

void slash_finished (qk_tap_dance_state_t *state, void *user_data) {
  slash_tap_state.state = cur_dance(state);
  switch (slash_tap_state.state) {
    case SINGLE_TAP: register_code(KC_SLSH); break;
    case DOUBLE_TAP: register_code16(KC_BSLS); break;
    case TRIPLE_TAP: register_code16(KC_PIPE); break;
    /*
     * Last case is for fast typing. Assuming your key is `f`.
     * For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
     * In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
     */
    case DOUBLE_SINGLE_TAP: register_code(KC_SLSH); unregister_code16(KC_SLSH); register_code16(KC_SLSH);
  }
}

void slash_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (slash_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_SLSH); break;
    case DOUBLE_TAP: unregister_code16(KC_BSLS); break;
    case TRIPLE_TAP: unregister_code16(KC_PIPE); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_SLSH);
  }
  slash_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SLASH_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slash_finished, slash_reset),
};
