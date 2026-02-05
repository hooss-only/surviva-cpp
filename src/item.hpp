#pragma once

#include <string>

#include "components/texture_component.hpp"

typedef enum {
        ITEM_TYPE_MATERIAL,
        ITEM_TYPE_AXE,
} item_type_t;

class Item {
        public:
                Item(std::string name, std::string description, item_type_t item_type);
                virtual ~Item() = default;

                virtual void on_use();
                
                std::string& get_name();
                std::string& get_description();
                item_type_t get_item_type();

                TextureComponent* get_texture();

                void render_on_body(SDL_FPoint body_position);

        protected:
                std::string name;
                std::string description;
                item_type_t item_type;
                std::unique_ptr<TextureComponent> texture;
};
