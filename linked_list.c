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

    if(idx == 0){
        n = ll->head;
        ll->head = ll->head->next;
        node_free(n);
        return;
    }

    for(int i = 0; i < idx - 1; i++){
        n = n -> next;
    }

    p = n->next;
    n->next = n->next->next;
    node_free(p);
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

// Remove duplicate elements? A linked list is supposed to be unique?
void llremove_all(LinkedList *ll, int elem) {
    Node *n = ll->head;
    Node *p = NULL;
    size_t count = llget_length(ll);

    printf("The length is %d\n", count);

    
    // This doesn't work because we need to link the previous node to the next next node
    for(int i = 0; i < count; i++){
        if(n->data == elem){
            //p = n;
            // P:N:1 = P:N:6?
            // n = n->next;
            //node_free(p);
        }
    }
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
            printf(" -> NULL\n");
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
    Node *n = NULL;
    Node *p = NULL;
    
    while(n != NULL){
        p = n;
        n = n->next;
        node_free(p);
    }
}

/*void good_function(void) {
    while (1) {
        fork();
    }
}*/