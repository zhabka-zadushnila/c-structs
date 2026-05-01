#include "cqueue.h"
#include <stdio.h>


int main() {

    Queue q1;
    queue_init(&q1);

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
    // passed
    printf("Test1 started\n");
    checker = queue_peek(&q1);
    if(checker != NULL){
        printf("That's a num from  %d\n", *(int*)checker);
    }

    //stoopid test2
    //  passed
    printf("\nTest2 started\n");
    printf("Size: %d\n",q1.size);
    queue_push(&q1, ptr1);
    printf("Element pushed\n");
    printf("Size: %d\n",q1.size);
    checker = queue_peek(&q1);

    printf("That's a num from queue: %d\n", * (int*)checker);

    printf("Element_popped\n");
    checker = queue_pop(&q1);
    printf("Size: %d\n",q1.size);
    printf("That's a num from queue: %d\n", * (int*)checker);
    //stoopid test3
    printf("\nTest3 started\n");
    queue_push(&q1, ptr1);
    queue_push(&q1, ptr2);
    queue_push(&q1, ptr3);
    queue_push(&q1, ptr4);
    queue_push(&q1, ptr5);
    queue_push(&q1, ptr6);
    queue_push(&q1, ptr7);
    queue_push(&q1, ptr8);
    queue_push(&q1, ptr9);
    printf("Inputed elements\n");
    printf("Size: %d\n",q1.size);
    printf("Outputed elements:\n");
    for (int i = 0; i < 9; i++){
        void* element = queue_pop(&q1);
        printf("%d | ", *(int*) element);
    }

    // stoopid test4
    printf("\nTest4 started\n");
    queue_kill(&q1);

    return 0;
}
