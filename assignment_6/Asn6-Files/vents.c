#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "vents.h"


/*
 * Given a vent name, find it's respective index value
 * 
 * @param vents    A pointer to an array of linked lists.
 * @param city     A string containing a vent name. 
 * @return         Index value of source_vent in vents, or
 *                 -1 if source_vent does not exist in vents.
 */
int find_index(List **vents, int num_vents, char *source_vent) {
    int idx;
    for (idx = 0; idx < num_vents; ++idx) {
        if (vents[idx]->head->data != NULL &&
            (strcmp(vents[idx]->head->data, source_vent) == 0)) {
            return idx;
            }
    }
    return 1;
}

/*
 * Given a file name, save all of the data from that file to an array
 * of linked lists.  
 * 
 * @param filename          A pointer to a file that is opened for reading. 
 * @param vent_locaitons    A pointer to an array of linked lists.
 * @return                  0 on success.
 *                          -1 on failure.
 */
int read_file (char *filename, List **vent_locations) {
    int num_vents, num_vent_connections;
    char src[MAX_VENT_NAME_LENGTH], dst[MAX_VENT_NAME_LENGTH];

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("ERROR: read_file(): Unable to open %s.\n", filename);
        return 1;
    }

    /* 
     * Get the first line in the format:  
     *      <NUMBER OF VENTS> <NUMBER OF PAIRS>  
     */
    fscanf(fp, "%d %d", &num_vents, &num_vent_connections);

    /* 
     * Loop through the next <NUMBER OF VENTS> lines in file to get
     * unique vents 
     */
    for (int i = 0; i < num_vents; ++i) {
        fscanf(fp, "%s", src);
        Node *sNode = create_node(src);
        if (sNode == NULL) {
            printf("ERROR: read_file(): create_node() failed to create a new "
                   "node for src vent.\n");
            return 1;
        } 

        add_end(vent_locations[i], sNode);
        vent_locations[i]->count++;
    }

    /* 
     * Loop through the next <NUMBER OF UNIQUE CITIES> lines in file to get
     * the src/dst pairs read in the format:
     *      <SRC> <DST> 
     */
    for (int i = 0; i < num_vent_connections; ++i) {
        fscanf(fp, "%s | %s", src, dst);
        int src_idx = find_index(vent_locations, num_vents, src);
        if (src_idx < 0) {
            printf("ERROR: read_file(): Can't find index for %s.", src);
            return 1;
        }
        Node *dNode = create_node(dst);
        if (dNode == NULL) {
            printf("ERROR: read_file(): create_node() failed to create a new "
                   "node for dst vent.\n");
            return 1;
        }
        add_end(vent_locations[src_idx], dNode);

        int dst_idx = find_index(vent_locations, num_vents, dst);
        if (dst_idx < 0) {
            printf("ERROR: read_file(): Can't find index for %s.", dst);
            return 1;
        }
        Node *sNode = create_node(src);
        if (sNode == NULL) {
            printf("ERROR: read_file(): create_node() failed to create a new "
                   "node for dst vent.\n");
            return 1;
        }
        add_end(vent_locations[dst_idx], sNode);
    }

    return 0;
}

/*
 * Print only the first node in every linked list in a given array
 * @param array         A pointer to an array of linked lists
 * @param num_vents     The number of vents that can be stored in the array
 */
void print_vent_locations (List **array, int num_vents) {
    for (int i = 0; i < num_vents; ++i) {
        if (array[i]->head != NULL) {
            printf("%s\n", array[i]->head->data);
        }
    }
}

/*
 * Given a destination vent name, print all vents that can it can be reached by
 * @param array         A pointer to an array of linked lists
 * @param num_vents     The number of vents that can be stored in the array
 * @param name          The name of the vent 
 */
void print_possible_starting_vents (List **array, int num_vents, char *name) {
    for (int i = 0; i < num_vents; ++i) {
        Node *node = array[i]->head;

        /* Check to make sure the node actually exists in memory */
        if (node == NULL) {
            printf("Vent not found, check spelling.\n");
            return;
        }

        if (strcmp(node->data, name) == 0) {
            printf ("You can get to %s from: \n", node->data);
            node = node->next;  // skip over head node
            for (int j = 0; j < array[i]->count-1; ++j) {
                if (node == NULL) {
                    return;
                }

                printf("%s, ", node->data);
                if (node->next == NULL) {
                    return;
                }
                node = node->next;
            }
            printf("\n");
        }
    }
}

int main () {
    int err;
    char *map, *search;
    map = (char*) malloc(sizeof(char) * 5);
    printf ("Which map are you using?  [Skeld, Polus, Mira]\n");
    scanf ("%s", map);

    List *vent_locations[MAX_NUM_VENTS];
    for (int i = 0; i < MAX_NUM_VENTS; ++i) {
        vent_locations[i] = (List*) malloc(sizeof(List));
        vent_locations[i]->head = NULL;
        vent_locations[i]->count = 0;
    }

    if (strcmp (map, "Skeld") == 0) {
        printf ("Loading vent connections for SKELD map...\n");
        err = read_file ("skeld.txt", vent_locations);
    } else if (strcmp (map, "Polus") == 0) {
        printf ("Loading vent connections for POLUS map...\n");
        err = read_file ("polus.txt", vent_locations);
    } else if (strcmp (map, "Mira") == 0) {
        printf ("Loading vent connections for MIRA map...\n");
        err = read_file ("mira.txt", vent_locations);
    } else {
        printf ("Invalid input, check spelling.\n");
        printf ("Closing program.\n");
        return 1;
    }

    if (err == 1) {
        return 1;
    }

    printf ("Here is a list of all possible vents:\n");
    print_vent_locations (vent_locations, MAX_NUM_VENTS);

    search = (char*) malloc(sizeof(char) * MAX_VENT_NAME_LENGTH);
    printf ("Which vent are you looking to go to?\n");
    scanf ("%s", search);

    print_possible_starting_vents (vent_locations, MAX_NUM_VENTS, search);

    for (int i = 0; i < MAX_NUM_VENTS; ++i) {
        destroy_list (vent_locations[i]);
    }

    return 0;
}