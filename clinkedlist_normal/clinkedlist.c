#include "clinkedlist.h"
#include <stdlib.h>



void linked_list_init(LinkedList *linked_list){
    linked_list->size = 0;
    linked_list->start_node = 0;
}

void linked_list_push(LinkedList *linked_list, long element){
    Node new_node = {element,
        linked_list->start_node,
        linked_list->start_node->previous_node
    };
    linked_list->start_node->previous_node->next_node = &new_node;
    linked_list->start_node->previous_node = &new_node;
    linked_list->start_node = &new_node;
    linked_list->size++;
}

void linked_list_append(LinkedList *linked_list, long element){
    Node new_node = {element,
        linked_list->start_node,
        linked_list->start_node->previous_node};
    linked_list->start_node->previous_node->next_node = &new_node;
    linked_list->start_node->previous_node = &new_node;
    linked_list->size++;
}

void linked_list_replace(LinkedList *linked_list, long element, int index){
    if((linked_list->size)/2 - index >= 0){
        Node* needed_node = linked_list->start_node;
        for (int i = 0; i < index; i++){
            needed_node = needed_node->next_node;
        }
        needed_node->data = element;
    } else {
        Node* needed_node=linked_list->start_node->previous_node;
        for(int i = 0; i < (linked_list->size - index); i++){
            needed_node = needed_node->previous_node;
        }
        needed_node->data = element;
    }
}
void linked_list_insert(LinkedList *linked_list, long element, int index){
    Node new_node = {element};
    if((linked_list->size)/2 - index >= 0){
        Node* needed_node = linked_list->start_node;
        for (int i = 0; i < index; i++){
            needed_node = needed_node->next_node;
        }
        Node* prev_node = needed_node->previous_node;
        prev_node->next_node = &new_node;
        new_node.previous_node = prev_node;
        new_node.next_node = needed_node;
        needed_node->previous_node = &new_node;
    } else {
        Node* needed_node=linked_list->start_node->previous_node;
        for(int i = 0; i < (linked_list->size - index); i++){
            needed_node = needed_node->previous_node;
        }
        Node* prev_node = needed_node->previous_node;
        prev_node->next_node = &new_node;
        new_node.previous_node = prev_node;
        new_node.next_node = needed_node;
        needed_node->previous_node = &new_node;
    }
}


long linked_list_pop_start(LinkedList *linked_list){
    Node* new_start = linked_list->start_node->next_node;
    linked_list->start_node->previous_node->next_node = linked_list->start_node->next_node;
    linked_list->start_node->next_node->previous_node = linked_list->start_node->previous_node;
    long return_value = linked_list->start_node->data;
    free(linked_list->start_node);
    linked_list->start_node = new_start;
    return return_value;
}


long linked_list_pop_end(LinkedList *linked_list){
    Node* new_end = linked_list->start_node->previous_node->previous_node;
    long return_value = linked_list->start_node->previous_node->data;
    free(linked_list->start_node->previous_node);
    linked_list->start_node->previous_node = new_end;
    new_end->next_node = linked_list->start_node;
    return return_value;
}

long linked_list_delete(LinkedList *linked_list, int index){
    if((linked_list->size)/2 - index >= 0){
        Node* needed_node = linked_list->start_node;
        for (int i = 0; i < index; i++){
            needed_node = needed_node->next_node;
        }
        needed_node->previous_node->next_node = needed_node->next_node;
        needed_node->next_node->previous_node = needed_node->previous_node;
        long return_value = needed_node->data;
        free(needed_node);
        return return_value;
    } else {
        Node* needed_node=linked_list->start_node->previous_node;
        for(int i = 0; i < (linked_list->size - index); i++){
            needed_node = needed_node->previous_node;
        }
        needed_node->previous_node->next_node = needed_node->next_node;
        needed_node->next_node->previous_node = needed_node->previous_node;
        long return_value = needed_node->data;
        free(needed_node);
        return return_value;
    }
}

//long linked_list_sort()
