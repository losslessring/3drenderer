#ifndef CUSTOM_DISPLAY_H
#define CUSTOM_DISPLAY_H

#include <stdint.h>
#include "display.h"

uint32_t *draw_rect_to(int x, int y, int width, int height, int window_width, uint32_t color, uint32_t *color_buffer);
uint32_t *draw_grid_to(int step_x, int step_y, int width, int height, uint32_t color, uint32_t *color_buffer);
void render_custom_color_buffer(int window_width, SDL_Renderer *renderer, SDL_Texture *color_buffer_texture, uint32_t *color_buffer);

#endif