// clinkedlist.h

#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

typedef struct Node {
    void* data;
    struct Node* next_node;
    struct Node* previous_node;
} Node;

typedef struct LinkedList {
    int size;
    struct Node* start_node;
} LinkedList;
//
// Аллокация списка;
void linked_list_init(LinkedList* linked_list);
// Деаллокация списка;
void linked_list_kill(LinkedList *linked_list);
// Вставка элемента в начало массива;
void linked_list_push(LinkedList *linked_list, void* element);
// Вставка элемента в конец массива;
void linked_list_append(LinkedList* linked_list, void* element);
// replace added
void linked_list_replace(LinkedList* linked_list, void* element, int index);
// Вставка элемента в массив по индексу;
void linked_list_insert(LinkedList* linked_list, void* element, int index);
// Удаление элемента с начала массива;
void* linked_list_pop_start(LinkedList* linked_list);
// Удаление элемента с конца массива;
void* linked_list_pop_end(LinkedList* linked_list);
// Удаление элемента в массиве по индексу;
void* linked_list_delete(LinkedList* linked_list, int index);
// Сортировка массива с указанием функции-компаратора.
void linked_list_sort(LinkedList* linked_list, int (*cmpPointer)(void*, void*));





#endif
