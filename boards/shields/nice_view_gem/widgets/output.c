#include <zephyr/kernel.h>
#include "output.h"
#include "../assets/custom_fonts.h"

#define STATUS_X 6
#define STATUS_Y 6

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)

static void draw_status_text(lv_obj_t *canvas, const char *text) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &saturn_font_16, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, STATUS_X, STATUS_Y, 80, &label_dsc, text);
}

void draw_output_status(lv_obj_t *canvas, const struct status_state *state) {
    switch (state->selected_endpoint.transport) {
    case ZMK_TRANSPORT_USB:
        draw_status_text(canvas, "USB");
        break;
    case ZMK_TRANSPORT_BLE:
        if (state->active_profile_bonded) {
            if (state->active_profile_connected) {
                draw_status_text(canvas, "BLE");
            } else {
                draw_status_text(canvas, "DISC");
            }
        } else {
            draw_status_text(canvas, "OPEN");
        }
        break;
    default:
        draw_status_text(canvas, "NULL");
        break;
    }
}

#else

void draw_output_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &saturn_font_16, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, STATUS_X, STATUS_Y, 80, &label_dsc,
                        state->connected ? "BLE" : "DISC");
}

#endif
