#include "cstack.h"
#include <stdio.h>


int main() {

    Stack st1;
    stack_init(&st1);

    int num = 12;
    void *checker;
    //stoopid test1
    /* passed
    checker = stack_peek(&st1);

    printf("That's a num from  %d\n", *((int*)checker));
    */

    //stoopid test2
    /* passed
    stack_push(&st1, &num);
    checker = stack_peek(&st1);

    printf("That's a num from  %d\n", *((int*)checker));
    //outputs 12
    num++;

    checker = stack_peek(&st1);

    printf("That's a num from  %d\n", *((int*)checker));
    //outputs 13 (pretty obvious)
    */

    //stoopid test3

    printf("Inputed elements:\n");
    for (int i = 0; i < 24; i++){
        printf("%d | %d\n ", i, st1.size);
        stack_push(&st1, i);
    }
    printf("\nOutputed elements:\n");
    for (int i = 0; i < 24; i++){
        long element = stack_pop(&st1);
        printf("%ld | %d\n ", element, st1.size);
    }



    return 0;
}
