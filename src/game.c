#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>

#include "data.h"
#include "game.h"
#include "graphics.h"
#include "util.h"

/**
 * Timer used for Noboru's "Walking" animation.
 */
Timer walk_timer;

/**
 * Current walk frame (either 0 or 1).
 */
uint8_t walk_frame;


void init_game(void) {
  load_tilesets();
  load_palettes();
  draw_hello_world();
  init_noboru();
}

void game_loop(void) {
  update_noboru();
}

void render(void) {
}

void init_noboru(void) {
  // Initialize the two 8x16 sprites for the character.
  const uint8_t x = 56;
  const uint8_t y = 70;
  const uint8_t frame = walk_frame << 2;

  set_sprite_tile(0, frame);
  set_sprite_prop(0, 0);
  move_sprite(0, x, y);

  set_sprite_tile(1, frame + 2);
  set_sprite_prop(1, 0);
  move_sprite(1, x + 8, y);

  // Initialize the walking animation timer & state
  init_timer(walk_timer, 12);
  walk_frame = 0;
}

void update_noboru(void) {
  const uint8_t frame = walk_frame << 2;
  if (update_timer(walk_timer)) {
    walk_frame ^= 1;
    reset_timer(walk_timer);
  }
  set_sprite_tile(0, frame);
  set_sprite_tile(1, frame + 2);
}

void draw_hello_world(void) {
  // Note: GBDK has methods for string printing (e.g. printf) but this example
  // shows how to set pointers, write arbitrary data to the VRAM, etc.

  // Initialize a VRAM address at the 2nd row and 3rd column.
  uint8_t *char_addr = (void *)(0x9800 + 0x10 * 2 + 3);

  // Set the bank so that we're writing to background tile ids
  VBK_REG = VBK_TILES;
  // VBK_REG = VBK_ATTRIBUTES; // Use this to write tile attributes

  // Initialize a string constant, and step through the character writing
  // data to the VRAM and incremented the VRAM address with each character
  // placed
  const char *hello = "HELLO WORLD!";
  const uint8_t len = 12;
  for (uint8_t k = 0; k < len; k++) {
    uint8_t c = (uint8_t)hello[k];
    set_vram_byte(char_addr++, c);
  }
}