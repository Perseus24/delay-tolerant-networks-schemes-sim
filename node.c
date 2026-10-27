#include "node.h"
#include <stdlib.h>
#include <math.h>

float rand_float(float max) { 
    return (float)rand() / RAND_MAX * max; 
}

void node_init(Node *n, int id, float world_size, float speed) {
    n->id = id;
    n->x = rand_float(world_size);
    n->y = rand_float(world_size);
    n->dest_x = rand_float(world_size);
    n->dest_y = rand_float(world_size);
    n->speed = speed;
}

void node_move(Node *n, float world_size) {

    // calculate gap
    float dx = n->dest_x - n->x;
    float dy = n->dest_y - n->y;

    float distance = sqrt(dx * dx + dy * dy);

    // check if arrived
    if (distance <= n->speed) {
        n->x = n->dest_x;
        n->y = n->dest_y;
        n->dest_x = rand_float(world_size);
        n->dest_y = rand_float(world_size);
    } else {
        // move to destination
        float direction_x = dx / distance;
        float direction_y = dy / distance;

        float step_x = direction_x * n->speed;
        float step_y = direction_y * n->speed;

        n->x += step_x;
        n->y += step_y;
    }
}