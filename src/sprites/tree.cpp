#include "tree.hpp"

#include "../assets/texture.hpp"
#include "../game_status.hpp"

Tree::Tree() : 
        Entity(),
        Clickable({16, 36, 16, 28}, this),
        Collidable({16, 55, 16, 9}, this)
{
        this->texture->set_texture(use_texture("assets/tree.png"));
        this->offset = { 24, 64 };
}

void Tree::on_click(Uint8 button) {
        if (button == SDL_BUTTON_LEFT) {
                Item* item = get_player()->get_inventory()->get_item_on_hand();
                if (!item) return;
                if (item->get_item_type() != ITEM_TYPE_AXE) return;
                
                this->hurt(30);
                SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "HP: %d", this->hp);
        }
}
