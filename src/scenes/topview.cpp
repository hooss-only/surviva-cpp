#include "topview.hpp"

#include "../behaviors/collidable.hpp"
#include "../behaviors/clickable.hpp"
#include "../game_status.hpp"
#include <algorithm>

void TopView::update(double dt) {
        this->check_collision();
        this->order_sprites();
        Scene::update(dt);
}

void TopView::check_collision() {
        for (Sprite* sprite: this-> sprites) {
                Collidable* collidable = dynamic_cast<Collidable*>(sprite);
                if (!collidable) continue;

                for (Sprite* other_sprite: this->sprites) {
                        if (other_sprite == sprite) continue;

                        Collidable* other = dynamic_cast<Collidable*>(other_sprite);
                        if (!other) continue;

                        if (collidable->check_collision(other)) {
                                collidable->on_collide();
                                other->on_collide();
                        }
                }
        }
}

void TopView::render() {
        Scene::render();

        if(get_debug_mode()) this->render_debug();
}

void TopView::render_debug() {
        for (Sprite* sprite: this->sprites) {
                Collidable* collidable = dynamic_cast<Collidable*>(sprite);
                if (collidable) {
                        SDL_SetRenderDrawColor(get_renderer(), 255, 0, 0, 255);
                        SDL_FRect rect = collidable->get_collide_box();
                        SDL_RenderRect(get_renderer(), &rect);;
                }
                Clickable* clickable = dynamic_cast<Clickable*>(sprite);
                if (clickable) {
                        SDL_SetRenderDrawColor(get_renderer(), 0, 255, 0, 255);
                        SDL_FRect rect = clickable->get_click_box();
                        SDL_RenderRect(get_renderer(), &rect);;
                }
        }
}

void TopView::order_sprites() {
        std::sort(this->sprites.begin(), this->sprites.end(),
                [](Sprite* a, Sprite* b) {
                        return a->get_position().y + a->get_scale().y
                                < b->get_position().y + b->get_scale().y;
                }
        );
}
