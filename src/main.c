#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdint.h>

#include "data.h"
#include "joypad.h"
#include "graphics.h"
#include "util.h"

/**
 * Bitfield for buttons that are currently being held down.
 *
 * @see J_START, J_SELECT, J_A, J_B, J_UP, J_DOWN, J_LEFT, J_RIGHT
 */
uint8_t joypad_down;

/**
 * Bitfield for buttons that were pressed as of this frame.
 *
 * @see J_START, J_SELECT, J_A, J_B, J_UP, J_DOWN, J_LEFT, J_RIGHT
 */
uint8_t joypad_pressed;

/**
 * Initializes graphics, sound, and game state.
 */
void initialize(void) {
  load_tilesets();
  load_palettes();
}

/**
 * Executes core gameloop logic.
 */
void game_loop(void) {
}

/**
 * Executes rendering logic that must occurr during a VBLANK.
 * Note: unsure if this is needed given the GBDK abstractions, should test if
 * updating VRAM before the vsync() call has any effect.
 */
void render(void) {
}

/**
 * Main function for the game. Initializes state and starts the game loop.
 */
void main(void) {
  // Initialize the game state
  lcd_off();
  initialize();
  lcd_on();

  // Start the main game loop
  while (1) {
    // Update joypad bitfields
    uint8_t last = joypad_down;
    joypad_down = joypad();
    joypad_pressed = (last ^ joypad_down) & joypad_down;

    // Execute game logic
    game_loop();

    // Wait for a VBLANK then execute rendering logic
    vsync();
    render();
  }
}
