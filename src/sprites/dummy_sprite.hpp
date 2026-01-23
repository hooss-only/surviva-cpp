#pragma once
#include "../sprite.hpp"

class DummySprite: public Sprite {
        public:
                DummySprite();
                ~DummySprite();

                void update(double dt) override;
                void render() override;

        private:
                SDL_Texture* texture;
};
