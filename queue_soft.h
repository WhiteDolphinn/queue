#ifndef QUEUE_SOFT_H
#define QUEUE_SOFT_H

#include <stdio.h>
#define QUEUE_SIZE 8
#define POISON 0xDED32DED
#define MASK (QUEUE_SIZE - 1)

struct queue{
    int* data;
    unsigned int head;
    unsigned int tail;
    bool block_push;
    bool block_pop;
};

void queue_init(struct queue* queue);
void queue_delete(struct queue* queue);
void queue_push(struct queue* queue, int i);
int queue_pop(struct queue* queue);
void queue_check(FILE* file, struct queue* queue, const char* filename, const char* function_name, int line);

#endif
