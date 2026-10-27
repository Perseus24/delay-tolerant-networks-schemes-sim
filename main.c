#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOTAL_NODES 100
#define WORLD_SIZE 2000 // 2km
#define SPEED 1.4

int main() {

    Node nodes[TOTAL_NODES];

    srand(42);
    // initialize nodes
    for (int i = 0; i<TOTAL_NODES; i++) {
        node_init(&nodes[i], i, WORLD_SIZE, SPEED);
    }

    // sample movement
    // 10 steps
    for (int i = 0; i<10; i++) {
        node_move(&nodes[0], WORLD_SIZE);
        printf("x: %f, y: %f\n", nodes[0].x, nodes[0].y);
    }

    return 0;

}