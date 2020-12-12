/*
# Name: Mohammed Thamidur Rashid
# Class: CMPT-214
# Student Number: 11280257
*/
#ifndef __statsdb_h__
#define __statsdb_h__
#include "statsdb.h"
#endif // !1

typedef struct encounter
{
  char **desc_name;// array of char pointers of length 1
  short int encounterCount;
  char **encounterNames;
  short int challengeRating;
} Encounter;

Encounter *generate_random_encounter(Creature *creatures, char encounterName[100], short int c, short int challenge_rating_threshold);
void print_encounter(Creature *creatures, Encounter *encounter);
void destroy_encounter(Encounter *encounter, int c);