#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int main(int argc, char *argv[])
{
    // Try out your code as you're building it here.
    // If you just run "make" in this directory, it
    // will compile this file and make an executable
    // called "main".

    // When you've got most of the functions in place,
    // try compiling the tests with "make test" and
    // running them via the executable called "test".

    node *head = node_make(1);
    list_insert(list_insert(list_insert(head, 5), 7), 3);

    list_print(head);

    list_remove(head->next->next);
    list_print(head);

    return 0;
}