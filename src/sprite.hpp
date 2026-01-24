#pragma once
#include <SDL3/SDL.h>

class Sprite {
        public:
                Sprite();
                virtual ~Sprite() = default;
                
                virtual void update(double dt) = 0;
                virtual void render() = 0;
                void set_should_delete(bool value);
                bool get_should_delete();

        protected:
                SDL_FPoint position;
                bool should_delete;
};
