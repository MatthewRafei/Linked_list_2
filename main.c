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

    llprint(&ll);

    //good_function();

    return 0;
}
