#include "item_entity.hpp"

#include "../game_status.hpp"

ItemEntity::ItemEntity(Item* item)
        : Entity(), Collidable({0, 0, 16, 16}, this) {
        this->item = item;

        this->offset = { 8, 8 };
}

void ItemEntity::render() {
        SDL_FPoint pos = {
                this->position.x - get_offset().x - get_scene()->get_camera().pos.x,
                this->position.y - get_offset().y - get_scene()->get_camera().pos.y
        };
        if (this->item) {
                TextureComponent* texture = this->item->get_texture();
                texture->render(pos);
        }
}

void ItemEntity::on_collide() {
        get_player()->get_inventory()->add_item(this->item);
        this->set_should_delete(true);
}
