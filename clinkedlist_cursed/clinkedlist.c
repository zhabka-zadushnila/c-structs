#include "clinkedlist.h"
#include <stdio.h>
#include <stdlib.h>


Node* split(Node* head);
Node* merge_nodes(Node* head_first, Node* head_second, int (*cmpPointer(void*, void*)));

void linked_list_init(LinkedList *linked_list){
    linked_list->size = 0;
}

void linked_list_push(LinkedList *linked_list, void* element){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = element;
    if(linked_list->size == 0){
        new_node->next_node = new_node;
        new_node->previous_node = new_node;
        linked_list->start_node = new_node;
    }else{
        new_node->next_node = linked_list->start_node;
        new_node->previous_node = linked_list->start_node->previous_node;
        linked_list->start_node->previous_node->next_node = new_node;
        linked_list->start_node->previous_node = new_node;
    }
    linked_list->size++;
}

void linked_list_append(LinkedList *linked_list, void* element){
    Node new_node = {element,
        linked_list->start_node,
        linked_list->start_node->previous_node};
    linked_list->start_node->previous_node->next_node = &new_node;
    linked_list->start_node->previous_node = &new_node;
    linked_list->size++;
}

void linked_list_replace(LinkedList *linked_list, void* element, int index){
    if(linked_list->size == 0){
        printf("Oopsie!");
        return;
    }else{
        if(index >= linked_list->size){
            printf("Oopsie! Out of bounds");
            return;
        }else{
            if((linked_list->size)/2 - index >= 0){
                Node* needed_node = linked_list->start_node;
                for (int i = 0; i < index; i++){
                    needed_node = needed_node->next_node;
                }
                needed_node->data = element;
            } else {
                Node* needed_node=linked_list->start_node->previous_node;
                for(int i = 0; i < (linked_list->size - index -1); i++){
                    needed_node = needed_node->previous_node;
                }
                needed_node->data = element;
            }
        }
    }
}
void linked_list_insert(LinkedList *linked_list, void* element, int index){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data=element;
    if(linked_list->size == 0){
        if(index != 0){
            printf("Oopsie!");
            return;
        }else{
            linked_list_push(linked_list, element);
        }
    }else{
        if(index > linked_list->size){
            printf("Oopsie! Out of bounds");
            return;
        }else{
            if((linked_list->size)/2 - index >= 0){
                Node* needed_node = linked_list->start_node;
                for (int i = 0; i < index; i++){
                    needed_node = needed_node->next_node;
                }
                Node* prev_node = needed_node->previous_node;
                prev_node->next_node = new_node;
                new_node->previous_node = prev_node;
                new_node->next_node = needed_node;
                needed_node->previous_node = new_node;
            } else {
                Node* needed_node=linked_list->start_node->previous_node;
                for(int i = 0; i < (linked_list->size - index -1); i++){
                    needed_node = needed_node->previous_node;
                }
                Node* prev_node = needed_node->previous_node;
                prev_node->next_node = new_node;
                new_node->previous_node = prev_node;
                new_node->next_node = needed_node;
                needed_node->previous_node = new_node;
            }
            linked_list->size++;
        }
    }
}


void* linked_list_pop_start(LinkedList *linked_list){
    if(linked_list->size==0){
        printf("bruh");
        return NULL;
    }
    Node* new_start = linked_list->start_node->next_node;
    linked_list->start_node->previous_node->next_node = linked_list->start_node->next_node;
    linked_list->start_node->next_node->previous_node = linked_list->start_node->previous_node;
    void* return_value = linked_list->start_node->data;
    free(linked_list->start_node);
    linked_list->start_node = new_start;
    linked_list->size--;
    return return_value;
}


void* linked_list_pop_end(LinkedList *linked_list){
    if(linked_list->size==0){
        printf("bruh");
        return NULL;
    }
    Node* new_end = linked_list->start_node->previous_node->previous_node;
    void* return_value = linked_list->start_node->previous_node->data;
    free(linked_list->start_node->previous_node);
    linked_list->start_node->previous_node = new_end;
    new_end->next_node = linked_list->start_node;
    linked_list->size--;
    return return_value;
}

void* linked_list_delete(LinkedList *linked_list, int index){
    if((linked_list->size)/2 - index >= 0){
        Node* needed_node = linked_list->start_node;
        for (int i = 0; i < index; i++){
            needed_node = needed_node->next_node;
        }
        if(needed_node == linked_list->start_node){
            linked_list->start_node->previous_node->next_node = linked_list->start_node->next_node;
            linked_list->start_node->next_node->previous_node = linked_list->start_node->previous_node;
            linked_list->start_node = linked_list->start_node->next_node;
        }else{
            needed_node->previous_node->next_node = needed_node->next_node;
            needed_node->next_node->previous_node = needed_node->previous_node;
        }
        void* return_value = needed_node->data;
        free(needed_node);
        return return_value;
    } else {
        Node* needed_node=linked_list->start_node->previous_node;
        for(int i = 0; i < (linked_list->size - index-1); i++){
            needed_node = needed_node->previous_node;
        }
        needed_node->previous_node->next_node = needed_node->next_node;
        needed_node->next_node->previous_node = needed_node->previous_node;
        void* return_value = needed_node->data;
        free(needed_node);
        return return_value;
    }// prev_node->head_1 ==> //

}

void linked_list_sort(LinkedList* linked_list, int (*cmpPointer)(void*, void*)){
}


Node* sort_nodes(Node* start_node, int (*cmpPointer(void*, void*))){


    if(start_node->previous_node == start_node){
        return start_node;
    }

    if(start_node->previous_node->previous_node == start_node){
        int cmp_result = *cmpPointer(start_node->data, start_node->previous_node->data);
        if (cmp_result > 0){
            void* temp = start_node->data;
            start_node->data = start_node->previous_node->data;
            start_node->previous_node->data = temp;
        }
    }

    Node* second_node = split(start_node);
    sort_nodes(start_node, cmpPointer);
    sort_nodes(second_node, cmpPointer);

    Node* result = merge_nodes(start_node, second_node, *cmpPointer);

    return result;
}


Node* split(Node* head){
    Node* stop_node = head -> previous_node;
    Node* slow = head;
    Node* fast = head;

    while (fast != stop_node && fast->next_node != stop_node) {
        fast = fast->next_node->next_node;
        if(fast != stop_node || fast != head){
            slow=slow->next_node;
        }
    }
    head->previous_node = slow;
    slow->previous_node = stop_node;
    return slow;

}

// prev_node->head_1 ==> //
Node* merge_nodes(Node* head_first, Node* head_second, int (*cmpPointer(void*, void*))) {
    Node* last = head_second;
    while (head_first != last){
        int cmp_result = *cmpPointer(head_first, head_second);
        if (cmp_result > 0){
            Node* temp = head_first;
            //head_first->
        }
    }
    return head_first;
}
