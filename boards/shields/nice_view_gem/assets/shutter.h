#pragma once

#include <lvgl.h>

LV_IMG_DECLARE(shutter_frame_0);
LV_IMG_DECLARE(shutter_frame_1);
LV_IMG_DECLARE(shutter_frame_2);
LV_IMG_DECLARE(shutter_frame_3);
LV_IMG_DECLARE(shutter_frame_4);
LV_IMG_DECLARE(shutter_frame_5);

#define SHUTTER_FRAMES 6
extern const lv_img_dsc_t *shutter_frames[6];
