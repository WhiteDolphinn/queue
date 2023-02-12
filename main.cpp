#include <stdio.h>
#include "queue_soft.h"

int main()
{
    struct queue queue;
    queue_init(&queue);

    queue_push(&queue, -2);
    queue_push(&queue, -1);
    for(int i = 0; i < 19; i++)
    {
        queue_push(&queue, i);
        int j = queue_pop(&queue);
    }

    queue_delete(&queue);
    return 0;
}
