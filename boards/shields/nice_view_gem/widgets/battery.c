#include <zephyr/kernel.h>
#include "battery.h"
#include "../assets/custom_fonts.h"
#include "../assets/eb_digits.h"

#define L_X 2
#define R_X 76
#define BATTERY_Y 140

/* Border width matches the 1px right border in each digit tile, scaled */
#define BORDER_W 2  /* DIGIT_SCALE */

static void draw_hp_counter(lv_obj_t *canvas, int x, int y, uint8_t value) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, x, y + 8, 16, &label_dsc, "HP");

    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    int dx = x + 16;

    /* Determine how many digits to show */
    uint8_t hundreds = value / 100;
    uint8_t tens = (value % 100) / 10;
    uint8_t ones = value % 10;
    int num_digits = (hundreds > 0) ? 3 : (tens > 0) ? 2 : 1;
    int box_w = num_digits * EB_DIGIT_W + BORDER_W;

    /* Top border */
    lv_draw_rect_dsc_t border_dsc;
    init_rect_dsc(&border_dsc, LVGL_FOREGROUND);
    lv_canvas_draw_rect(canvas, dx, y, box_w, BORDER_W, &border_dsc);

    /* Left border */
    lv_canvas_draw_rect(canvas, dx, y, BORDER_W, EB_DIGIT_H + BORDER_W, &border_dsc);

    /* Bottom border */
    lv_canvas_draw_rect(canvas, dx, y + EB_DIGIT_H, box_w, BORDER_W, &border_dsc);

    /* Digits (each tile has its own right border built in) */
    dx += BORDER_W;
    if (hundreds > 0) {
        lv_canvas_draw_img(canvas, dx, y, eb_digits[hundreds], &img_dsc);
        dx += EB_DIGIT_W;
    }
    if (hundreds > 0 || tens > 0) {
        lv_canvas_draw_img(canvas, dx, y, eb_digits[tens], &img_dsc);
        dx += EB_DIGIT_W;
    }
    lv_canvas_draw_img(canvas, dx, y, eb_digits[ones], &img_dsc);
}

void draw_battery_status(lv_obj_t *canvas, const struct status_state *state) {
    draw_hp_counter(canvas, L_X, BATTERY_Y, state->battery);
    draw_hp_counter(canvas, R_X, BATTERY_Y, state->battery_p);
}
