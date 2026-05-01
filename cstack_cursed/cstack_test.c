#include "cstack.h"
#include <stdio.h>


int main() {

    Stack st1;
    stack_init(&st1);

    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;
    int num6 = 6;
    int num7 = 7;
    int num8 = 8;
    int num9 = 9;
    void* ptr1 = &num1;
    void* ptr2 = &num2;
    void* ptr3 = &num3;
    void* ptr4 = &num4;
    void* ptr5 = &num5;
    void* ptr6 = &num6;
    void* ptr7 = &num7;
    void* ptr8 = &num8;
    void* ptr9 = &num9;

    void* checker;
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

    printf("Inputed elements\n");
    /*for (int i = 0; i < 24; i++){
        int tmp = i;
        printf("%d | ", i);
        stack_push(&st1, &tmp);
        }*/
    stack_push(&st1, ptr1);
    stack_push(&st1, ptr2);
    stack_push(&st1, ptr3);
    stack_push(&st1, ptr4);
    stack_push(&st1, ptr5);
    stack_push(&st1, ptr6);
    stack_push(&st1, ptr7);
    stack_push(&st1, ptr8);
    stack_push(&st1, ptr9);
    printf("Outputed elements:\n");
    for (int i = 0; i < 9; i++){
        void* element = stack_pop(&st1);
        printf("%d | ", *((int*) element));
    }



    return 0;
}
