#!/usr/bin/env python3
"""Convert EarthBound party sprite GIFs to LVGL 1-bit indexed C arrays.

Source GIFs go in src/ alongside this script. Output is sprites.c and sprites.h
in the same directory (assets/).

Each character has one source GIF. The walk animation alternates between
the original and its horizontal flip.

Uses Floyd-Steinberg dithering at display resolution for tonal detail.

Usage: python3 convert_sprites.py
"""

from PIL import Image, ImageOps
import os

SCALE = 4

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
SRC_DIR = os.path.join(SCRIPT_DIR, "src")
OUT_DIR = SCRIPT_DIR

# layer index -> character name (matches keymap layer order)
CHARACTERS = ["ness", "paula", "jeff", "poo"]

# Characters with a separate walk frame (hat asymmetry, etc.)
# Others auto-generate walk by flipping the stand frame.
WALK_OVERRIDES = {
    "ness": "ness-walk.gif",
}


def gif_to_mono(path, scale, flip=False):
    img = Image.open(path).convert("RGBA")
    if flip:
        img = ImageOps.mirror(img)
    _, _, _, a = img.split()

    scaled = img.resize((img.width * scale, img.height * scale), Image.NEAREST)
    scaled_a = a.resize((a.width * scale, a.height * scale), Image.NEAREST)

    gray = scaled.convert("L")
    mono_pil = gray.convert("1")  # Floyd-Steinberg dithering

    w, h = scaled.size
    mono = []
    for y in range(h):
        row = []
        for x in range(w):
            if scaled_a.getpixel((x, y)) < 128:
                row.append(0)
            else:
                row.append(0 if mono_pil.getpixel((x, y)) else 1)
        mono.append(row)
    return mono, w, h


def mono_to_lvgl_c(name, mono, w, h):
    row_bytes = (w + 7) // 8
    lines = []
    lines.append(f"/* {name}: {w}x{h} */")
    lines.append(
        f"const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST uint8_t {name}_map[] = {{"
    )
    lines.append("    0x00, 0x00, 0x00, 0x00, /*Color of index 0 (transparent)*/")
    lines.append("    0xff, 0xff, 0xff, 0xff, /*Color of index 1*/")
    for y in range(h):
        row_data = []
        for byte_idx in range(row_bytes):
            byte_val = 0
            for bit in range(8):
                x = byte_idx * 8 + bit
                if x < w and mono[y][x]:
                    byte_val |= 0x80 >> bit
            row_data.append(byte_val)
        hex_str = ", ".join(f"0x{b:02x}" for b in row_data)
        lines.append(f"    {hex_str}, ")
    lines.append("};")
    lines.append("")
    lines.append(f"const lv_img_dsc_t {name} = {{")
    lines.append("    .header.cf = LV_IMG_CF_INDEXED_1BIT,")
    lines.append("    .header.always_zero = 0,")
    lines.append("    .header.reserved = 0,")
    lines.append(f"    .header.w = {w},")
    lines.append(f"    .header.h = {h},")
    data_size = 8 + row_bytes * h
    lines.append(f"    .data_size = {data_size},")
    lines.append(f"    .data = {name}_map,")
    lines.append("};")
    return "\n".join(lines)


def save_preview(name, mono, w, h):
    preview = Image.new("L", (w * 2, h * 2), 255)
    for py in range(h):
        for px in range(w):
            if mono[py][px]:
                for dy in range(2):
                    for dx in range(2):
                        preview.putpixel((px * 2 + dx, py * 2 + dy), 0)
    preview.save(os.path.join(SRC_DIR, f"{name}_preview.png"))


def main():
    c_parts = ['#include <lvgl.h>', '#include "sprites.h"', ""]
    sprite_w = sprite_h = 0
    all_names = []

    for char in CHARACTERS:
        stand_path = os.path.join(SRC_DIR, f"{char}.gif")

        # Stand frame
        name = f"{char}_stand"
        mono, w, h = gif_to_mono(stand_path, SCALE)
        c_parts.append(mono_to_lvgl_c(name, mono, w, h))
        c_parts.append("")
        sprite_w, sprite_h = w, h
        save_preview(name, mono, w, h)
        all_names.append(name)
        print(f"  {name} ({char}.gif): {w}x{h}")

        # Walk frame: use override file or flip the stand frame
        name = f"{char}_walk"
        if char in WALK_OVERRIDES:
            walk_path = os.path.join(SRC_DIR, WALK_OVERRIDES[char])
            mono, w, h = gif_to_mono(walk_path, SCALE)
            label = WALK_OVERRIDES[char]
        else:
            mono, w, h = gif_to_mono(stand_path, SCALE, flip=True)
            label = f"{char}.gif (flipped)"
        c_parts.append(mono_to_lvgl_c(name, mono, w, h))
        c_parts.append("")
        save_preview(name, mono, w, h)
        all_names.append(name)
        print(f"  {name} ({label}): {w}x{h}")

    c_parts.append("/* Per-layer sprite pairs: [stand, walk] */")
    c_parts.append(
        "const lv_img_dsc_t *layer_sprites[NUM_LAYER_SPRITES][2] = {"
    )
    for char in CHARACTERS:
        c_parts.append(f"    {{ &{char}_stand, &{char}_walk }},")
    c_parts.append("};")
    c_parts.append("")

    with open(os.path.join(OUT_DIR, "sprites.c"), "w") as f:
        f.write("\n".join(c_parts) + "\n")

    declares = "\n".join(f"LV_IMG_DECLARE({n});" for n in all_names)
    with open(os.path.join(OUT_DIR, "sprites.h"), "w") as f:
        f.write(
            f"""#pragma once

#include <lvgl.h>

{declares}

#define SPRITE_SCALE {SCALE}
#define SPRITE_W {sprite_w}
#define SPRITE_H {sprite_h}

#define NUM_LAYER_SPRITES {len(CHARACTERS)}
extern const lv_img_dsc_t *layer_sprites[NUM_LAYER_SPRITES][2];
"""
        )

    print(f"\nGenerated sprites.c/h ({sprite_w}x{sprite_h})")


if __name__ == "__main__":
    main()
