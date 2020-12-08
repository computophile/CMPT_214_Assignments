#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

/*
 * Initializes and returns an empty List data structure
 * @return an empty List data structure
 */
List *create_list (void) {
    List *new_list = (List*) malloc(sizeof(List) * MAX_NUM_CONNECTIONS);
    new_list->head = (Node*) malloc(sizeof(Node));
    new_list->head = NULL;
    new_list->count = 0;

    return new_list;
}

/*
 * Initializes and returns a Node data structure with the data set
 * @param data    Value to be stored to the Node data structure
 * @return an initalized Node data structure
 */
Node *create_node (char *data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = (char*) malloc(sizeof(strlen(data)));
    strcpy(new_node->data, data);

    return new_node;
}

/*
 * Deallocates a linked list
 * @list    The link list to be allocated
 */
void destroy_list (List *list) {
    if (list->head == NULL)
        return;

    Node *node = list->head; 
    for (int i = 0; i < list->count; ++i) {
        Node *temp = node->next;
        free(node->data);
        free(node);
        node = temp;
        list->count--;
    }
    free (list);
}
