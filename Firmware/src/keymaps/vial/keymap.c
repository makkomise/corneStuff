/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    QK_GESC,  KC_Q,     KC_W,       KC_E,       KC_R,       KC_T,                     KC_Y,           KC_U,     KC_I,     KC_O,    KC_P,    KC_BACKSPACE,
    KC_LSFT,  KC_A,     KC_S,       KC_D,       KC_F,       KC_G,                     KC_H,           KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,     KC_X,       MT(KC_COPY, KC_C),  MT(KC_PSTE,KC_V), KC_B,       KC_N,           KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_NUHS,
                                    MT(KC_LGUI, KC_LALT), MO(1),  KC_SPC,           KC_ENT,   MO(2),    KC_RALT
  ),

  [1] = LAYOUT_split_3x6_3(
    KC_F1,    KC_F2,    KC_F3,      KC_F4,      KC_F5,      KC_F6,                    KC_F7,          KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,
    KC_TRNS,  KC_1,     KC_2,       KC_3,       KC_4,       KC_5,                     KC_6,           KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,
    KC_TILD,  KC_EXLM,  KC_DQUO,    KC_HASH,    KC_TRNS,    KC_PERC,                  KC_AMPR,        KC_SLSH,  KC_LPRN,  KC_RPRN,  KC_PEQL, KC_EQL,
                                              KC_TRNS,    KC_NO,  KC_TRNS,          KC_TRNS,  KC_NO,    KC_TRNS
  ),

  [2] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_PSLS,  RALT(KC_3), RALT(KC_5), RALT(KC_4), RALT(KC_6),                KC_PGUP,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_DEL,
    KC_TRNS, KC_LEFT,  KC_DOWN,    KC_UP,      KC_RIGHT,   KC_TRNS,                   KC_PGDN,        KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS, KC_QUES,
    KC_NUM,  KC_AT,    KC_TRNS,    KC_LABK,    KC_LCBR,    RALT(KC_LBRC),             RALT(KC_RBRC),  KC_RCBR,  KC_RABK,  KC_TRNS,  KC_PIPE, RALT(KC_BSLS),
                                              KC_TRNS,    KC_NO,  KC_TRNS,          KC_TRNS,  KC_NO,    KC_TRNS
  ),

  [3] = LAYOUT_split_3x6_3(
    KC_TRNS, KC_1,     KC_2,       KC_3,       KC_4,       KC_5,                      KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_TRNS, KC_Q,     KC_W,       KC_E,       KC_R,       KC_T,                      KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
    KC_TRNS, KC_A,     KC_S,       KC_D,       KC_F,       KC_G,                      KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
                                              KC_TRNS,  KC_TRNS,  KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS
  )
};
//per-layer RGB
#ifdef RGB_MATRIX_ENABLE

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
bool rgb_matrix_indicators_user(void) {
    uint8_t highest_layer = get_highest_layer(layer_state);
    if (highest_layer == 3) { //Layer3
        uint8_t left_side_led_count = 27; 
        for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
            if (i < left_side_led_count) {
                rgb_matrix_set_color(i, 196,147,255); 
            } else {
                rgb_matrix_set_color(i, 0, 0, 0); 
            }
        }
        return false;
    }
    switch (highest_layer) {
        case 0:
            rgb_matrix_set_color_all(255,0,180);  //Layer0
            break;
        case 1:
            rgb_matrix_set_color_all(142,165,255);  //Layer1
            break;
        case 2:
            rgb_matrix_set_color_all(0,255,188);  //Layer2
            break;
        default:
            rgb_matrix_set_color_all(255,255,255);  //Fallback
            break;
    }
    return false; 
}
#endif