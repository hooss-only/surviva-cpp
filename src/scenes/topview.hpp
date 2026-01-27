#pragma once

#include "../scene.hpp"

class TopView : public Scene {
        public:
                TopView() = default;
                virtual ~TopView() = default;

                void update(double dt) override;
                void render() override;

        private:
                void check_collision();
                void order_sprites();

                void render_debug();
};
