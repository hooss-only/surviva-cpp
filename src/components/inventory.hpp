#pragma once

#include "../item.hpp"

#include <vector>

class Inventory {
        public:
                Inventory(int size);
                ~Inventory() = default;

                bool add_item(Item* item);
                Item* get_item(int index);
                int get_size();

        private:
                int size;
                std::vector<std::unique_ptr<Item>> items;
};
