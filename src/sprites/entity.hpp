#pragma once

#include "../sprite.hpp"
#include "../components/inventory.hpp"

class Entity : public Sprite {
        public:
                Entity();
                virtual ~Entity() = default;

        protected:
                SDL_FPoint velocity;
                int hp, max_hp;
                int speed;

                std::unique_ptr<Inventory> inventory;
};
