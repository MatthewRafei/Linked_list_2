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
    llappend(&ll, 1);

    llprint(&ll);

    llremove_all(&ll, 1);

    llprint(&ll);

    llfree(&ll);

    llprint(&ll);

    return 0;
}