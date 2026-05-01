// cqueue.h
#ifndef CQUEUE_H
#define CQUEUE_H

typedef struct Queue{
    int capacity;
    long end_pointer;
    long start_pointer;
    long* array;
} Queue;


void queue_init(Queue *queue);

void queue_kill(Queue *queue);

void queue_push(Queue *queue, long element);

long queue_pop(Queue *queue);

long queue_peek(Queue *queue);

void realloc_queue(Queue *queue, int newsize);

void queue_check(Queue *queue);

#endif
