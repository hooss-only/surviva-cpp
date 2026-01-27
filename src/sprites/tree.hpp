#pragma once

#include "entity.hpp"
#include "../behaviors/clickable.hpp"
#include "../behaviors/collidable.hpp"

class Tree : public Entity, public Clickable, public Collidable {
        public:
                Tree();
                ~Tree() = default;
};
