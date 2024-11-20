/**
 * GB/GBC Common Utility Functions & Macros
 */
#ifndef _UTIL_H
#define _UTIL_H

/**
 * Disables interrupts, turns of the LCD, and sets default rendering flags
 * (8x16 objects, objects rendering on, background rendering on).
 */
#define lcd_off() do { \
    disable_interrupts(); \
    DISPLAY_OFF; \
    LCDC_REG = LCDCF_OFF | LCDCF_OBJ16 | LCDCF_OBJON | LCDCF_BGON; \
  } while (0)

/**
 * Enables interrupts and turns the LCD on.
 */
#define lcd_on() do { \
    DISPLAY_ON; \
    enable_interrupts(); \
  } while (0)

#endif
