#pragma once

#include "../item.hpp"

#include <vector>

class Inventory {
        public:
                Inventory(int size);
                ~Inventory() = default;
                
                bool add_item(Item* item);
                Item* get_item(int index);
                Item* get_item_on_hand();
                int get_size();

        private:
                int size;
                int hand_index = 0;
                std::vector<std::unique_ptr<Item>> items;
};
