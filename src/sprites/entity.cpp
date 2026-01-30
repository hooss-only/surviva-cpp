#include "entity.hpp"

Entity::Entity() : Sprite() {
        this->texture = std::make_unique<TextureComponent>();

        this->velocity = { 0 };

        this->max_hp = 100;
        this->hp = max_hp;

        this->speed = 200;
}

Inventory* Entity::get_inventory() {
        return this->inventory.get();
}
