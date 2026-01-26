#pragma once

#include <SDL3/SDL.h>

class Clickable {
        public:
                Clickable();
                ~Clickable() = default;

                void set_click_box(SDL_FRect box);
                
                virtual void on_hover();
                virtual void on_click(Uint8 button);

                SDL_FRect get_click_box();

        private:
                SDL_FRect click_box;
};
