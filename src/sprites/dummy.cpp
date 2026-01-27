#include "dummy.hpp"

#include "../assets/texture.hpp"
#include "../game_status.hpp"

Dummy::Dummy() : 
        Entity(), 
        Clickable({0, 0, 16, 16}, &this->position), 
        Collidable({0, 13, 10, 3}, &this->position) 
{
        this->texture->set_texture(use_texture("assets/dummy.png"));
}

void Dummy::on_click(Uint8 button) {
        if (button == SDL_BUTTON_LEFT) {
                SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "You left-clicked DUMMY!!");
                set_debug_mode(!get_debug_mode());
        }
}
