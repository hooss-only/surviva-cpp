#include "sprite.hpp"

#include "game_status.hpp"

Sprite::Sprite() {
        this->position = { 0 };
        this->offset = { 0 };
        this->should_delete = false;
}

void Sprite::update(double dt) {
}

void Sprite::render() {
        SDL_FPoint pos = {
                this->position.x - get_offset().x - get_scene()->get_camera().pos.x,
                this->position.y - get_offset().y - get_scene()->get_camera().pos.y
        };
        if (texture) texture->render(pos, get_offset());
}

bool Sprite::get_should_delete() {
        return this->should_delete;
}

void Sprite::set_should_delete(bool value) {
        this->should_delete = value;
}

SDL_FPoint Sprite::get_offset() {
        SDL_FPoint offset = {
                this->offset.x * get_sprite_scale(),
                this->offset.y * get_sprite_scale(),
        };
        return offset;
}

SDL_FPoint Sprite::get_screen_pos() {
        SDL_FPoint screen_pos = {
                this->position.x - get_scene()->get_camera().pos.x,
                this->position.y - get_scene()->get_camera().pos.y
        };

        return screen_pos;
}

SDL_FPoint& Sprite::get_position() {
        return this->position;
}

void Sprite::set_position(float x, float y) {
        this->position.x = x;
        this->position.y = y;
}

SDL_FPoint Sprite::get_scale() {
        return this->texture->get_size();
}
