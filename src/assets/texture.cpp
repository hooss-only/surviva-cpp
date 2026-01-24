#include "texture.hpp"

#include "../game_status.h"

#include <SDL3_image/SDL_image.h>
#include <vector>
#include <cstring>
#include <cstdlib>

struct texture_slot {
        const char* path;
        SDL_Texture* texture;
        unsigned int usage_amount;
};

std::vector<texture_slot> texture_slots;

void free_slot(int index) {
        char tmp[128] = { 0 };
        strcpy(tmp, texture_slots[index].path);
        free((void*) texture_slots[index].path);
        SDL_DestroyTexture(texture_slots[index].texture);
        texture_slots.erase(texture_slots.begin() + index);
        
        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "Texture successfully freed: %s", tmp);
}

SDL_Texture* use_texture(const char* path) {
        for (texture_slot& slot: texture_slots) {
                if (!strcmp(path, slot.path)) {
                        slot.usage_amount++;
                        SDL_LogInfo(
                                SDL_LOG_CATEGORY_APPLICATION, 
                                "Texture successfully assigned: %s", path
                        );
                        return slot.texture;
                }
        }

        struct texture_slot slot = {
                (const char*) malloc(sizeof(char) * strlen(path)),
                IMG_LoadTexture(get_renderer(), path),
                1
        };

        texture_slots.push_back(slot);
        SDL_LogInfo(
                SDL_LOG_CATEGORY_APPLICATION, 
                "Texture successfully assigned: %s", path
        );
        return slot.texture;
}

void unuse_texture(SDL_Texture* texture) {
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

        SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "The texture to unuse is not available with texture manager.");
}
