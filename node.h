#pragma once

typedef struct {
    int id;
    float x, y;            // current position
    float dest_x, dest_y;  // destination
    float speed;           // meters per tick
} Node;

void node_init(Node *n, int id, float world_size, float speed);
void node_move(Node *n, float world_size);