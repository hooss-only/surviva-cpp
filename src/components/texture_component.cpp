#include "texture_component.hpp"

#include "../game_status.hpp"
#include "../assets/texture.hpp"

TextureComponent::~TextureComponent() {
        unuse_texture(this->texture);
}

void TextureComponent::set_texture(SDL_Texture* texture) {
        this->texture = texture;
}

void TextureComponent::render(SDL_FPoint position) {
        SDL_FRect dst = {
                position.x,
                position.y,
                (float) this->texture->w * get_sprite_scale(),
                (float) this->texture->h * get_sprite_scale(),
        };

        SDL_RenderTexture(
                get_renderer(),
                this->texture,
                NULL,
                &dst
        );
}
