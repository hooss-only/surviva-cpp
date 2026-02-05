#include "tree.hpp"

#include "../sprites/item_entity.hpp"
#include "../items/wood.hpp"
#include "../items/tool.hpp"
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

Tree::~Tree() {
        ItemEntity* w = new ItemEntity(new Wood());
        w->set_position(this->get_position().x, this->get_position().y);
        get_scene()->add_sprite(w);
}

void Tree::on_click(Uint8 button) {
        if (button == SDL_BUTTON_LEFT) {
                Item* item = get_player()->get_inventory()->get_item_on_hand();
                Tool* tool = dynamic_cast<Tool*>(item);
                if (!tool) return;
                if (tool->get_item_type() != ITEM_TYPE_AXE) return;

                this->hurt(tool->get_damage());

                float x = 0, d = (float) this->max_hp / SHEET_AMOUNT;
                int i = 0;

                for (i=0; i<SHEET_AMOUNT; i++) {
                        if ((float) this->hp > d * i) {
                                x = (SHEET_AMOUNT - i - 1) * SPRITE_WIDTH;
                        }
                }
                
                this->texture->set_src({ x, 0, SPRITE_WIDTH, SPRITE_HEIGHT });
        }
}
