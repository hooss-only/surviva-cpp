#include "inventory.hpp"

Inventory::Inventory(int size) {
        this->size = size;
        this->items = new Item*[size];
        for (int i=0; i<this->size; i++) {
                items[i] = nullptr;
        }
}

Inventory::~Inventory() {
        for (int i=0; i<this->size; i++) {
                delete this->items[i];
        }
        delete[] this->items;
}

void Inventory::add_item(Item* item) {
        for (int i=0; i<this->size; i++)
                if (!items[i])
                        items[i] = item;
}

Item* Inventory::get_item(int index) {
        return this->items[index];
}

Item** Inventory::get_items() {
        return this->items;
}
