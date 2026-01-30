#include "inventory.hpp"

Inventory::Inventory(int size) : items(size) {
}

Inventory::~Inventory() {
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

int Inventory::get_size() {
        return this->size;
}
