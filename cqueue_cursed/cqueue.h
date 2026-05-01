// cqueue.h
#ifndef CQUEUE_H
#define CQUEUE_H

typedef struct Node {
    void* element;
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct Queue{
    Node* start_element;
    int size;
} Queue;


void queue_init(Queue *queue);

void queue_kill(Queue *queue);

void queue_push(Queue *queue, void* element);

void* queue_pop(Queue *queue);

void* queue_peek(Queue *queue);


#endif
