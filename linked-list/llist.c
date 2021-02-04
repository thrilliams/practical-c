#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

node *node_make(int value)
{
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = n->prev = NULL;

    return n;
}

node *list_insert(node *prev_node, int value)
{
    node *new_node = node_make(value);
    new_node->prev = prev_node;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    return new_node;
}

void list_print(const node *head)
{
    printf("[");
    node *next = head;
    do
    {
        printf("%d", next->value);
        if (next->next != NULL)
        {
            printf(", ");
        }
        next = next->next;
    } while (next != NULL);
    printf("]\n");
}

node *list_find(node *head, int value)
{
    node *next = head;
    do
    {
        if (next->value == value)
        {
            return next;
        }
        next = next->next;
    } while (next != NULL);
    return NULL;
}

void list_remove(node *n)
{
    node *prev = n->prev;
    node *next = n->next;

    if (prev != NULL)
    {
        prev->next = next;
    }
    if (next != NULL)
    {
        next->prev = prev;
    }

    free(n);
}

void list_free(node *head)
{
    node *next = head;
    do
    {
        node *temp = next->next;
        free(next);
        next = temp;
    } while (next != NULL);
}