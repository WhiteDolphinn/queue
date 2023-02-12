#include <stdio.h>
#include "queue_soft.h"

int main()
{
    struct queue queue;
    queue_init(&queue);
    queue_push(&queue, 25);
    queue_delete(&queue);
    return 0;
}
