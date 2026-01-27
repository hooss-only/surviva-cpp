#pragma once

#include <SDL3/SDL.h>
#include <stdbool.h>

#include "scene.hpp"

typedef struct {
        SDL_Window* window;
        SDL_Renderer* renderer;

        Scene* current_scene;

        int scale;

        bool debug;
        bool should_close;
} game_status_t;

void set_window(SDL_Window* window);
SDL_Window* get_window();

void set_renderer(SDL_Renderer* renderer);
SDL_Renderer* get_renderer();

void set_scene(Scene* scene);
void change_scene(Scene* scene);
Scene* get_scene();

void set_sprite_scale(int scale);
int get_sprite_scale();

void set_debug_mode(bool debug);
bool get_debug_mode();

void set_game_should_close(bool should_close);
bool game_should_close();
