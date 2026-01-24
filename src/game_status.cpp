#include "game_status.hpp"

game_status_t game_status = { 0 };

void set_window(SDL_Window* window) {
        game_status.window = window;
}

SDL_Window* get_window() {
        return game_status.window;
}

void set_renderer(SDL_Renderer* renderer) {
        game_status.renderer = renderer;
}

SDL_Renderer* get_renderer() {
        return game_status.renderer;
}

void set_scene(Scene* scene) {
        game_status.current_scene = scene;
}

void change_scene(Scene* scene) {
        delete game_status.current_scene;
        game_status.current_scene = scene;
}

Scene* get_scene() {
        return game_status.current_scene;
}

void set_game_should_close(bool should_close) {
        game_status.should_close = should_close;
}

bool game_should_close() {
        return game_status.should_close;
}
