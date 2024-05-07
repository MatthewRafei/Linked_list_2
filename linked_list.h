#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
} LinkedList;

// Non-heap vs heap
LinkedList llcreate(void);

void llappend(LinkedList *ll, int data);
void llremove_at(LinkedList *ll, size_t idx);
void llremove(LinkedList *ll, int elem);
void llremove_all(LinkedList *ll, int elem);
int llget_at(LinkedList *ll, size_t idx);
void llprint(LinkedList *ll);
size_t llget_length(LinkedList *ll);
void llfree(LinkedList *ll);
void good_function(void);
#endif // LINKED_LIST_H