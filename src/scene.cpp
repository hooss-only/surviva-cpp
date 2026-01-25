#include "scene.hpp"

#include "behaviors/clickable.hpp"
#include "cursor.hpp"

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
        process_hovering();
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

void Scene::process_hovering() {
        SDL_FPoint mouse;
        SDL_GetMouseState(&mouse.x, &mouse.y);
        for (Sprite* sprite: this->sprites) {
                auto* clickable = dynamic_cast<Clickable*>(sprite);

                SDL_FRect p = clickable->get_click_box();
                if (p.x >= mouse.x &&
                        p.x + p.w <= mouse.x &&
                        p.y >= mouse.y &&
                        p.y + p.h >= mouse.y) {
                        
                        set_cursor_hovering(sprite);
                        clickable->on_hover();
                        break;
                }
        }
}
