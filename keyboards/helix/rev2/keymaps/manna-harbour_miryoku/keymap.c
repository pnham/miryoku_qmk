// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_EXTRA 2
#define L_TAP 4
#define L_BUTTON 8
#define L_NAV 16
#define L_MOUSE 32
#define L_MEDIA 64
#define L_NUM 128
#define L_SYM 256
#define L_FUN 512


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_EXTRA:
            oled_write_ln_P(PSTR("Extra"), false);
            break;
        case L_TAP:
            oled_write_ln_P(PSTR("Tap"), false);
            break;
        case L_BUTTON:
            oled_write_ln_P(PSTR("Button"), false);
            break;
        case L_NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case L_MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case L_MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case L_SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case L_FUN:
            oled_write_ln_P(PSTR("Fun"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }
}
