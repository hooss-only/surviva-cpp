#include "clickable.hpp"

#include "../game_status.hpp"

Clickable::Clickable(SDL_FRect box, const SDL_FPoint* follow) {
        this->box = {
                box.x * get_sprite_scale(),
                box.y * get_sprite_scale(),
                box.w * get_sprite_scale(),
                box.h * get_sprite_scale()
        };
        this->follow = follow;
}

void Clickable::on_hover() {}
void Clickable::on_click(Uint8 button) {}

SDL_FRect Clickable::get_click_box() {
        return SDL_FRect {
                this->follow->x + this->box.x,
                this->follow->y + this->box.y,
                this->box.w,
                this->box.h
        };
}
