#pragma once

#include <string>

typedef enum {
        ITEM_TYPE_AXE,
} item_type_t;

class Item {
        public:
                Item() = default;
                virtual ~Item() = default;

                virtual void on_use();
                
                std::string& get_name();
                std::string& get_description();
                item_type_t get_item_type();

        protected:
                std::string name;
                std::string description;
                item_type_t item_type;
};
