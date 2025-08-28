/*
Copyright 2022 @Yowkees
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

#include "quantum.h"


enum custom_keycodes {
    PASS1 = SAFE_RANGE,
    PASS2,
    PASS3,
    PASS4,
    MAIL1,
    MAIL2,
    ADDRESS,
    NOTEPAD,
    OPEN,
    SCREEN,
    BACK
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {

//# user0
case PASS1:
 SEND_STRING("pjpj8787\n");
return false;         
            
//# user1
case PASS2:
SEND_STRING("Kobataku83\n");
return false;
            
//# user2
case PASS3:
SEND_STRING("jred2025\n");
return false;
            
//# user3
case PASS4:
SEND_STRING("jred2019\n");
return false;
            
//# user4
case MAIL1:
SEND_STRING("tak-kobayashi");
SEND_STRING("@");
SEND_STRING("jred.co.jp");
return false;
            
//# user5
case MAIL2:
SEND_STRING("taku83");
SEND_STRING("@");
SEND_STRING("icloud.com");
return false;
            
//# user6
case ADDRESS:
SEND_STRING("THE LINKPILLAR1 SOUTH 12F");
return false;
            
//# user7
case NOTEPAD:
tap_code16(LGUI(KC_R));
wait_ms(100);
SEND_STRING("notepad\n");
return false;
            
//# user8
case OPEN:
tap_code16(LGUI(KC_R));
wait_ms(100);
tap_code16(C(KC_V));
SEND_STRING("\n");
return false;
            
//# user9
case SCREEN:
tap_code16(LGUI(S(KC_S)));
return false;
            
//# user10
case BACK:
tap_code16(LALT(KC_LEFT));
return false;
        }
    }
    return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                     KC_Y     , KC_U           ,   KC_I       , LT(3,KC_O) , LT(1,KC_P) ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                     KC_H     , KC_J           ,   KC_K       , KC_L       , LT(3)      ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                     KC_N     , KC_M           ,   KC_BTN1    , KC_BTN3    , KC_BTN2    ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),    KC_BSPC,LT(2,KC_ENT) , LSFT_T(KC_LNG2),   KC_RALT    , KC_RGUI    , KC_RSFT
  ),

  [1] = LAYOUT_universal(
    KC_ESC     ,  KC_EXLM  , S(KC_2)   , S(KC_3)  , S(KC_4)   ,                                      KC_SLSH     , KC_7      ,  KC_8     , KC_9       , KC_MINS    ,
    KC_TAB     ,  S(KC_5)  , S(KC_6)   , S(KC_7)  , S(KC_AT)  ,                                      KC_ASTR     , KC_4      ,  KC_5     , KC_6       , KC_PPLS    ,
    KC_JYEN    ,  KC_LBRC  , KC_RBRC   , S(KC_8)  , S(KC_9)   ,                                      KC_0        , KC_1      ,  KC_2     , KC_3       , KC_EQL     ,
    _______    ,  _______  ,  _______  , _______  , _______   , _______  ,              S(KC_BSPC) , _______     , _______   ,  _______  , _______    , _______
  ),

  [2] = LAYOUT_universal(
    KC_F1    , KC_F2     , KC_F3    , KC_F4       , KC_F5     ,                                      KC_SCLN    , KC_MINS  ,  KC_UP    , S(KC_GRAVE) , S(KC_SLSH) ,
    KC_F6    , KC_F7     , KC_F8    , KC_F9       , KC_F10    ,                                      S(KC_SCLN) , KC_LEFT  ,  KC_DOWN  , KC_RGHT     , KC_AT      ,
    KC_F11   , KC_F12    , S(KC_6)  , S(KC_COMMA) , S(KC_DOT) ,                                      KC_COMM    , KC_DOT   ,  CS(TAB)  , C(W)        , C(TAB)     ,
    _______  , _______   , _______  , _______     , _______   , _______  ,             S(KC_BSPC) ,  _______    , _______  ,  _______  , _______     , S(KC_MINS) 
  ),

  [3] = LAYOUT_universal(
    _______  , _______   , _______  , _______    , _______    ,                                      SCREEN     , MAIL1    ,  MAIL1    , OPEN      ,  PASS1     , 
    _______  , _______   , _______  , _______    , _______    ,                                      PASS4      , PASS3    ,  PASS2    , ADDRESS   ,  LT(3)     ,
    _______  , _______   , _______  , _______　  , _______    ,                                      NOTEPAD    , _______  ,  KC_BTN1  , KC_BTN3   ,  KC_BTN2   , 
    _______  , _______   , _______  , _______    , _______    , _______  ,             S(KC_BSPC),   _______    , _______  ,  _______  , _______   ,  BACK
  ),

  [4] = LAYOUT_universal(
    _______  ,  _______  ,  _______ , _______   , _______    ,                                        _______  , _______   ,  _______  , _______  , _______  ,
    _______  ,  _______  ,  _______ , _______   , _______    ,                                        _______  , _______   ,  _______  , _______  , _______  ,
    _______  ,  _______  ,  _______ , _______   , _______    ,                                        _______  , _______   ,  _______  , _______  , _______  ,
    _______  ,  _______  ,  _______ , _______   , _______    , _______   ,                 _______  , _______  , _______   ,  _______  , _______  , _______
  ),
};

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef COMBO_ENABLE
enum combos{
QW_ESCAPE,
AS_TAB,
ZX_LSFT,
OP_DELETE,
LF24_ENTER,
BTN3BTN2_RSFT,
BACKSPACEENTER_DELETE,

};

const uint16_t PROGMEM my_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM my_as[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM my_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM my_op[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM my_lF24[] = {KC_L, KC_F24, COMBO_END};
const uint16_t PROGMEM my_BTN3BTN2[] = {KC_BTN3, KC_BTN2, COMBO_END};
const uint16_t PROGMEM my_BACKSPACEENTER[] = {KC_BACKSPACE, KC_ENTER, COMBO_END};

combo_t key_combos[] = {
[QW_ESCAPE] = COMBO(my_qw, KC_ESCAPE),
[AS_TAB] = COMBO(my_as, KC_TAB),
[ZX_LSFT] = COMBO(my_zx, KC_LSFT),
[OP_DELETE] = COMBO(my_op, KC_DELETE),
[LF24_ENTER] = COMBO(my_lF24, KC_ENTER),
[BTN3BTN2_RSFT] = COMBO(my_BTN3BTN2, KC_RSFT),
[BACKSPACEENTER_DELETE] = COMBO(my_BACKSPACEENTER, KC_DELETE),
};
#endif

