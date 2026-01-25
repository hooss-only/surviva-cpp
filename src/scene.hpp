#pragma once

#include "sprite.hpp"

#include <vector>

class Scene {
        public:
                Scene();
                virtual ~Scene();

                virtual void update(double dt);
                virtual void render();

                void add_sprite(Sprite* sprite);

        protected:
                std::vector<Sprite*> sprites;

        private:
                void remove_dead_sprites();
                void process_hovering();
};
