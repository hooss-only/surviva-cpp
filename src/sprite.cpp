#include "sprite.hpp"

Sprite::Sprite() {
        this->position = { 0 };
        this->should_delete = false;
}

bool Sprite::get_should_delete() {
        return this->should_delete;
}

void Sprite::set_should_delete(bool value) {
        this->should_delete = value;
}
