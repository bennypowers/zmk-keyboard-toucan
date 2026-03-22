#pragma once

#include <lvgl.h>

LV_IMG_DECLARE(ness_stand);
LV_IMG_DECLARE(ness_walk);
LV_IMG_DECLARE(paula_stand);
LV_IMG_DECLARE(paula_walk);
LV_IMG_DECLARE(jeff_stand);
LV_IMG_DECLARE(jeff_walk);
LV_IMG_DECLARE(poo_stand);
LV_IMG_DECLARE(poo_walk);

#define SPRITE_SCALE 4
#define SPRITE_W 64
#define SPRITE_H 96

#define NUM_LAYER_SPRITES 4
extern const lv_img_dsc_t *layer_sprites[NUM_LAYER_SPRITES][2];
