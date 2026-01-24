#pragma once

#include <SDL3/SDL.h>

SDL_Texture* use_texture(const char* path);
void unuse_texture(SDL_Texture* texture);

void unload_all_texture();
