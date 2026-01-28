#include "distance.h"

#include <math.h>

float get_dist(SDL_FPoint a, SDL_FPoint b) {
        float A = a.x - b.x;
        A *= A;

        float B = a.y - b.y;
        B *= B;

        return sqrt(A + B);
}
