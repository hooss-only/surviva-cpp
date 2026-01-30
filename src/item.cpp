#include "item.hpp"

void Item::on_use() {}

std::string& Item::get_name() {
        return this->name;
}

std::string& Item::get_description() {
        return this->description;
}

item_type_t Item::get_item_type() {
        return this->item_type;
}
