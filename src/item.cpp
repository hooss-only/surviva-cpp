#include "item.hpp"

void Item::on_use() {}

std::string& Item::get_name() {
        return this->name;
}

std::string& Item::get_description() {
        return this->description;
}

item_type_t Item::get_item_type() {
        return this->item_type;
}

TextureComponent* Item::get_texture() {
        return this->texture.get();
}

void Item::render_on_body(SDL_FPoint position) {
        if (!this->texture) return;
        
        position.y -= this->texture->get_size().y;
        position.x += 10;
        this->texture->render(position);
}
