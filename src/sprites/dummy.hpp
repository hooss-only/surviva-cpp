#pragma once

#include "entity.hpp"
#include "../behaviors/clickable.hpp"
#include "../behaviors/collidable.hpp"

class Dummy : public Entity, public Clickable, public Collidable {
        public:
                Dummy();
                ~Dummy() = default;

                void on_click(Uint8 button) override;
};
