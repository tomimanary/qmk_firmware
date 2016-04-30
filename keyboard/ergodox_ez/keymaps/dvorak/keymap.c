#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  | Nlck |           |  PRT |   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   '  |   ,  |   .  |   P  |   Y  |  DEL |           |  =   |   F  |   G  |   C  |   R  |   L  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------|  Bksp|           |  ~   |------+------+------+------+------+--------|
 * |   ~L1  |   ;  |   Q  |   J  |   K  |   X  |      |           |  `   |   B  |   M  |   W  |   V  |   Z  |   /    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Super|  ESC |  Tab | Super| Bksp |                                       |  ~L1 |   -  |   /  |  `~  | Super  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Down |       |  Up  | Right |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | +L1  |       |  +   |       |      |
 *                                 | Enter| Ctrl |------|       |------|  Alt  | S/SPC|
 *                                 |      |      |  :   |       |  *   |       |      |
 *                                 `--------------------'       `---------------------'
*/
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_NLCK,
        KC_TAB,         KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_DELETE,
        KC_LCTL,        KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        MO(1),          KC_SCLN,        KC_Q,    KC_J,   KC_K,   KC_X,   KC_BSPC,
        KC_LGUI,        KC_ESC,         KC_TAB,  KC_LGUI,KC_BSPC,
                                                      KC_LEFT,KC_DOWN,
                                                              TG(1),
                                               KC_ENT,KC_LCTL,S(KC_SCLN),
        // right hand
             KC_PSCR,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSLS,
             KC_EQL,      KC_F,   KC_G,   KC_C,   KC_R,   KC_L,             KC_BSLS,
                          KC_D,   KC_H,   KC_T,   KC_N,   KC_S,             KC_MINS,
             KC_GRAVE,    KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,             KC_SLSH,
                                  MO(1)  ,KC_MINS,KC_SLSH,KC_GRAVE,         KC_RGUI,
             KC_UP,  KC_RGHT,
             KC_PPLS,
             KC_PAST,KC_RALT, SFT_T(KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | reset|      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |  ª  |   {  |   }  |      |           |      | PgUp |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   © |  «  |   ¨ |   $  |------|           |------| PgDn |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   [  |   ]  |   (  |   )  |   &  |      |           |      |   `  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   L2 |insert| Super| Bksp |                                       |  fn  |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Enter| Ctrl |------|       |------|  Alt | S/SPC|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP( 
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR, KC_TRNS,.`
       KC_TRNS, KC_HASH, KC_LEFT, KC_DOWN, KC_RIGHT,KC_DLR,
       KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_TRNS,
       KC_TRNS, TG(MDIA),KC_INS,  KC_LGUI, KC_BSPC,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_PGUP, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_PGDN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  INS | home | MsUp |  end | PgUp |      |           |      |  ª  |  f7  |  f8  |  f9  |  f10 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  DEL |MsLeft|MsDown|MsRght| PgDn |------|           |------|  «  |  f4  |  f5  |  f6  |  f11 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |volup | Lclk | Rclk | reset|      |           |      |      |  f1  |  f2  |  f3  |  f12 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |voldn | Super| Bksp |                                       |  L0  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_INS,   KC_HOME,   KC_MS_U, KC_END,  KC_PGUP, KC_TRNS,
       KC_TRNS, KC_DELETE,KC_MS_L,   KC_MS_D, KC_MS_R, KC_PGDN,
       KC_TRNS, KC_TRNS,  KC_VOLU,   KC_BTN1, KC_BTN2, RESET,   KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_VOLD,   KC_LGUI, KC_BSPC,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
                 KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_TRNS,
                          TG(0),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
