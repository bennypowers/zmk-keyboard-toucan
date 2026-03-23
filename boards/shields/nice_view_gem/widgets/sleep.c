#include <zephyr/kernel.h>
#include "sleep.h"
#include "../assets/custom_fonts.h"
#include "../assets/sprites.h"

static bool show_sleep_screen = false;

bool is_sleep_screen_active(void) {
    return show_sleep_screen;
}

void set_sleep_screen_active(bool active) {
    show_sleep_screen = active;
}

void draw_sleep_screen(lv_obj_t *canvas) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    int x = (SCREEN_WIDTH - SPRITE_W) / 2;
    lv_canvas_draw_img(canvas, x, 22, &ness_sleep, &img_dsc);

    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &saturn_font_16, LV_TEXT_ALIGN_CENTER);
    lv_canvas_draw_text(canvas, 0, 130, SCREEN_WIDTH, &label_dsc, "zzz...");
}
