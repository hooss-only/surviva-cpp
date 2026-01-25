#include "clickable.hpp"

Clickable::Clickable(SDL_FRect box) {
        click_box = {
                box.x,
                box.y,
                box.w,
                box.h
        };
}

void Clickable::on_hover() {}
void Clickable::on_click() {}

SDL_FRect Clickable::get_click_box() {
        return this->click_box;
}
