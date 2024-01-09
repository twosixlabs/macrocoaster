
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "oled_driver.h"
#include QMK_KEYBOARD_H

#define _MEDIA 0
#define _GIT 1
#define _TERM 2
#define _SLACK 3
#define _KICAD 4
#define _NUMPD 5
#define _TEST 6

enum custom_keycodes {
    M_HELLO = SAFE_RANGE,
    M_PARTY,
    M_OKAY,
    M_DITO,
    M_PUGD,

    DIS_VERT,
    DIS_HORZ,
    ALGN_VERT,
    ALGN_HORZ,
    FLIP_BRD,

    GIT_PULL,
    GIT_PUSH,
    GIT_COMM,
    GIT_SEND,
    GIT_ADD,

    VIM_WQF,
    CTR_C,
    CTR_U,
    NEW_WIN,
    NEW_TAB,
    OPN_TERM,

    FLSH_ATML,
    FLSH_KB24
};

// CUSTOM MACROS DEFINED HERE
// Make sure to add to custom_keycodes enum, and use in keymap
// https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_HELLO:
            if (record->event.pressed) {
                SEND_STRING("# Hello world!\n");
            } // add else for on release
            break; // Don't forget this line!
        
        case M_PARTY:
            if (record->event.pressed) {
                SEND_STRING(":partyparrot:"SS_DELAY(100)"\n");
            }
            break;
        case M_OKAY:
            if (record->event.pressed) {
                SEND_STRING(":ok:"SS_DELAY(100)"\n");
            }
            break;
        case M_DITO:
            if (record->event.pressed) {
                SEND_STRING(":ditto_party:"SS_DELAY(100)"\n");
            }
            break;
        case M_PUGD:
            if (record->event.pressed) {
                SEND_STRING(":pug_dance_fast:"SS_DELAY(100)"\n");
            }
            break;

        case DIS_VERT:
            if (record->event.pressed) {
                SEND_STRING(";");
            }
            break;
        case DIS_HORZ:
            if (record->event.pressed) {
                SEND_STRING(".");
            }
            break;   
        case ALGN_VERT:
            if (record->event.pressed) {
                SEND_STRING("\"");
            }
            break;  
        case ALGN_HORZ:
            if (record->event.pressed) {
                SEND_STRING("?");
            }
            break;  
        case FLIP_BRD:
            if (record->event.pressed) {
                SEND_STRING("]");
            }
            break; 

        case GIT_PUSH:
            if (record->event.pressed) {
                SEND_STRING("git push\n");
            }
            break;
        case GIT_PULL:
            if (record->event.pressed) {
                SEND_STRING("git pull\n");
            }
            break;
        case GIT_COMM:
            if (record->event.pressed) {
                SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
            }
            break;
        case GIT_ADD:
            if (record->event.pressed) {
                SEND_STRING("git add -A\n");
            }
            break;

        case VIM_WQF:
            if (record->event.pressed) {

                SEND_STRING("\e:wq\n");
            }
            break;
        case CTR_C:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
            break;
        case CTR_U:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("u"));
            }
            break;
        case NEW_WIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("t"));
            }
            break;
        case NEW_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("N"));
            }
            break;
        case OPN_TERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI() "terminal\n");
            }
            break;

        case FLSH_ATML:
            if (record->event.pressed) {
                // #if defined(QMK_MCU)
                //     #if (QMK_MCU == atmega32u4)
                //         SEND_STRING("qmk compile -kb macrocoaster -km default && qmk flash -bl dfu -km default -kb macrocoaster\n");
                //     #elif (QMK_MCU == asd)
                //         SEND_STRING("qmk compile -kb macrocoaster -km default && qmk flash -bl dfu -km default -kb macrocoaster -e CONVERT_TO=kb2040\n");
                //     #else
                //         SEND_STRING("# [FAIL] Unknown MCU detected\n");
                //     #endif
                // #endif
                SEND_STRING("qmk compile -kb macrocoaster -km default && qmk flash -bl dfu -km default -kb macrocoaster\n");
            }
            break;
        case FLSH_KB24:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb macrocoaster -km default && qmk flash -km default -kb macrocoaster -e CONVERT_TO=kb2040\n");
            }
            break;
    
    }
    return true;
};


