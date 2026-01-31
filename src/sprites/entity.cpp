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

void Entity::hurt(int damage) {
        this->hp -= damage;
        if (hp <= 0) this->should_delete = true;
}

void Entity::render() {
        Sprite::render();
        if (!this->inventory) return;

        Item* item = this->inventory->get_item_on_hand();
        if (!item) return;

        item->render_on_body(this->get_screen_pos());
}
