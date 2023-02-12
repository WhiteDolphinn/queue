#include <stdlib.h>
#include "queue_soft.h"

void queue_init(struct queue* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->data = (int*)calloc(QUEUE_SIZE, sizeof(int));
}

void queue_delete(struct queue* queue)
{
    queue->head = POISON;
    queue->tail = POISON;
    free(queue->data);
}

void queue_push(struct queue* queue, int i)
{
    queue->data[queue->tail++] = i;
}

int queue_pop(struct queue* queue)
{
    int i = queue->data[queue->head++];
    return i;
}
