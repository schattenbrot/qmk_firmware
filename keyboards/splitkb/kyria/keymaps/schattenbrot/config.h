/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
// #    define RGBLIGHT_HUE_STEP  8
// #    define RGBLIGHT_SAT_STEP  8
// #    define RGBLIGHT_VAL_STEP  8
// #    define RGBLIGHT_LIMIT_VAL 150
#    define RGBLIGHT_TIMEOUT_MINS 1
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_SPLIT
#endif

#ifdef COMBO_ENABLE
#    define COMBO_SHOULD_TRIGGER
#endif

#define ONESHOT_TIMEOUT 1000

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT

// Turns on one word caps when pressing both shifts at the same time
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
