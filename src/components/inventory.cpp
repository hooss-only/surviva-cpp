#include "inventory.hpp"

Inventory::Inventory(int size) : items(size) { 
        this->size = size;
}

bool Inventory::add_item(Item* item) {
        for (int i=0; i<this->size; i++) {
                if (!items[i]) {
                        items[i].reset(item);
                        return true;
                }
        }
        return false;
}

Item* Inventory::get_item(int index) {
        return this->items[index].get();
}

Item* Inventory::get_item_on_hand() {
        return this->items[hand_index].get();
}

int Inventory::get_size() {
        return this->size;
}
