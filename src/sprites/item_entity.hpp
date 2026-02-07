#pragma once

#include "../item.hpp"
#include "entity.hpp"
#include "../behaviors/collidable.hpp"

class ItemEntity : public Entity, public Collidable {
        public:
                ItemEntity(Item* item);
                ~ItemEntity();

                void render() override;
                void update(double dt) override;

                void on_collide() override;

        private:
                Item* item;
};
