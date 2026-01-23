#include "dummy_sprite.hpp"

#include <SDL3_image/SDL_image.h>

#include "../game_status.h"

DummySprite::DummySprite() : Sprite() {
        this->texture = IMG_LoadTexture(get_renderer(), "assets/apple.png");
}

DummySprite::~DummySprite() {
        SDL_DestroyTexture(this->texture);
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
