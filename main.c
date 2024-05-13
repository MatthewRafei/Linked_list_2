#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main(void) {
    LinkedList ll = llcreate();
    llappend(&ll, 1);
    llappend(&ll, 2);
    llappend(&ll, 3);
    llappend(&ll, 4);
    llappend(&ll, 5);
    llappend(&ll, 6);
    llappend(&ll, 7);

    llprint(&ll);

    printf("The length of the linked list %d\n", llget_length(&ll));

    int index = 6;

    printf("Value at index %d in Linked list is %d\n", index, llget_at(&ll, index));

    printf("The head is %d\n", ll.head->data);

    llremove(&ll, 5);

    llprint(&ll);

    printf("Node 0's next is equal to %d\n", ll.head->data);

    //llget_at(&ll, 0);

    // Does this segfault because 0 is equal to null?
    llremove_at(&ll, 0);

    llremove_at(&ll, 2);

    llprint(&ll);

    llappend(&ll, 1);

    llremove_all(&ll, 1);

    llprint(&ll);

    //good_function();

    return 0;
}
