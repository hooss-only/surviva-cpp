#include "player.hpp"

#include "../assets/texture.hpp"

Player::Player() {
        this->texture->set_texture(use_texture("assets/apple.png"));
}

void Player::update(double dt) {
        move(dt);

        this->position.x += this->velocity.x;
        this->position.y += this->velocity.y;
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

        this->velocity.x = speed * horizontal * dt;
        this->velocity.y = speed * vertical * dt;
}
