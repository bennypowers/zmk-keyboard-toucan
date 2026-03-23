#include <zephyr/kernel.h>
#include "character.h"
#include "../assets/sprites.h"

#define SPRITE_X ((SCREEN_WIDTH - SPRITE_W) / 2)
#define SPRITE_Y 30

static uint8_t walk_frame;

bool character_is_walking(const struct status_state *state) {
    return state->charging || state->wpm > 0;
}

void draw_character(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    uint8_t idx = state->layer_index;
    if (idx >= NUM_LAYER_SPRITES) {
        idx = 0;
    }

    const lv_img_dsc_t *sprite;
    if (character_is_walking(state)) {
        sprite = layer_sprites[idx][walk_frame % 2];
        walk_frame++;
    } else {
        walk_frame = 0;
        sprite = layer_sprites[idx][0];
    }

    lv_canvas_draw_img(canvas, SPRITE_X, SPRITE_Y, sprite, &img_dsc);
}
