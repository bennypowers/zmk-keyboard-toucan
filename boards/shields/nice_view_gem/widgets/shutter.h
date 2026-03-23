#pragma once

#include <lvgl.h>
#include "util.h"

bool is_shutter_active(void);
void draw_shutter_overlay(lv_obj_t *canvas);
void shutter_tick(void);
void shutter_init(void);
