/**
 * Main game state and related functions.
 */

#ifndef _GAME_H
#define _GAME_H

/**
 * Draws the "HELLO WORLD!" message to the background.
 */
void draw_hello_world(void);

/**
 * Initializes the Noboru character's state and sprites.
 */
void init_noboru(void);

/**
 * Updates and animates the sprites for the Noboru character.
 */
void update_noboru(void);

/**
 * Initializes graphics, sound, and game state.
 */
void init_game(void);

/**
 * Executes core gameloop logic.
 */
void game_loop(void);

/**
 * Executes rendering logic that must occurr during a VBLANK.
 * Note: unsure if this is needed given the GBDK abstractions, should test if
 * updating VRAM before the vsync() call has any effect.
 */
void render(void);

#endif
