#include <stdint.h>

#include "display.h"
#include "vector.h"

uint32_t *draw_rect_to(int x, int y, int width, int height, int window_width,
                       uint32_t color, uint32_t *color_buffer)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int current_x = x + i;
            int current_y = y + j;
            color_buffer[(window_width * current_y) + current_x] = color;
        }
    }
    return color_buffer;
}

uint32_t *draw_grid_to(int step_x, int step_y, int width, int height,
                       uint32_t color, uint32_t *color_buffer)
{
    for (int y = 0; y < height; y += 10)
    {
        for (int x = 0; x < window_width; x += 10)
        {
            color_buffer[(width * y) + x] = color;
        }
    }
    return color_buffer;
}

void render_custom_color_buffer(int window_width, SDL_Renderer *renderer,
                                SDL_Texture *color_buffer_texture,
                                uint32_t *color_buffer)
{
    SDL_UpdateTexture(color_buffer_texture, NULL, color_buffer,
                      (int)(window_width * sizeof(uint32_t)));
    SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL);
}

vec2_t project3d_2d(vec3_t point, float fov_factor)
{
    vec2_t projected_point = {.x = (fov_factor * point.x) / point.z,
                              .y = (fov_factor * point.y) / point.z};
    return projected_point;
}