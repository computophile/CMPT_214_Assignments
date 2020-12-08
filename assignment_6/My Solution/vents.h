#ifndef VENTS_H
#define VENTS_H

#define MAX_VENT_NAME_LENGTH 25
#define MAX_NUM_VENTS 14

/*
 * Given a vent name, find it's respective index value
 * 
 * @param vents    A pointer to an array of linked lists.
 * @param city     A string containing a vent name. 
 * @return         Index value of source_vent in vents, or
 *                 -1 if source_vent does not exist in vents.
 */
int find_index(List **array, int num_vents, char *source_vent);

/*
 * Given a file name, save all of the data from that file to an array
 * of linked lists.  
 * 
 * @param filename    A pointer to a file that is opened for reading.
 * @param vent_locaitons    A pointer to an array of linked lists. 
 * @return            A pointer to an array of linked lists.
 */
int read_file (char *filename, List **array);

/*
 * Print only the first node in every linked list in a given array
 * @param array         A pointer to an array of linked lists
 * @param num_vents     The number of vents that can be stored in the array
 */
void print_vent_locations (List **array, int num_vents);

/*
 * Given a destination vent name, print all vents that can it can be reached by
 * @param array         A pointer to an array of linked lists
 * @param num_vents     The number of vents that can be stored in the array
 * @param name          The name of the vent 
 */
void print_possible_starting_vents (List **array, int num_vents, char *value);

#endif // VENTS_H