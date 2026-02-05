#include "tool.hpp"

Tool::Tool(std::string name, std::string description, item_type_t item_type)
        : Item(name, description, item_type) {}

int Tool::get_damage() {
        return this->damage;
}
