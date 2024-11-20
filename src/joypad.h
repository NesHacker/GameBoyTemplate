/**
 * Common joypad state and macros.
 */
#ifndef _JOYPAD_H
#define _JOYPAD_H

#include <gb/gb.h>

extern uint8_t joypad_down;
extern uint8_t joypad_pressed;

#define a_down() (joypad_down & J_A)
#define a_pressed() (joypad_pressed & J_A)

#define b_down() (joypad_down & J_B)
#define b_pressed() (joypad_pressed & J_B)

#endif