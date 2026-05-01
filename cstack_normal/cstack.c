#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"


// Self compressing stack realisation 0_0
// pretty surprised it actually works

void stack_init(Stack *stack){
    stack->size = 8;
    stack->top_pointer = -1;
    stack->array_pointer = calloc(stack->size, sizeof(long));
}

void stack_kill(Stack *stack){
    free(stack->array_pointer);
    free(stack);
}
//size == 8 -> top_pointer == 7 -> stack full
void stack_push(Stack *stack, long element){
    stack_check(stack);
    stack->array_pointer[++stack->top_pointer] = element;
}

long stack_pop(Stack *stack){
    if(stack->top_pointer <0){
        fprintf(stderr, "Oopsie - seems like stack is empty\n");
        return 0;
    } else {
        if(stack->top_pointer < ((stack->size >>1) - 2)){
            realloc_stack(stack, stack->size >> 1);
        }
        return stack->array_pointer[stack->top_pointer--];
    }
}

long stack_peek(Stack *stack){
    if(stack->top_pointer <0){
        fprintf(stderr, "Oopsie - seems like stack is empty\n");
        return 0;
    } else {
        return stack->array_pointer[stack->top_pointer];
    }
}

void stack_check(Stack *stack){
    if((stack->size >> 1) < stack->top_pointer){
        realloc_stack(stack, stack->size << 1);
    }
}

void realloc_stack(Stack *stack, int newsize){
    stack->array_pointer = realloc(stack->array_pointer, newsize * sizeof(void*));
    if(stack->array_pointer == NULL){
        fprintf(stderr, "Oopsie - seems like reallocation finished with death\n");
    } else {
        stack->size = newsize;
    }

}
