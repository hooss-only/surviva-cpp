#include "dummy_sprite.hpp"

#include <memory>

#include "../assets/texture.hpp"

DummySprite::DummySprite() : Sprite() {
        this->texture = std::make_unique<TextureComponent>();
        this->texture->set_texture(use_texture("assets/apple.png"));
}

void DummySprite::update(double dt) {

}
