#include "player.hpp"

#include "../assets/texture.hpp"

#define SPRITE_HEIGHT 16
#define SPRITE_WIDTH 10

Player::Player() : Entity(), Collidable({0, 13, 10, 3}, this) {
        this->texture->set_texture(use_texture("assets/player.png"));
        this->offset = { 5, 16 };
        this->texture->set_src({ 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT });

        this->inventory = std::make_unique<Inventory>(24);

        ticks = SDL_GetTicks();
}

void Player::update(double dt) {
        this->previous_position = this->position;

        animate();
        move(dt);

        this->position.x += this->velocity.x;
        this->position.y += this->velocity.y;
}

void Player::on_collide() {
        this->position = this->previous_position;
}

void Player::move(double dt) {
        const bool* key = SDL_GetKeyboardState(NULL);

        int vertical = 0, horizontal = 0;

        if (key[SDL_SCANCODE_W]) vertical--;
        if (key[SDL_SCANCODE_S]) vertical++;
        if (key[SDL_SCANCODE_A]) horizontal--;
        if (key[SDL_SCANCODE_D]) horizontal++;

        int speed = this->speed;
        if (horizontal * vertical) speed /= 1.414;

        if (key[SDL_SCANCODE_LSHIFT]) speed /= 2;

        this->velocity.x = speed * horizontal * dt;
        this->velocity.y = speed * vertical * dt;
}

void Player::animate() {
        if (SDL_GetTicks() - ticks < 500) return;
        ticks = SDL_GetTicks();

        this->texture->set_src({ 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT });

        if(!this->velocity.x && !this->velocity.y) return;

        float x = flipflop % 2 * SPRITE_WIDTH;
        this->texture->set_src({ x, 0, SPRITE_WIDTH, SPRITE_HEIGHT });
        flipflop++;
}
