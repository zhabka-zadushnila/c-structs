#include "cqueue.h"
#include <stdlib.h>

// there are actually lots of ways on how to make queue
// I want the most efficient dynamic queue
// Efficient queue is circular (the one that works with % op)
// But when we want to make it dynamic, we face a problem:
//      We do not actually know how to allocate new memory fast enough
//      In case there've been only pushes, we would just allocate new memory when it is like 50% full
//      But what if queue looks like f|e|e|e|e|e|e|f (f-full, e-empty) ? so the end pointer is at the start, and start pointer at the end
//      In this case, if we would do basic reallocation, we would get something like f|e|e|...|e|f|e|e...
//      Which is, honestly, kinda bad frfr
//      So that's pretty obvious, that we have to copy part of that queue
//      How may we do it? Probably, we have to introduce some stuff like "elements_amount"
//      So in this case we would know how much elements should we copy from the end to... uh... "new end"?..
//      It is pretty straightforward and I assert it would take always less than n/2 ops (which is really bad)
//      Another option is linked list!
//      And it is really good in comparison
//      Any operation would take const time


void queue_init(Queue *queue){
    queue->capacity = 8;
    queue->end_pointer = 0;
    queue->start_pointer = 0;
    queue->array = calloc(queue->capacity, sizeof(long));
}

void queue_kill(Queue* queue){
    free(queue->array);
    free(queue);
}

void queue_push(Queue *queue, long element){
    queue_check(queue);
}
