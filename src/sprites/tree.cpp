#include "tree.hpp"

#include "../assets/texture.hpp"
#include "../game_status.hpp"

#define SPRITE_WIDTH 48
#define SPRITE_HEIGHT 64
#define SHEET_AMOUNT 6

Tree::Tree() : 
        Entity(),
        Clickable({16, 36, 16, 28}, this),
        Collidable({16, 55, 16, 9}, this)
{
        this->texture->set_texture(use_texture("assets/tree.png"));
        this->offset = { 24, 64 };
        this->texture->set_src({ 0, 0, SPRITE_WIDTH, SPRITE_HEIGHT });
}

void Tree::on_click(Uint8 button) {
        if (button == SDL_BUTTON_LEFT) {
                Item* item = get_player()->get_inventory()->get_item_on_hand();
                if (!item) return;
                if (item->get_item_type() != ITEM_TYPE_AXE) return;
                
                this->hurt(10);

                float x = 0;
                float d = (float) this->max_hp / SHEET_AMOUNT;

                SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "## Start sheet calculate");
                for (int i=0; i<SHEET_AMOUNT; i++) {
                        SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "%d %f", hp, d*i);
                        if ((float) this->hp > d * i) {
                                x = (SHEET_AMOUNT - i - 1) * SPRITE_WIDTH;
                        }
                }

                SDL_LogDebug(SDL_LOG_CATEGORY_TEST, "## %f %f %d", x, d, hp);

                this->texture->set_src({ x, 0, SPRITE_WIDTH, SPRITE_HEIGHT });
        }
}
