#include <gb/gb.h>
#include "data.h"

// Include binary tile data
INCBIN(background_tile_data, "res/background_tile_data.bin")
INCBIN(sprite_tile_data, "res/sprite_tile_data.bin")

void load_tilesets(void) {
  set_tile_data(0x00, 0x80, sprite_tile_data, 0x80);
  set_tile_data(0x00, 0x80, background_tile_data + 128 * 16, 0x88);
  set_tile_data(0x00, 0x80, background_tile_data, 0x90);
}
