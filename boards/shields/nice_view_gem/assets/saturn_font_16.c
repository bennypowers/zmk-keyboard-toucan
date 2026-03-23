/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --font /tmp/senor-saturno/SenorSaturno-Aw9g.ttf --size 16 --bpp 1 --format lvgl -o /home/bennyp/Developer/zmk/config/boards/shields/nice_view_gem/assets/saturn_font_16.c --range 0x20-0x7E
 ******************************************************************************/

#include <lvgl.h>

#ifndef SATURN_FONT_16
#define SATURN_FONT_16 1
#endif

#if SATURN_FONT_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x21, 0x8, 0x42, 0x10, 0x84, 0x3, 0xa3, 0x17,
    0x0,

    /* U+0022 "\"" */
    0x22, 0x11, 0x15, 0x4a, 0xaf, 0xf8,

    /* U+0023 "#" */
    0x74, 0x62, 0xe0,

    /* U+0024 "$" */
    0x2, 0x6, 0xc, 0xc, 0xc, 0x4, 0x6, 0x89,
    0x89, 0x89, 0x4a, 0x3c, 0x10, 0x10,

    /* U+0025 "%" */
    0xfc, 0x50, 0x8a, 0x11, 0x42, 0x28, 0x49, 0xfa,
    0x0, 0x80, 0x2f, 0x9, 0x22, 0x24, 0x87, 0x80,

    /* U+0026 "&" */
    0x10, 0x21, 0xf4, 0x18, 0x30, 0x18, 0x40, 0x83,
    0x5, 0xf0, 0x81, 0x0,

    /* U+0027 "'" */
    0x21, 0x14, 0xaf, 0x80,

    /* U+0028 "(" */
    0x13, 0x54, 0x88, 0x88, 0x84, 0x53, 0x10,

    /* U+0029 ")" */
    0x8c, 0xa2, 0x11, 0x11, 0x12, 0xac, 0x80,

    /* U+002A "*" */
    0x21, 0x3e, 0xa7, 0x44,

    /* U+002B "+" */
    0x10, 0x23, 0xc0, 0xf1, 0x2, 0x0,

    /* U+002C "," */
    0x74, 0x62, 0xe1, 0x8, 0x40,

    /* U+002D "-" */
    0x1f, 0x80,

    /* U+002E "." */
    0x74, 0x62, 0xe0,

    /* U+002F "/" */
    0x1, 0x1, 0x1, 0x1, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40, 0x80,

    /* U+0030 "0" */
    0x3e, 0x10, 0x6b, 0x89, 0x11, 0x84, 0x60, 0x18,
    0x6, 0x1, 0x40, 0x98, 0x61, 0xe0,

    /* U+0031 "1" */
    0x2, 0x0, 0xc0, 0x48, 0x11, 0x4, 0x2, 0x0,
    0x80, 0x20, 0x10, 0x4, 0xf, 0xf0,

    /* U+0032 "2" */
    0x30, 0x3, 0x0, 0x30, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x83, 0x5f, 0x38, 0x0,

    /* U+0033 "3" */
    0x1c, 0x1, 0x80, 0x20, 0x10, 0x70, 0x20, 0x1c,
    0x1, 0x0, 0x81, 0xbf, 0x0,

    /* U+0034 "4" */
    0x80, 0x20, 0x8, 0x2, 0x0, 0x90, 0x24, 0x39,
    0x72, 0xe0, 0xd0, 0x4, 0x1, 0x0,

    /* U+0035 "5" */
    0x7f, 0x84, 0x1, 0x1, 0xf0, 0x93, 0x24, 0x26,
    0x4, 0x1, 0x0, 0x5c, 0x20, 0xf0,

    /* U+0036 "6" */
    0x18, 0x18, 0x4, 0x2, 0x0, 0x80, 0x20, 0x68,
    0x26, 0x9, 0x42, 0x98, 0x61, 0xe0,

    /* U+0037 "7" */
    0xc0, 0x30, 0xc, 0x3, 0x2, 0x4, 0x4, 0x8,
    0x10, 0x10, 0x20,

    /* U+0038 "8" */
    0x3f, 0x10, 0x24, 0x9, 0x2, 0x3f, 0x0, 0x7,
    0xfa, 0x1, 0x80, 0x60, 0x17, 0xf8,

    /* U+0039 "9" */
    0x1f, 0x8, 0x24, 0x5, 0x1, 0x44, 0x48, 0xa1,
    0xf0, 0x2, 0x1, 0xc7, 0x8e, 0x0,

    /* U+003A ":" */
    0x74, 0x62, 0xe0, 0x3a, 0x31, 0x70,

    /* U+003B ";" */
    0x74, 0x62, 0xe0, 0x3a, 0x31, 0x70, 0x84, 0x20,

    /* U+003C "<" */
    0x2, 0x1c, 0xce, 0x13, 0x21, 0xc0, 0x80,

    /* U+003D "=" */
    0xe0, 0x70, 0x38, 0x1c,

    /* U+003E ">" */
    0x81, 0xc2, 0x64, 0x39, 0x9c, 0x20, 0x0,

    /* U+003F "?" */
    0xfc, 0x4, 0x8, 0x13, 0xc4, 0x8, 0x0, 0x71,
    0x12, 0x23, 0x80,

    /* U+0040 "@" */
    0x0,

    /* U+0041 "A" */
    0x7e, 0x4, 0xea, 0x38, 0x30, 0x60, 0xa3, 0x3a,

    /* U+0042 "B" */
    0x81, 0x3, 0xe4, 0x28, 0x37, 0x69, 0xd3, 0xbb,
    0x6, 0x17, 0xc8, 0x10, 0x0,

    /* U+0043 "C" */
    0xf, 0xc, 0x24, 0x5, 0x31, 0x90, 0x64, 0x29,
    0x12, 0x38, 0x80, 0x50, 0x63, 0xe0,

    /* U+0044 "D" */
    0x10, 0x4, 0x1, 0x3, 0xf0, 0x13, 0x4, 0x21,
    0x4, 0x41, 0x10, 0x44, 0x21, 0x30, 0x70,

    /* U+0045 "E" */
    0x3, 0xc0, 0xc0, 0x10, 0x2, 0x0, 0xff, 0xf2,
    0x0, 0x10, 0x0, 0xc0, 0x3, 0xc0,

    /* U+0046 "F" */
    0x7, 0x4, 0x42, 0x21, 0x10, 0xb0, 0x40, 0x20,
    0xfe, 0x8, 0x4, 0x1a, 0x11, 0x8, 0x84, 0x41,
    0xc0,

    /* U+0047 "G" */
    0xe, 0x18, 0xd0, 0x10, 0x8, 0x4, 0x3e, 0x13,
    0x9, 0x48, 0x9c, 0x43, 0xe0,

    /* U+0048 "H" */
    0x0, 0x8, 0x20, 0x10, 0x40, 0x40, 0x40, 0x80,
    0x81, 0xe1, 0xfc, 0x3e, 0x8, 0x4, 0x10, 0x4,
    0x40, 0x8, 0x80, 0x1, 0x0,

    /* U+0049 "I" */
    0x72, 0x28, 0x9c, 0x0, 0x82, 0x4, 0x10, 0x41,
    0x1f,

    /* U+004A "J" */
    0x1, 0xfc, 0x0, 0x80, 0x2, 0x20, 0x10, 0x80,
    0x41, 0x86, 0x1, 0xe0, 0x0,

    /* U+004B "K" */
    0x10, 0x4, 0x31, 0x30, 0x70, 0x30, 0x34, 0x3,
    0x0, 0x70, 0x13, 0x4, 0x31, 0x0,

    /* U+004C "L" */
    0x18, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
    0x24, 0x18, 0x18, 0xe7,

    /* U+004D "M" */
    0x30, 0x62, 0x44, 0x92, 0x25, 0xa, 0x18, 0x50,
    0xc2, 0x84, 0x1c, 0x0,

    /* U+004E "N" */
    0x90, 0x98, 0xa4, 0xa4, 0xc2, 0xc1, 0x81, 0x80,

    /* U+004F "O" */
    0x1f, 0x18, 0x24, 0x76, 0x22, 0x88, 0x62, 0x18,
    0x66, 0x1, 0x40, 0x98, 0x61, 0xe0,

    /* U+0050 "P" */
    0x20, 0x3e, 0x61, 0xa1, 0xa1, 0xa6, 0x78, 0x20,
    0x20, 0x20, 0x20, 0x20,

    /* U+0051 "Q" */
    0x3e, 0x10, 0x6b, 0x89, 0x11, 0x80, 0x60, 0x18,
    0x6, 0x11, 0x44, 0x99, 0x61, 0xe0, 0x20, 0x8,
    0xf, 0x80,

    /* U+0052 "R" */
    0x20, 0x1f, 0x18, 0x54, 0x2a, 0x15, 0x31, 0xe0,
    0x40, 0x20, 0x1e, 0x8, 0xe4, 0x0,

    /* U+0053 "S" */
    0x4, 0x8, 0x8, 0x8, 0x4, 0x2, 0x81, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0054 "T" */
    0x10, 0x23, 0xc0, 0xf1, 0x2, 0x4, 0x8, 0x10,

    /* U+0055 "U" */
    0x20, 0x90, 0x50, 0x28, 0x14, 0xa, 0x6, 0x3,
    0x1, 0xff, 0x80,

    /* U+0056 "V" */
    0x80, 0xc0, 0x50, 0x48, 0x24, 0x12, 0x8, 0x88,
    0x44, 0x3e, 0x0,

    /* U+0057 "W" */
    0x9, 0x8, 0x91, 0x89, 0x18, 0x91, 0x46, 0x23,
    0x9c,

    /* U+0058 "X" */
    0x20, 0x8c, 0x18, 0x44, 0x5, 0x0, 0x40, 0x14,
    0x4, 0x41, 0x4, 0xc0, 0x68, 0x8,

    /* U+0059 "Y" */
    0xc3, 0x24, 0x18, 0x18, 0x18, 0x18, 0x24, 0x24,
    0x24, 0x24, 0x24, 0x18,

    /* U+005A "Z" */
    0xff, 0xc0, 0x10, 0x4, 0x8, 0x81, 0xe0, 0x44,
    0x8, 0x2, 0x0, 0xff, 0xe0,

    /* U+005B "[" */
    0xf6, 0x49, 0x24, 0x92, 0x4b, 0xc0,

    /* U+005C "\\" */
    0x80, 0x80, 0x80, 0x80, 0x40, 0x20, 0x10, 0x8,
    0x4, 0x2, 0x1,

    /* U+005D "]" */
    0xf4, 0x92, 0x49, 0x24, 0x9b, 0xc0,

    /* U+005E "^" */
    0x0,

    /* U+005F "_" */
    0x0,

    /* U+0060 "`" */
    0x0,

    /* U+0061 "a" */
    0x7e, 0x4, 0xea, 0x38, 0x30, 0x60, 0xa3, 0x3a,

    /* U+0062 "b" */
    0x81, 0x3, 0xe4, 0x28, 0x37, 0x69, 0xd3, 0xbb,
    0x6, 0x17, 0xc8, 0x10, 0x0,

    /* U+0063 "c" */
    0xf, 0xc, 0x24, 0x5, 0x31, 0x90, 0x64, 0x29,
    0x12, 0x38, 0x80, 0x50, 0x63, 0xe0,

    /* U+0064 "d" */
    0x10, 0x4, 0x1, 0x3, 0xf0, 0x13, 0x4, 0x21,
    0x4, 0x41, 0x10, 0x44, 0x21, 0x30, 0x70,

    /* U+0065 "e" */
    0x3, 0xc0, 0xc0, 0x10, 0x2, 0x0, 0xff, 0xf2,
    0x0, 0x10, 0x0, 0xc0, 0x3, 0xc0,

    /* U+0066 "f" */
    0x7, 0x4, 0x42, 0x21, 0x10, 0xb0, 0x40, 0x20,
    0xfe, 0x8, 0x4, 0x1a, 0x11, 0x8, 0x84, 0x41,
    0xc0,

    /* U+0067 "g" */
    0xe, 0x18, 0xd0, 0x10, 0x8, 0x4, 0x3e, 0x13,
    0x9, 0x48, 0x9c, 0x43, 0xe0,

    /* U+0068 "h" */
    0x0, 0x8, 0x20, 0x10, 0x40, 0x40, 0x40, 0x80,
    0x81, 0xe1, 0xfc, 0x3e, 0x8, 0x4, 0x10, 0x4,
    0x40, 0x8, 0x80, 0x1, 0x0,

    /* U+0069 "i" */
    0x72, 0x28, 0x9c, 0x0, 0x82, 0x4, 0x10, 0x41,
    0x1f,

    /* U+006A "j" */
    0x1, 0xfc, 0x0, 0x80, 0x2, 0x20, 0x10, 0x80,
    0x41, 0x86, 0x1, 0xe0, 0x0,

    /* U+006B "k" */
    0x10, 0x4, 0x31, 0x30, 0x70, 0x30, 0x34, 0x3,
    0x0, 0x70, 0x13, 0x4, 0x31, 0x0,

    /* U+006C "l" */
    0x18, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24,
    0x24, 0x18, 0x18, 0xe7,

    /* U+006D "m" */
    0x30, 0x62, 0x44, 0x92, 0x25, 0xa, 0x18, 0x50,
    0xc2, 0x84, 0x1c, 0x0,

    /* U+006E "n" */
    0x90, 0x98, 0xa4, 0xa4, 0xc2, 0xc1, 0x81, 0x80,

    /* U+006F "o" */
    0x1f, 0x18, 0x24, 0x76, 0x22, 0x88, 0x62, 0x18,
    0x66, 0x1, 0x40, 0x98, 0x61, 0xe0,

    /* U+0070 "p" */
    0x20, 0x3e, 0x61, 0xa1, 0xa1, 0xa6, 0x78, 0x20,
    0x20, 0x20, 0x20, 0x20,

    /* U+0071 "q" */
    0x3e, 0x10, 0x6b, 0x89, 0x11, 0x80, 0x60, 0x18,
    0x6, 0x11, 0x44, 0x99, 0x61, 0xe0, 0x20, 0x8,
    0xf, 0x80,

    /* U+0072 "r" */
    0x20, 0x1f, 0x18, 0x54, 0x2a, 0x15, 0x31, 0xe0,
    0x40, 0x20, 0x1e, 0x8, 0xe4, 0x0,

    /* U+0073 "s" */
    0x4, 0x8, 0x8, 0x8, 0x4, 0x2, 0x81, 0x81,
    0x81, 0x42, 0x3c,

    /* U+0074 "t" */
    0x10, 0x23, 0xc0, 0xf1, 0x2, 0x4, 0x8, 0x10,

    /* U+0075 "u" */
    0x20, 0x90, 0x50, 0x28, 0x14, 0xa, 0x6, 0x3,
    0x1, 0xff, 0x80,

    /* U+0076 "v" */
    0x80, 0xc0, 0x50, 0x48, 0x24, 0x12, 0x8, 0x88,
    0x44, 0x3e, 0x0,

    /* U+0077 "w" */
    0x9, 0x8, 0x91, 0x89, 0x18, 0x91, 0x46, 0x23,
    0x9c,

    /* U+0078 "x" */
    0x20, 0x8c, 0x18, 0x44, 0x5, 0x0, 0x40, 0x14,
    0x4, 0x41, 0x4, 0xc0, 0x68, 0x8,

    /* U+0079 "y" */
    0xc3, 0x24, 0x18, 0x18, 0x18, 0x18, 0x24, 0x24,
    0x24, 0x24, 0x24, 0x18,

    /* U+007A "z" */
    0xff, 0xc0, 0x10, 0x4, 0x8, 0x81, 0xe0, 0x44,
    0x8, 0x2, 0x0, 0xff, 0xe0,

    /* U+007B "{" */
    0x0,

    /* U+007C "|" */
    0x0,

    /* U+007D "}" */
    0x0,

    /* U+007E "~" */
    0x33, 0xcc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 96, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 108, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 10, .adv_w = 172, .box_w = 9, .box_h = 5, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 16, .adv_w = 108, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 19, .adv_w = 156, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 33, .adv_w = 204, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 140, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 61, .adv_w = 111, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 65, .adv_w = 99, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 72, .adv_w = 99, .box_w = 4, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 79, .adv_w = 108, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 83, .adv_w = 147, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 89, .adv_w = 108, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 94, .adv_w = 131, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 96, .adv_w = 108, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 163, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 192, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 192, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 112, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 112, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 259, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 266, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 270, .adv_w = 144, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 277, .adv_w = 144, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 74, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 143, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 143, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 310, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 191, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 223, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 353, .adv_w = 175, .box_w = 9, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 370, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 271, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 127, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 255, .box_w = 14, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 440, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 239, .box_w = 13, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 464, .adv_w = 159, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 191, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 516, .adv_w = 172, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 156, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 549, .adv_w = 172, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 560, .adv_w = 172, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 223, .box_w = 12, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 580, .adv_w = 204, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 594, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 606, .adv_w = 204, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 80, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 625, .adv_w = 163, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 80, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 642, .adv_w = 42, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 643, .adv_w = 63, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 644, .adv_w = 46, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 143, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 143, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 666, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 191, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 223, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 709, .adv_w = 175, .box_w = 9, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 726, .adv_w = 175, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 739, .adv_w = 271, .box_w = 15, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 127, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 769, .adv_w = 255, .box_w = 14, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 796, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 808, .adv_w = 239, .box_w = 13, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 820, .adv_w = 159, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 828, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 842, .adv_w = 159, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 854, .adv_w = 191, .box_w = 10, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 872, .adv_w = 172, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 886, .adv_w = 156, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 905, .adv_w = 172, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 172, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 223, .box_w = 12, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 936, .adv_w = 204, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 156, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 962, .adv_w = 204, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 975, .adv_w = 54, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 976, .adv_w = 26, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 46, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 978, .adv_w = 160, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t saturn_font_16 = {
#else
lv_font_t saturn_font_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if SATURN_FONT_16*/