// Define keymaps here (either QMK keycodes or from process_record_user())
// See https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
/* 
    [_NAME] = LAYOUT(
        KC_A,   KC_B,   KC_NO, //the KC_NO switch doesn't exist (knob)
        KC_C,   KC_D,   KC_E,
        KC_F,   KC_G,   KC_H,
        KC_I,   KC_J,   KC_K
    )
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT(
        KC_BRIGHTNESS_DOWN,  KC_BRIGHTNESS_UP,    KC_NO,
        KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_AUDIO_MUTE,
        KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PLAY_PAUSE,
        KC_WWW_REFRESH,      KC_SYSTEM_SLEEP,     KC_CALCULATOR
    ),
    [_GIT] = LAYOUT(
        GIT_PULL, GIT_PUSH, KC_NO,
        GIT_COMM, GIT_ADD,  KC_NO,
        KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO
    ),
    [_TERM] = LAYOUT(
        CTR_U,    CTR_C,     KC_NO,
        VIM_WQF,   KC_NO,     KC_NO,
        FLSH_ATML, FLSH_KB24, KC_NO,
        NEW_WIN,   NEW_TAB,   OPN_TERM
    ),
    [_SLACK] = LAYOUT(
        M_PARTY, M_OKAY, KC_NO,
        KC_NO,   M_PUGD, M_DITO,
        KC_NO,   KC_NO,  KC_NO,
        KC_SPC,  KC_ENT, KC_BSPC
    ),
    [_KICAD] = LAYOUT(
        DIS_VERT, ALGN_VERT, KC_NO,
        DIS_HORZ, ALGN_HORZ, FLIP_BRD,
        KC_F8,    KC_NO,     KC_NO,
        KC_NO,    KC_NO,     KC_NO
    ),
    [_NUMPD] = LAYOUT(
        KC_1, KC_2, KC_NO,
        KC_3, KC_4, KC_5,
        KC_6, KC_7, KC_8,
        KC_9, KC_0, KC_EQL
    ),
    [_TEST] = LAYOUT(
        KC_A, KC_B, KC_NO,
        KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H,
        KC_I, KC_J, KC_K
    )
};


// Define rotary knob functions here, must match existing layers
// See: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md#encoder-map-idencoder-map
/*
    [_NAME] = {ENCODER_CCW_CW(TO(_PREV_LAYER), TO(_NEXT_LAYER)), ENCODER_CCW_CW(_CCW_KEYCODE, _CW_KEYCODE)},
*/
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_MEDIA] = {ENCODER_CCW_CW(TO(1), TO(6)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GIT] =   {ENCODER_CCW_CW(TO(2), TO(0)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_TERM] =  {ENCODER_CCW_CW(TO(3), TO(1)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SLACK] = {ENCODER_CCW_CW(TO(4), TO(2)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_KICAD] = {ENCODER_CCW_CW(TO(5), TO(3)), ENCODER_CCW_CW(KC_N, LSFT(KC_N))},
    [_NUMPD] = {ENCODER_CCW_CW(TO(6), TO(4)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_TEST] =  {ENCODER_CCW_CW(TO(0), TO(5)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};


// Rotary encoder push-buttons (Specify keycode)
bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0: // right knob
            if (active) { // on press
			    tap_code(KC_MUTE);
            } // add an "else" for on release
            break;
        case 1: // left knob (by OLED)
            if (active) { 
			    tap_code(KC_MUTE);
            }
            break;
    }

    return true;
}


#ifdef OLED_ENABLE

// Since OLED is reverse-mounted
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }


// Define layer display names here (up to 21 characters (22 byte string))
/*
    case _LAYER_NAME:
        oled_write_P(PSTR("Layer Name           "), false);
        break; // Make sure not to forget this line!
*/
bool oled_task_user(void) {
    oled_write_P(PSTR("  MACROCOASTER v1.4\n"), false);
    led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("     [CAPS LOCK]\n") : PSTR("\n"), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    oled_write_P(PSTR("Current Layer:\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _MEDIA:
            oled_write_P(PSTR("Multimedia           "), false);
            break;
        case _GIT:
            oled_write_P(PSTR("Git                  "), false);
            break;
        case _TERM:
            oled_write_P(PSTR("Terminal             "), false);
            break;
        case _SLACK:
            oled_write_P(PSTR("Slack                "), false);
            break;
        case _KICAD:
            oled_write_P(PSTR("KiCAD                "), false);
            break;
        case _NUMPD:
            oled_write_P(PSTR("Numpad               "), false);
            break;
        case _TEST:
            oled_write_P(PSTR("TEST12345678912345678"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unnamed Layer        "), false);
    }
    
    return false;
}

#endif // OLED_ENABLE