#pragma once
#include <SDL3/SDL.h>

class Sprite {
        public:
                Sprite();
                ~Sprite();
                
                virtual void update(double dt) = 0;
                virtual void render() = 0;

        protected:
                SDL_FPoint position;
};
