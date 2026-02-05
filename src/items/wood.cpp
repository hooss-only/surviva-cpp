#include "wood.hpp"

#include "../assets/texture.hpp"

Wood::Wood() : Item("Wood", "A Wood", ITEM_TYPE_MATERIAL) {
        this->texture = std::make_unique<TextureComponent>();
        this->texture->set_texture(use_texture("assets/wood.png"));
}
