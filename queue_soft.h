#ifndef QUEUE_SOFT_H
#define QUEUE_SOFT_H

#define QUEUE_SIZE 256
#define POISON 0xDED32DED
#define MASK (QUEUE_SIZE - 1)

struct queue{
    int* data;
    unsigned int head;
    unsigned int tail;
};

#endif
