#pragma once

#include "../item.hpp"

class Inventory {
        public:
                Inventory(int size);
                ~Inventory();

                void add_item(Item* item);
                Item* get_item(int index);
                Item** get_items();

        private:
                int size;
                Item** items;
};
