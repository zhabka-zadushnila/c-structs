#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"
// использовать войды и движковую аллокацию!



void stack_init(Stack *stack){
    stack->size = 8;
    stack->top_pointer = -1;
    stack->array_pointer = calloc(stack->size, sizeof(void*));
}

void stack_kill(Stack *stack){
    for(int i = 0; i <= stack->top_pointer; i++){
        free(stack->array_pointer[i]);
    }
    free(stack->array_pointer);
    free(stack);
}
//size == 8 -> top_pointer == 7 -> stack full
void stack_push(Stack *stack, void* element){
    stack_check(stack);
    stack->array_pointer[++stack->top_pointer] = element;
}

void *stack_pop(Stack *stack){
    if(stack->top_pointer <0){
        fprintf(stderr, "Oopsie - seems like stack is empty\n");
        return NULL;
    } else {
        return stack->array_pointer[stack->top_pointer--];
    }
}

void *stack_peek(Stack *stack){
    if(stack->top_pointer <0){
        fprintf(stderr, "Oopsie - seems like stack is empty\n");
        return NULL;
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
