// Copyright 2023 placeholder (@placeholder)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define ENCODERS_PAD_A { B4, D7 }
#define ENCODERS_PAD_B { E6, C6 }
#define ENCODER_RESOLUTION 4
#define DIP_SWITCH_PINS { D4, B5 }

#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 1

#define OLED_TIMEOUT 60000
// #define OLED_SCROLL_TIMEOUT 5000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 10
// #define OLED_DISPLAY_128X64