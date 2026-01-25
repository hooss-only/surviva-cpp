#include "cursor.hpp"

cursor_t cursor = { 0 };

void set_cursor_hovering(Sprite* sprite) {
        cursor.hovering = sprite;
}

Sprite* get_cursor_hovering() {
        return cursor.hovering;
}
