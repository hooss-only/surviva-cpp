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

void Scene::handle_event(SDL_Event& event) {
        if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
                Clickable* hovering = dynamic_cast<Clickable*>(get_cursor_hovering());
                if (hovering) {
                        hovering->on_click(event.button.button);
                }
        }
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
                if (!clickable) continue;

                SDL_FRect p = clickable->get_click_box();
                if (p.x <= mouse.x &&
                        p.x + p.w >= mouse.x &&
                        p.y <= mouse.y &&
                        p.y + p.h >= mouse.y) {

                        set_cursor_hovering(sprite);
                        clickable->on_hover();
                        return;
                }
        }
        set_cursor_hovering(nullptr);
}
