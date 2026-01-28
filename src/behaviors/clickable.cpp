#include "clickable.hpp"

#include "../game_status.hpp"
#include "../math/distance.h"

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

bool Clickable::is_in_player_reach() {
        float dist = get_dist(
                *this->follow,
                get_player()->get_position()
        );
        return dist <= get_player()->reach;
}

SDL_FRect Clickable::get_click_box() {
        return SDL_FRect {
                this->follow->x + this->box.x,
                this->follow->y + this->box.y,
                this->box.w,
                this->box.h
        };
}
