#include <zephyr/kernel.h>

#include <zmk/event_manager.h>
#include <zmk/events/keycode_state_changed.h>
#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>

#include "shutter.h"
#include "../assets/shutter.h"

/*
 * Camera shutter iris animation, triggered by PrintScreen.
 *
 * Sequence: close (frames 0-5), hold black, open (frames 5-0).
 * Each frame is a full-screen 144x168 1-bit mask drawn over the
 * normal display content.
 */

#define PHASE_IDLE    0
#define PHASE_CLOSING 1
#define PHASE_HOLD    2
#define PHASE_OPENING 3

#define HOLD_TICKS 3  /* hold closed for 3 ticks (~200ms at 67ms/tick) */

static uint8_t phase = PHASE_IDLE;
static uint8_t frame_idx;
static uint8_t hold_counter;

bool is_shutter_active(void) {
    return phase != PHASE_IDLE;
}

void shutter_trigger(void) {
    if (phase != PHASE_IDLE) {
        return;  /* already animating */
    }
    phase = PHASE_CLOSING;
    frame_idx = 0;
    hold_counter = 0;
}

void shutter_tick(void) {
    if (phase == PHASE_IDLE) {
        return;
    }

    switch (phase) {
    case PHASE_CLOSING:
        frame_idx++;
        if (frame_idx >= SHUTTER_FRAMES) {
            phase = PHASE_HOLD;
            frame_idx = SHUTTER_FRAMES - 1;
            hold_counter = 0;
        }
        break;
    case PHASE_HOLD:
        hold_counter++;
        if (hold_counter >= HOLD_TICKS) {
            phase = PHASE_OPENING;
        }
        break;
    case PHASE_OPENING:
        if (frame_idx == 0) {
            phase = PHASE_IDLE;
        } else {
            frame_idx--;
        }
        break;
    }
}

void draw_shutter_overlay(lv_obj_t *canvas) {
    if (phase == PHASE_IDLE) {
        return;
    }

    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    lv_canvas_draw_img(canvas, 0, 0, shutter_frames[frame_idx], &img_dsc);
}

/* Listen for PrintScreen keycode */
static int shutter_keycode_handler(const zmk_event_t *eh) {
    const struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);
    if (ev == NULL) {
        return ZMK_EV_EVENT_BUBBLE;
    }

    if (ev->keycode == HID_USAGE_KEY_KEYBOARD_PRINTSCREEN &&
        ev->usage_page == HID_USAGE_KEY && ev->state) {
        shutter_trigger();
    }

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(nice_view_shutter, shutter_keycode_handler);
ZMK_SUBSCRIPTION(nice_view_shutter, zmk_keycode_state_changed);
