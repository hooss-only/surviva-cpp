#pragma once
#include <SDL3/SDL.h>

#include <memory>

#include "components/texture_component.hpp"

class Sprite {
        public:
                Sprite();
                virtual ~Sprite() = default;
                
                virtual void update(double dt);
                virtual void render();
                void set_should_delete(bool value);
                bool get_should_delete();

                SDL_FPoint& get_position();
                void set_position(float x, float y);
                SDL_FPoint get_screen_pos();

                SDL_FPoint get_offset();

                SDL_FPoint get_scale();

        protected:
                SDL_FPoint position;
                SDL_FPoint offset;

                bool should_delete;

                std::unique_ptr<TextureComponent> texture;
};
