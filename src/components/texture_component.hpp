#pragma once
#include <SDL3/SDL.h>

class TextureComponent {
        public:
                TextureComponent() = default;
                ~TextureComponent();

                void set_texture(SDL_Texture* texture);
                void set_src(SDL_FRect src);
                void render(SDL_FPoint position);

        private:
                SDL_Texture* texture;
                SDL_FRect src;
};
