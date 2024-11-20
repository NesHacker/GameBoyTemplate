/**
 * Graphics & color related state and functions.
 */

#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>

#define RGB_SKY_BLUE        RGB8(160, 228, 240)
#define RGB_NOBORU_SKIN     RGB8(199, 172, 131)
#define RGB_NOBORU_PURPLE1  RGB8(135, 32, 216)
#define RGB_NOBORU_PURPLE2  RGB8(126, 0, 125)

void load_palettes(void);

#endif
