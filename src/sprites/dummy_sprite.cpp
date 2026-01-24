#include "dummy_sprite.hpp"

#include "../game_status.h"
#include "../assets/texture.hpp"

DummySprite::DummySprite() : Sprite() {
        this->texture = use_texture("assets/apple.png");
}

DummySprite::~DummySprite() {
        unuse_texture(this->texture);
}

void DummySprite::update(double dt) {

}

void DummySprite::render() {
        SDL_FRect dst = {0, 0, 128, 128};
        SDL_RenderTexture(
                get_renderer(),
                this->texture,
                NULL, 
                &dst
        );
}
