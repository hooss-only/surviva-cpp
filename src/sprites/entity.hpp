#pragma once

#include "../sprite.hpp"

class Entity : public Sprite {
        public:
                Entity();
                virtual ~Entity() = default;

        protected:
                int hp, max_hp;
                int middle_point;
};
