#include "dummy.hpp"

#include "../assets/texture.hpp"

Dummy::Dummy() : Entity(), Clickable() {
        this->texture->set_texture(use_texture("assets/dummy.png"));
        set_click_box({0, 0, 64, 64});
}

void Dummy::on_hover() {
}

void Dummy::on_click(Uint8 button) {
        if (button == SDL_BUTTON_LEFT) {
                SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "You left-clicked DUMMY!!");
        }
}
