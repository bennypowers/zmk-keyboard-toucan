#include <zephyr/kernel.h>
#include <stdio.h>
#include "character.h"
#include "../assets/sprites.h"
#include "../assets/custom_fonts.h"
#include <zmk/keymap.h>

#define SPRITE_X ((SCREEN_WIDTH - SPRITE_W) / 2)
#define SPRITE_Y 30
#define LAYER_LABEL_Y (SPRITE_Y + SPRITE_H + 2)

static uint8_t walk_frame;

bool character_is_walking(const struct status_state *state) {
    return state->wpm > 0;
}

void draw_character(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    uint8_t idx = state->layer_index;
    if (idx >= NUM_LAYER_SPRITES) {
        idx = 0;
    }

    const lv_img_dsc_t *sprite;

    /* Pick sprite set: robot when charging, normal otherwise */
    const lv_img_dsc_t *(*sprites)[2] = state->charging
        ? charge_sprites : layer_sprites;

    if (state->wpm > 0) {
        sprite = sprites[idx][walk_frame % 2];
        walk_frame++;
    } else {
        walk_frame = 0;
        sprite = sprites[idx][0];
    }

    /* Non-base layers while charging: show layer name below sprite */
    if (state->charging && idx > 0) {
        const char *name = zmk_keymap_layer_name(
            zmk_keymap_layer_index_to_id(idx));
        if (name && name[0] != '\0') {
            lv_draw_label_dsc_t label_dsc;
            init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8,
                           LV_TEXT_ALIGN_CENTER);
            lv_canvas_draw_text(canvas, 0, LAYER_LABEL_Y, SCREEN_WIDTH,
                                &label_dsc, name);
        }
    }

    lv_canvas_draw_img(canvas, SPRITE_X, SPRITE_Y, sprite, &img_dsc);
}
