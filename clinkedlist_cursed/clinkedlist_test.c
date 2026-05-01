#include "clinkedlist.h"
#include <stdio.h>


int main() {

    LinkedList llst1;
    linked_list_init(&llst1);

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
    printf("Test1 (push):\n");
    linked_list_push(&llst1, ptr3);
    printf("# Passed #\n");


    printf("\nTest2 (pop_start):\n");
    checker = linked_list_pop_start(&llst1);
    printf("Res: %d\n", *(int*)checker);
    printf("# Passed #\n");

    printf("\nTest3 (pop_end):\n");
    linked_list_push(&llst1, ptr7);
    checker = linked_list_pop_end(&llst1);
    printf("Res: %d\n", *(int*)checker);
    printf("# Passed #\n");

    printf("\nTest4 (pop_empty):\n");
    checker = linked_list_pop_start(&llst1);
    if(checker == NULL){
        printf("# Passed #\n");
    }


    printf("\nTest5 (replace):\n");
    int num_test5 = 23;
    printf("%d\n", llst1.size);
    linked_list_push(&llst1, ptr1);
    linked_list_push(&llst1, ptr2);
    linked_list_push(&llst1, ptr3);
    linked_list_push(&llst1, ptr4);
    linked_list_push(&llst1, ptr5);
    linked_list_push(&llst1, ptr6);
    linked_list_push(&llst1, ptr7);
    linked_list_push(&llst1, ptr8);
    linked_list_push(&llst1, ptr9);
    printf("%d\n", llst1.size);

    linked_list_insert(&llst1, &num_test5, 9);
    printf("%d\n", llst1.size);
    printf("|");
    for(int i =0; i<10; i++){
        void* element = linked_list_pop_start(&llst1);
        printf("%d|", *(int*)element);
    }

    printf("\nTest6 (replace):\n");
    int num_test6 = 95;
    printf("%d\n", llst1.size);
    linked_list_push(&llst1, ptr1);
    linked_list_push(&llst1, ptr2);
    linked_list_push(&llst1, ptr3);
    linked_list_push(&llst1, ptr4);
    linked_list_push(&llst1, ptr5);
    linked_list_push(&llst1, ptr6);
    linked_list_push(&llst1, ptr7);
    linked_list_push(&llst1, ptr8);
    linked_list_push(&llst1, ptr9);
    printf("%d\n", llst1.size);
    linked_list_replace(&llst1, &num_test6, 9);
    printf("|");
    for(int i =0; i<9; i++){
        void* element = linked_list_pop_start(&llst1);
        printf("%d|", *(int*)element);
    }


    printf("\nTest7 (delete):\n");
    printf("%d\n", llst1.size);
    linked_list_push(&llst1, ptr1);
    linked_list_push(&llst1, ptr2);
    linked_list_push(&llst1, ptr3);
    linked_list_push(&llst1, ptr4);
    linked_list_push(&llst1, ptr5);
    linked_list_push(&llst1, ptr6);
    linked_list_push(&llst1, ptr7);
    linked_list_push(&llst1, ptr8);
    linked_list_push(&llst1, ptr9);
    printf("%d\n", llst1.size);
    linked_list_delete(&llst1, 6);
    printf("|");
    for(int i =0; i<8; i++){
        void* element = linked_list_pop_start(&llst1);
        printf("%d|", *(int*)element);
    }


    return 0;
}
