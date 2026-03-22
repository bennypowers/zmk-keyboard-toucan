#include <zephyr/kernel.h>
#include "battery_peripheral.h"

/* Peripheral battery is drawn by draw_battery_status in battery.c
   using state->battery_p. This file only needs to exist for the
   status state struct and the draw stub. */

void draw_battery_peripheral_status(lv_obj_t *canvas, const struct status_state *state) {
    /* Drawing handled by draw_battery_status which reads state->battery_p */
}
