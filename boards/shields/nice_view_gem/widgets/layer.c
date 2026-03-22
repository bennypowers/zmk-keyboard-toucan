#include <zephyr/kernel.h>
#include <stdio.h>
#include <string.h>

#include "layer.h"
#include "../assets/custom_fonts.h"
#include <zmk/keymap.h>

#define LAYER_NAME_Y 156

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);

    char fallback[16];
    const char *name =
        zmk_keymap_layer_name(zmk_keymap_layer_index_to_id(state->layer_index));

    if (name == NULL || name[0] == '\0') {
        snprintf(fallback, sizeof(fallback), "L#%" PRIu8, state->layer_index);
        name = fallback;
    }

    lv_canvas_draw_text(canvas, 2, LAYER_NAME_Y, 40, &label_dsc, name);
}
