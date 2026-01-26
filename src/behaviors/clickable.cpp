#include "clickable.hpp"

Clickable::Clickable() {
}

void Clickable::set_click_box(SDL_FRect box) {
        this->click_box = box;
}

void Clickable::on_hover() {}
void Clickable::on_click(Uint8 button) {}

SDL_FRect Clickable::get_click_box() {
        return this->click_box;
}
