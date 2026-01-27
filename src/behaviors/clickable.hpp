#pragma once

#include <SDL3/SDL.h>

class Clickable {
        public:
                Clickable(SDL_FRect box, const SDL_FPoint* follow);
                ~Clickable() = default;

                virtual void on_hover();
                virtual void on_click(Uint8 button);

                SDL_FRect get_click_box();

        private:
                SDL_FRect box;
                const SDL_FPoint* follow;
};
