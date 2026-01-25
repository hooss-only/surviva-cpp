#pragma once

#include "sprite.hpp"

typedef struct {
        Sprite* hovering;
} cursor_t;

void set_cursor_hovering(Sprite* sprite);
Sprite* get_cursor_hovering();
