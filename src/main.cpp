#include <SDL3/SDL.h>
#include "game_status.h"
#include "sprites/dummy_sprite.hpp"

int initialize_window() {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init error.");
                return 1;
        }

        set_window(SDL_CreateWindow(
                "Surviva",
                800, 600,
                0
        ));
        if (!get_window()) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation error.");
                return 1;
        }

        set_renderer(SDL_CreateRenderer(get_window(), NULL));
        if (!get_renderer()) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window renderer error.");
                return 1;
        }

        SDL_SetLogPriority(SDL_LOG_CATEGORY_APPLICATION,
                SDL_LOG_PRIORITY_DEBUG);

        return 0;
}

int main() {
        if (initialize_window())  return 1;

        DummySprite sprite;

        while (!game_should_close()) {
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_EVENT_QUIT) set_game_should_close(true);
                }
                
                sprite.update(0.1);

                SDL_RenderClear(get_renderer());
                sprite.render();
                SDL_RenderPresent(get_renderer());
        }

        SDL_DestroyRenderer(get_renderer());
        SDL_DestroyWindow(get_window());
        SDL_Quit();

        return 0;
}
