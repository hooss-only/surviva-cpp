#include "test_scene.hpp"

#include "../sprites/player.hpp"
#include "../sprites/dummy.hpp"

TestScene::TestScene() : TopView() {
        this->add_sprite(new Player());

        Dummy* d = new Dummy();
        d->set_position(100, 100);
        this->add_sprite(d);
}
