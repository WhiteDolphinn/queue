#include <stdlib.h>
#include "queue_soft.h"
#include "log.h"

void queue_init(struct queue* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->data = (int*)calloc(QUEUE_SIZE, sizeof(int));

    queue_print(get_log_file(), queue);
}

void queue_delete(struct queue* queue)
{
    queue_print(get_log_file(), queue);

    queue->head = POISON;
    queue->tail = POISON;
    free(queue->data);
}

void queue_push(struct queue* queue, int i)
{
    queue_print(get_log_file(), queue);

    queue->data[queue->tail++] = i;
    queue->tail &= MASK;

    queue_print(get_log_file(), queue);
}

int queue_pop(struct queue* queue)
{
    queue_print(get_log_file(), queue);

    int i = queue->data[queue->head++];
    queue->head &= MASK;

    queue_print(get_log_file(), queue);
    return i;
}

void queue_print(FILE* file, struct queue* queue)
{
    fprintf(file, "========================\n");
    for(int i = 0; i < QUEUE_SIZE; i++)
    {
        if(queue->data[i] != (int)POISON)
            fprintf(file, "%d:  %d\n", i, queue->data[i]);
        else
            fprintf(file, "%d: %X\n", i, queue->data[i]);
    }
    fprintf(file, "========================\n\n");
}
