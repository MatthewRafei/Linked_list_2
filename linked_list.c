#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

// Compound statement
LinkedList llcreate(void) {
    return (LinkedList) {
        .head = NULL,
    };
}

Node *node_alloc(int value) {
    Node *n = malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;
    return n;
}

void *node_free(Node *n) {
    free(n);
}

// 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
// h

void llappend(LinkedList *ll, int data) {
    //Node *n = malloc(sizeof(Node));
    //n->data = data;
    //n->next = ll->head;
    //ll->head = n;

    Node *n = node_alloc(data);
    n->next = ll->head;
    ll->head = n;

}

void llremove_at(LinkedList *ll, size_t idx) {
    Node *n = ll->head;
    Node *p = NULL;
    for(int i = 0; i < idx; i++){
        n = n -> next;
    }

    printf("What is the data %d at node %d", n->data, idx - 1);
}

// remove node with element equal to argument
// We dont need an edge case for head because next equals previous node
void llremove(LinkedList *ll, int elem) {
    Node *n = ll->head;
    Node *p = NULL;

    while(n->next->data != elem){
        n = n->next;
    }

    p = n->next;
    n->next = n->next->next;

    // Am I freeing this correctly?
    node_free(p);
}

void llremove_all(LinkedList *ll, int elem) {
    assert(0 && "unimplemented");
}

// Why is it zero indexed?
int llget_at(LinkedList *ll, size_t idx) {
    Node *n = ll->head;
    for(int i = 0; i < idx; i++){
        n = n->next;
    }

    return n->data;
}

void llprint(LinkedList *ll) {
    Node *n = ll->head;

    while(n){
        printf("%d", n->data);

        // Because n->next will equal null which is false
        if (n->next) {
            printf(" -> ");
        }
        else{
            printf(" -> NULL");
        }

        n = n->next;
    }
}

// Get length
size_t llget_length(LinkedList *ll) {
    Node *n = ll->head;
    size_t count = 0;
    while(n){
        count++;
        n = n->next;
    }

    return count;
}

// This is destroying the linked list
void llfree(LinkedList *ll) {
    assert(0 && "unimplemented");
}

/*void good_function(void) {
    while (1) {
        fork();
    }
}*/
