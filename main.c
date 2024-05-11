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

    printf("\n");

    printf("The length of the linked list %d\n", llget_length(&ll));

    int index = 0;

    printf("Value at index %d in Linked list is %d\n", index, llget_at(&ll, index));

    printf("The head is %d\n", ll.head->data);

    llremove(&ll, 5);

    llprint(&ll);

    llremove(&ll, 0);

    //good_function();

    return 0;
}
