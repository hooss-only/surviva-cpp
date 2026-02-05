#pragma once

#include "../item.hpp"

class Tool : public Item {
        public:
                Tool(std::string name, std::string description, item_type_t item_type);
                virtual ~Tool() = default;

                int get_damage();

        protected:
                int damage = 0;
                int max_durability = 100;
                int durability = this->max_durability;
};
