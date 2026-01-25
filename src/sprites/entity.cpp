#include "entity.hpp"

Entity::Entity() {
        this->texture = std::make_unique<TextureComponent>();

        this->max_hp = 100;
        this->hp = max_hp;

        this->middle_point = 0;
}
