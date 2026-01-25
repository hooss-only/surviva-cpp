#pragma once

#include <SDL3/SDL.h>

class Clickable {
        public:
                Clickable(SDL_FRect box);
                ~Clickable() = default;

                virtual void on_hover();
                virtual void on_click();

                SDL_FRect get_click_box();

        private:
                SDL_FRect click_box;
};
