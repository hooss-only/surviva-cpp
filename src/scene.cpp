#include "scene.hpp"

Scene::Scene() {
}

Scene::~Scene() {
        for (Sprite* sprite: this->sprites) {
                delete sprite;
        }
        sprites.clear();
}

void Scene::update(double dt) {
        this->remove_dead_sprites();
        for (Sprite* sprite: this->sprites) {
                sprite->update(dt);
        }
}

void Scene::render() {
        for (Sprite* sprite: this->sprites) {
                sprite->render();
        }
}

void Scene::add_sprite(Sprite* sprite) {
        this->sprites.push_back(sprite);
}

void Scene::remove_dead_sprites() {
        for (auto it = this->sprites.begin(); it != this->sprites.end(); ) {
                if ((*it)->get_should_delete()) {
                        it = sprites.erase(it);
                } else {
                        it++;
                }
        }
}
