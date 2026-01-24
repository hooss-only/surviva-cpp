#include "texture_component.hpp"

#include "../game_status.hpp"
#include "../assets/texture.hpp"

TextureComponent::~TextureComponent() {
        unuse_texture(this->texture);
}

void TextureComponent::set_texture(SDL_Texture* texture) {
        this->texture = texture;

        this->dst.w = this->texture->w;
        this->dst.h = this->texture->h;
}

void TextureComponent::render(SDL_FPoint position) {
        this->dst.x = position.x;
        this->dst.y = position.y;

        SDL_RenderTexture(
                get_renderer(),
                this->texture,
                NULL,
                &dst
        );
}
