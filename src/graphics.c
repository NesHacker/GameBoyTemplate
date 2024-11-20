#include "graphics.h"

const uint16_t example_bg_palette[] = {
  RGB_SKY_BLUE,
  RGB_DARKGRAY,
  RGB_LIGHTGRAY,
  RGB_WHITE
};

const uint16_t example_fg_palette[] = {
  RGB_BLACK,
  RGB_NOBORU_PURPLE1,
  RGB_NOBORU_PURPLE2,
  RGB_NOBORU_SKIN
};

void load_palettes (void) {
  set_bkg_palette(0, 1, example_bg_palette);
  set_sprite_palette(0, 1, example_fg_palette);
}
