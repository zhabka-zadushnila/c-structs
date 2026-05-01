// cstack.h
#ifndef CSTACK_H
#define CSTACK_H

typedef struct Stack{
    int size;
    int top_pointer;
    long* array_pointer;
} Stack;


void stack_init(Stack *stack);

void stack_kill(Stack *stack);

void stack_push(Stack *stack, long element);

long stack_pop(Stack *stack);

long stack_peek(Stack *stack);

void realloc_stack(Stack *stack, int newsize);

void stack_check(Stack *stack);

#endif
