#pragma once

#include "../item.hpp"

#include <vector>

class Inventory {
        public:
                Inventory(int size);
                ~Inventory();
                
                bool add_item(Item* item);
                Item* get_item(int index);

                Item* get_item_on_hand();
                void set_hand_index(int index);
                int get_hand_index();

                int get_size();

        private:
                int size;
                int hand_index;
                std::vector<Item*> items;
};
