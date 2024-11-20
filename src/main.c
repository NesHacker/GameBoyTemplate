#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>

#include "game.h"
#include "joypad.h"
#include "util.h"

uint8_t joypad_down;
uint8_t joypad_pressed;
uint8_t joypad_released;

/**
 * Main function for the game. Handles initialization, game loop setup, and
 * joypad state updates.
 */
void main(void) {
  // Initialize the game state
  lcd_off();
  LCDC_REG = LCDCF_OFF | LCDCF_OBJ16 | LCDCF_OBJON | LCDCF_BGON;
  init_game();
  lcd_on();

  // Start the main game loop
  while (1) {
    // Update joypad bitfields
    uint8_t last = joypad_down;
    joypad_down = joypad();
    joypad_pressed = ~last & joypad_down;
    joypad_released = last & ~joypad_down;

    // Execute game logic
    game_loop();

    // Wait for a VBLANK then execute rendering logic
    vsync();
    render();
  }
}
