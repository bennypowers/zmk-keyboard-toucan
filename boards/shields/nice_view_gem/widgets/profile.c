#include <zephyr/kernel.h>
#include "profile.h"
#include "../assets/presents.h"

#define PROFILE_X 54
#define PROFILE_Y 4
#define PROFILE_SPACING 18

void draw_profile_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    for (int i = 0; i < 5; i++) {
        int x = PROFILE_X + i * PROFILE_SPACING;
        const lv_img_dsc_t *icon = (i == state->active_profile_index)
            ? &present_open : &present_closed;
        lv_canvas_draw_img(canvas, x, PROFILE_Y, icon, &img_dsc);
    }
}
