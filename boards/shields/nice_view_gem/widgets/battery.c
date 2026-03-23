#include <zephyr/kernel.h>
#include "battery.h"
#include "../assets/custom_fonts.h"
#include "../assets/eb_digits.h"

#define L_X 2
#define R_X 76
#define BATTERY_Y 140
#define BORDER_W 2

struct roll_state {
    uint8_t displayed;
    uint8_t target;
    uint8_t frame;  /* 0 = clean, 1..EB_ROLL_FRAMES-1 = transition */
};

static struct roll_state roll_l;
static struct roll_state roll_r;

static void draw_hp_counter(lv_obj_t *canvas, int x, int y,
                            struct roll_state *rs) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, x, y + 8, 16, &label_dsc, "HP");

    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    int dx = x + 16;
    uint8_t val = rs->displayed;
    uint8_t hundreds = val / 100;
    uint8_t tens = (val % 100) / 10;
    uint8_t ones = val % 10;

    /* Use target to determine digit count so box doesn't resize during roll */
    uint8_t t_hundreds = rs->target / 100;
    int num_digits = (t_hundreds > 0 || hundreds > 0) ? 3 : 2;
    int box_w = num_digits * EB_DIGIT_W + BORDER_W;

    /* Box borders */
    lv_draw_rect_dsc_t border_dsc;
    init_rect_dsc(&border_dsc, LVGL_FOREGROUND);
    lv_canvas_draw_rect(canvas, dx, y, box_w, BORDER_W, &border_dsc);
    lv_canvas_draw_rect(canvas, dx, y, BORDER_W, EB_DIGIT_H + BORDER_W, &border_dsc);
    lv_canvas_draw_rect(canvas, dx, y + EB_DIGIT_H, box_w, BORDER_W, &border_dsc);

    dx += BORDER_W;

    /* Draw digits: only the ones place rolls, others show clean */
    if (num_digits >= 3) {
        lv_canvas_draw_img(canvas, dx, y, eb_digits[hundreds], &img_dsc);
        dx += EB_DIGIT_W;
    }
    if (num_digits >= 2) {
        lv_canvas_draw_img(canvas, dx, y, eb_digits[tens], &img_dsc);
        dx += EB_DIGIT_W;
    }

    /* Ones digit rolls through transition frames */
    if (rs->frame > 0 && rs->displayed != rs->target) {
        /* Rolling: show transition tile for current ones digit */
        uint8_t roll_digit = (rs->displayed < rs->target) ? ones :
                             (ones == 0 ? 9 : ones - 1);
        lv_canvas_draw_img(canvas, dx, y, eb_roll[roll_digit][rs->frame], &img_dsc);
    } else {
        lv_canvas_draw_img(canvas, dx, y, eb_digits[ones], &img_dsc);
    }
}

bool battery_rolling_active(void) {
    return roll_l.displayed != roll_l.target || roll_l.frame != 0 ||
           roll_r.displayed != roll_r.target || roll_r.frame != 0;
}

void battery_roll_tick(uint8_t target_l, uint8_t target_r) {
    roll_l.target = target_l;
    roll_r.target = target_r;

    struct roll_state *rollers[] = {&roll_l, &roll_r};
    for (int i = 0; i < 2; i++) {
        struct roll_state *rs = rollers[i];
        if (rs->displayed == rs->target && rs->frame == 0) {
            continue;
        }

        rs->frame++;
        if (rs->frame >= EB_ROLL_FRAMES) {
            rs->frame = 0;
            if (rs->displayed < rs->target) {
                rs->displayed++;
            } else if (rs->displayed > rs->target) {
                rs->displayed--;
            }
        }
    }
}

void draw_battery_status(lv_obj_t *canvas, const struct status_state *state) {
    draw_hp_counter(canvas, L_X, BATTERY_Y, &roll_l);
    draw_hp_counter(canvas, R_X, BATTERY_Y, &roll_r);
}
