#include "item_entity.hpp"

#include "../game_status.hpp"

ItemEntity::ItemEntity(Item* item)
        : Entity(), Collidable({0, 0, 16, 16}, this) {
        this->item = item;

        this->offset = { 8, 8 };

        this->item->get_texture()->set_scale(0);
}

void ItemEntity::render() {
        SDL_FPoint pos = {
                this->position.x - get_offset().x - get_scene()->get_camera().pos.x,
                this->position.y - get_offset().y - get_scene()->get_camera().pos.y
        };
        if (this->item) {
                TextureComponent* texture = this->item->get_texture();
                texture->render(pos, get_offset());
        }
}

void ItemEntity::update(double dt) {
        TextureComponent* texture = this->item->get_texture();
        float scale = texture->get_scale();
        if (scale < 1) {
                scale += 1 * dt;
        }

        texture->set_scale(scale);
}

void ItemEntity::on_collide() {
        this->item->get_texture()->set_scale(1);
        get_player()->get_inventory()->add_item(this->item);
        this->set_should_delete(true);
}
