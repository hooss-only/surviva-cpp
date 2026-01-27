#pragma once

#include <SDL3/SDL.h>

class Collidable {
        public:
                Collidable(SDL_FRect box, const SDL_FPoint* follow);
                ~Collidable() = default;

                virtual void on_collide();

                bool check_collision(Collidable* other);
                SDL_FRect get_collide_box();

        private:
                SDL_FRect box;
                const SDL_FPoint* follow;
};
