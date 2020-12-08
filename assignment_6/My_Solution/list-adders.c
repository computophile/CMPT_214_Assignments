#include <stdlib.h>

#include "list.h"

/*
 * Adds a node to the end of the linked list
 * @param list  A linked list of nodes
 * @param node  A node to add to the linked list
 */
void add_end (List *list, Node *node) {
    if (list->count == 0) {
        list->head = node;
        list->count++;
        return;
    }

    Node *pNode = list->head;
    while (pNode->next != NULL) {
        pNode = pNode->next;
    }

    pNode->next = node;
    list->count++;
}
