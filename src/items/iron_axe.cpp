#include "iron_axe.hpp"

#include "../assets/texture.hpp"

IronAxe::IronAxe() {
        this->name = "Iron Axe";
        this->description = "Strong AXE!!!";
        this->item_type = ITEM_TYPE_AXE;

        this->texture = std::make_unique<TextureComponent>();
        this->texture->set_texture(use_texture("assets/axe.png"));
}
