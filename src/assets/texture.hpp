#pragma once

#include <SDL3/SDL.h>

#include <string>

SDL_Texture* use_texture(const std::string path);
void unuse_texture(SDL_Texture* texture);

void unload_all_texture();
