/**
 * Binary data loading variables and routines.
 */

#ifndef _DATA_H
#define _DATA_H

#include <gbdk/incbin.h>

INCBIN_EXTERN(background_tile_data)
INCBIN_EXTERN(sprite_tile_data)

/**
 * Loads graphics tiles into VRAM.
 */
void load_tilesets(void);

#endif
