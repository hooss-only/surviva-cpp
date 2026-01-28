#include "collidable.hpp"

#include "../game_status.hpp"

Collidable::Collidable(SDL_FRect box, Entity* owner) {
        this->box = {
                box.x * get_sprite_scale(),
                box.y * get_sprite_scale(),
                box.w * get_sprite_scale(),
                box.h * get_sprite_scale()
        };
        this->owner = owner;
}

void Collidable::on_collide() {
}

SDL_FRect Collidable::get_collide_box() {
        SDL_FPoint follow = this->owner->get_position();
        SDL_FPoint offset = this->owner->get_offset();
        return SDL_FRect {
                follow.x - offset.x + this->box.x,
                follow.y - offset.y + this->box.y,
                this->box.w,
                this->box.h
        };
}

bool Collidable::check_collision(Collidable* other) {
        SDL_FRect a = this->get_collide_box();
        SDL_FRect b = other->get_collide_box();

        return
                a.x < b.x + b.w &&
                a.x + a.w > b.x &&
                a.y < b.y + b.h &&
                a.y + a.h > b.y;
}
