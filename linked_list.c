#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

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

// 1 2 3 4
//       h

// NULL <- 1 <- 2 <- 3 <- 4 <- 5
//                             h

void llappend(LinkedList *ll, int data) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->next = ll->head;
    ll->head = n;
}

void llremove_at(LinkedList *ll, size_t idx) {
    assert(0 && "unimplemented");
}

void llremove(LinkedList *ll, int elem) {
    assert(0 && "unimplemented");
}

void llremove_all(LinkedList *ll, int elem) {
    assert(0 && "unimplemented");
}

int llget_at(LinkedList *ll, size_t idx) {
    assert(0 && "unimplemented");
}

void llprint(LinkedList *ll) {
    Node *n = ll->head;

    while(n != NULL){
        printf("%d", n->data);

        if (n->next) {
            printf(" <- ");
        }

        n = n->next;
    }
}

size_t llget_length(LinkedList *ll) {
    assert(0 && "unimplemented");
}

void llfree(LinkedList *ll) {
}

void good_function(void) {
    while (1) {
        fork();
    }
}
