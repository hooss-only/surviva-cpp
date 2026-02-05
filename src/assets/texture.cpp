#include "texture.hpp"

#include "../game_status.hpp"

#include <SDL3_image/SDL_image.h>
#include <vector>

struct texture_slot {
        std::string path;
        SDL_Texture* texture;
        unsigned int usage_amount;
};

std::vector<texture_slot> texture_slots;

void free_slot(int index) {
        std::string tmp = texture_slots[index].path;

        SDL_DestroyTexture(texture_slots[index].texture);
        texture_slots.erase(texture_slots.begin() + index);
        
        SDL_LogInfo(
                SDL_LOG_CATEGORY_APPLICATION,
                "Texture successfully freed: %s", tmp.c_str()
        );
}

SDL_Texture* use_texture(const std::string path) {
        for (texture_slot& slot: texture_slots) {
                if (path == slot.path) {
                        slot.usage_amount++;
                        SDL_LogInfo(
                                SDL_LOG_CATEGORY_APPLICATION, 
                                "Texture successfully assigned: %s", path.c_str()
                        );
                        return slot.texture;
                }
        }

        struct texture_slot slot = {
                path,
                IMG_LoadTexture(get_renderer(), path.c_str()),
                1
        };

        SDL_SetTextureScaleMode(slot.texture, SDL_SCALEMODE_NEAREST);

        if (!slot.texture) {
                SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "Texture is null!"
                );
                return NULL;
        }
        
        slot.path = path;

        texture_slots.push_back(slot);
        SDL_LogInfo(
                SDL_LOG_CATEGORY_APPLICATION, 
                "Texture successfully assigned: %s", path.c_str()
        );
        return slot.texture;
}

void unload_all_texture() {
        SDL_LogWarn(
                SDL_LOG_CATEGORY_APPLICATION,
                "Your program is trying to unload all textures regardless there is remained users!"
        );
        for (int i=0; i<texture_slots.size(); i++) {
                free_slot(0);
        }
}

void unuse_texture(SDL_Texture* texture) {
        if (!texture) return;

        int index = 0;
        for (int i=0; i<texture_slots.size(); i++) {
                if (texture == texture_slots[i].texture) {
                        texture_slots[i].usage_amount--;
                        
                        if (texture_slots[i].usage_amount < 1) {
                                free_slot(i);
                                return;
                        }
                }
                index++;
        }

        SDL_LogWarn(
                SDL_LOG_CATEGORY_APPLICATION, 
                "The texture to unuse is not available with texture manager."
        );
}
