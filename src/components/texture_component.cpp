#include "texture_component.hpp"

#include "../game_status.hpp"
#include "../assets/texture.hpp"

TextureComponent::~TextureComponent() {
        unuse_texture(this->texture);
}

void TextureComponent::set_texture(SDL_Texture* texture) {
        this->texture = texture;

        this->src = {
                0, 0,
                (float) this->texture->w, 
                (float) this->texture->h
        };
}

void TextureComponent::set_src(SDL_FRect src) {
        this->src = {
                src.x, src.y, src.w, src.h
        };
}

void TextureComponent::render(SDL_FPoint position) {
        SDL_FRect dst = {
                position.x,
                position.y,
                (float) this->src.w * get_sprite_scale(),
                (float) this->src.h * get_sprite_scale(),
        };

        SDL_RenderTexture(
                get_renderer(),
                this->texture,
                &this->src,
                &dst
        );
}
