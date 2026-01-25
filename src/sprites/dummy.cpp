#include "dummy.hpp"

#include "../assets/texture.hpp"

Dummy::Dummy() : Entity() {
        this->texture->set_texture(use_texture("assets/dummy.png"));
}
