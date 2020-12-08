#ifndef LIST_H
#define LIST_H

#define MAX_NUM_CONNECTIONS 4

typedef struct _node {
    struct _node *next;
    char *data;
} Node;

typedef struct _list {
    Node *head;
    int count;
} List;

/*
 * Initializes and returns an empty List data structure
 * @return an empty List data structure
 */
List *create_list (void);

/*
 * Initializes and returns a Node data structure with the data set
 * @param data    Value to be stored to the Node data structure
 * @return an initalized Node data structure
 */
Node *create_node (char *data);

/*
 * Deallocates a linked list
 * @list    The link list to be allocated
 */
void destroy_list (List *list);

/*
 * Adds a node to the end of the linked list
 * @param list  A linked list of nodes
 * @param node  A node to add to the linked list
 */
void add_end (List *list, Node *node);

#endif // LIST_H
