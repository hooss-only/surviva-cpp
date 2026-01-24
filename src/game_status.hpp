#pragma once

#include <SDL3/SDL.h>
#include <stdbool.h>

#include "scene.hpp"

typedef struct {
        SDL_Window* window;
        SDL_Renderer* renderer;

        Scene* current_scene;

        bool should_close;
} game_status_t;

void set_window(SDL_Window* window);
SDL_Window* get_window();

void set_renderer(SDL_Renderer* renderer);
SDL_Renderer* get_renderer();

void set_scene(Scene* scene);
void change_scene(Scene* scene);
Scene* get_scene();

void set_game_should_close(bool should_close);
bool game_should_close();
