/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _GAMING,
    _GAMING2,
    _NAV,
    _SYM,
    _NUM,
    _FUNCTION,
    _BRACKETS
};


// Aliases for readability
#define COLEMAK  DF(_COLEMAK_DH)
#define GAMING   DF(_GAMING)

#define SYM      MO(_SYM)
#define FKEYS    MO(_FUNCTION)
#define NUM      MO(_NUM)

#define FK_SPC   LT(_FUNCTION, KC_SPC)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define BRC_ENT  LT(_BRACKETS, KC_ENT)

#define GAMING2  OSL(_GAMING2)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define ALT_BSPC MT(MOD_RALT, KC_BSPC)

// Homerow modifiers
#define HOME_A LALT_T(KC_A)
#define HOME_R LCTL_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LGUI_T(KC_T)
#define HOME_O RALT_T(KC_O)
#define HOME_I RCTL_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N RGUI_T(KC_N)
// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc| Alt/A|Ctrl/R|Shft/S| GUI/T|   G  |                              |   M  | GUI/N|Shft/E|Ctrl/I| Alt/O|Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |      |  |GAMING|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LGUI | BRC/ | Space| Num  |  | Sym  | Space|BSpace| RAlt | Menu |
 *                        |      |      | Enter| Nav  |      |  |      | Fkeys|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  ,  KC_Q ,  KC_W   ,  KC_F  , KC_P ,   KC_B ,                                          KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_DEL,
     CTL_ESC , HOME_A, HOME_R  , HOME_S , HOME_T,  KC_G ,                                          KC_M, HOME_N , HOME_E, HOME_I ,HOME_O, CTL_QUOT,
     KC_LSFT ,  KC_Z ,  KC_X   ,  KC_C  , KC_D ,   KC_V ,   KC_LBRC , GAMING, GAMING  , KC_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                 _______, KC_LGUI, BRC_ENT, NAV_SPC , NUM    ,   SYM     ,FK_SPC,KC_BSPC, KC_RALT, KC_APP
    ),

/*
 * Base Layer: Gaming
 *
 * ,------------------------------------------.                              ,-------------------------------------------.
 * |  Y    | Tab  |   Q  |   T  |   E  |   R  |                              |   Y  |   U  |   I  |   O  |   P  | Delete |
 * |-------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Esc  |LShift|   A  |   W  |   D  |   F  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |-------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   N   | Ctrl |   Z  |   S  |   C  |   V  |   B  |   G  |  |F-keys|      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `---------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                       |   X  | LAlt |GAMENUM|Space|   M  |  | Sym  | Space|BSpace| RAlt | Menu |
 *                       `----------------------------------'  `----------------------------------'
 */
    [_GAMING] = LAYOUT(
     KC_Y   , KC_TAB  , KC_Q  , KC_T  , KC_E   ,   KC_R ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,   KC_DEL,
     KC_ESC , KC_LSFT,  KC_A  , KC_W  , KC_D   ,   KC_F ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,  KC_SCLN, CTL_QUOT,
     _______, KC_LCTL,  KC_Z  , KC_S  , KC_C   ,   KC_V , KC_B   , KC_G  ,     FKEYS  , KC_RBRC, KC_N,   KC_M ,  KC_COMM ,KC_DOT, KC_Z ,   KC_RSFT,
                                KC_X  , KC_LALT, GAMING2, KC_SPC , KC_M  ,     SYM    , KC_SPC ,KC_BSPC, KC_RALT, KC_APP
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home | PgDn | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  Alt | Ctrl | Shift|  GUI |      |                              |   ←  |   ↓  |   ↑  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |CapsLk| ScLck|  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_PGDN, KC_END,  _______, KC_DEL,
      _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_CAPS, KC_SLCK, _______, _______, _______, _______, _______, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |      |      |      |      |      |                              |      |      |      |      |      | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  =   |  +   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
     KC_GRV  , _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_DEL ,
     KC_TILD , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL , KC_PLUS, _______,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT , KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      |  GUI | Shift| Ctrl |  Alt |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RGUI, KC_RSFT, KC_RCTL, KC_LALT, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Numbers Layer: Full numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |   /  |   7  |   8  |   9  |   -  | Delete |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LAlt | LCtrl|LShift| LGUI |      |                              |   *  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   =  |   1  |   2  |   3  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |   .  |   0  |BSpace|Enter |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_SLSH, KC_7   , KC_8   , KC_9   , KC_MINS, KC_DEL ,
      _______, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, _______,                                     KC_ASTR, KC_4   , KC_5   , KC_6   , KC_PLUS, KC_LPRN,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_EQL , KC_1   , KC_2   , KC_3   , KC_EQL , KC_RPRN,
                                 _______, _______, _______, _______, _______, KC_DOT , KC_0   , _______, KC_ENT , _______
    ),

/*
 * Gaming Additions: adds numbers for the gaming layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   F4   |  F3  |  F2  |  F1  |   P  |   I  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   5  |   1  |   2  |   3  |   4  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Ctrl  |   0  |   6  |   7  |   8  |   9  |      |Colmak|  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LAlt |      |   -  |   =  |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAMING2] = LAYOUT(
      KC_F4  , KC_F3  , KC_F2  , KC_F1  , KC_P   , KC_I   ,                                     _______, _______, _______, _______, _______, _______,
      KC_F5  , KC_5   , KC_1   , KC_2   , KC_3   , KC_4   ,                                     _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_0   , KC_6   , KC_7   , KC_8   , KC_9   , _______, COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_LALT, _______, KC_MINS, KC_EQL , _______, _______, _______, _______, _______
    ),

/*
 * Brackets: Layer for brackets and some numbers
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |   {  |   [  |   (  |      |                              |      |   )  |   ]  |   }  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |      |      |  |      |      |   6  |   7  |   8  |   9  |   0  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BRACKETS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_LCBR, KC_LBRC, KC_LPRN, _______,                                     _______, KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,
      _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev2\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _GAMING:
                oled_write_P(PSTR("Gaming\n"), false);
                break;
            case _GAMING2:
                oled_write_P(PSTR("Gaming Plus\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Num\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _BRACKETS:
                oled_write_P(PSTR("Brackets\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();

        // force numlock not needed ... no numblock anymore
        // if (!led_usb_state.num_lock) {
        //     register_code(KC_NUMLOCK);
        //     unregister_code(KC_NUMLOCK);
        // }

        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
//   rgblight_enable_noeeprom(); // Enables RGB, without saving settings
    rgblight_reload_from_eeprom();
    rgblight_sethsv(220, 255, 150);
//   rgblight_sethsv_noeeprom(220, 255, 150);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

bool process_global_quick_tap(uint16_t keycode, keyrecord_t *record) {
  static uint16_t global_quick_tap_timer = 0;
  if (keycode < QK_MOD_TAP || keycode > QK_MOD_TAP_MAX) {
    global_quick_tap_timer = timer_read();
    return true;
  }
  if (timer_elapsed(global_quick_tap_timer) > TAPPING_TERM) {
    return true;
  }
  if (record->event.pressed) {
    keycode = keycode & 0xFF;
    global_quick_tap_timer = timer_read();
    tap_code(keycode);
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_global_quick_tap(keycode, record)) {
        return false;
    }
    return true;
}
