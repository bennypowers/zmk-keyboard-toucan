#pragma once

#include <lvgl.h>
#include "util.h"

bool character_is_walking(const struct status_state *state);
void draw_character(lv_obj_t *canvas, const struct status_state *state);
