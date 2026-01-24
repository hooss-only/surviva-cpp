#pragma once
#include "../sprite.hpp"

class DummySprite: public Sprite {
        public:
                DummySprite();
                ~DummySprite() = default;

                void update(double dt) override;
};
