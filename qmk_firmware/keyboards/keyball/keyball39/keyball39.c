/*
Copyright 2021 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "lib/keyball/keyball.h"

//////////////////////////////////////////////////////////////////////////////

// clang-format off
matrix_row_t matrix_mask[MATRIX_ROWS] = {
    0b00011111,
    0b00011111,
    0b00011111,
    0b00111111,
    0b00011111,
    0b00011111,
    0b00011111,
    0b00111111,
};
// clang-format on

void keyball_on_adjust_layout(keyball_adjust_t v) {
#ifdef RGBLIGHT_ENABLE
    // adjust RGBLIGHT's clipping and effect ranges
    uint8_t lednum_this = keyball.this_have_ball ? 22 : 24;
    uint8_t lednum_that = !keyball.that_enable ? 0 : keyball.that_have_ball ? 22 : 24;
    rgblight_set_clipping_range(is_keyboard_left() ? 0 : lednum_that, lednum_this);
    rgblight_set_effect_range(0, lednum_this + lednum_that);
#endif
}

enum custom_keycodes {
    PASS1 = SAFE_RANGE,
    PASS2,
    PASS3,
    MAIL1,
    MAIL2,
    ADDRESS,
    NOTEPAD
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PASS1:
                SEND_STRING(SS_LSFT("K") "OBATAKUN83\n");
                return false;
            case PASS2:
                SEND_STRING("JREDN2025\n");
                return false;
            case PASS3:
                SEND_STRING("JREDN2019\n");
                return false;
            case MAIL1:
                SEND_STRING("tak-kobayashhi@" "jred.co.jp");
                return false;
            case MAIL2:
                SEND_STRING("takun83@" "icloud.com");
                return false;
            case ADDRESS:
                SEND_STRING("THE LINKPILLAR1 SOUTH 12F");
                return false;
            case NOTEPAD:
                tap_code16(LGUI(KC_R));  // Win + R
                wait_ms(100);
                SEND_STRING("notepad\n");
                return false;
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
#define LAYOUT_right_ball( \
    L00, L01, L02, L03, L04,              R04, R03, PASS3, PASS2, PASS1, \
    L10, L11, L12, L13, L14,              R14, R13, MAIL1, MAIL2, ADDRESS, \
    L20, L21, L22, L23, L24,              NOTEPAD, R23, R22, R21, R20, \
    L30, L31, L32, L33, L34, L35,    R35, R34,                R30  \
    ) \
    { \
        {   L00,   L01,   L02,   L03,   L04, KC_NO }, \
        {   L10,   L11,   L12,   L13,   L14, KC_NO }, \
        {   L20,   L21,   L22,   L23,   L24, KC_NO }, \
        {   L30,   L31,   L32,   L33,   L34,   L35 }, \
        {   R00,   R01,   R02,   R03,   R04, KC_NO }, \
        {   R10,   R11,   R12,   R13,   R14, KC_NO }, \
        {   R20,   R21,   R22,   R23,   R24, KC_NO }, \
        {   R30, KC_NO, KC_NO, KC_NO,   R34,   R35 }, \
    }
};
