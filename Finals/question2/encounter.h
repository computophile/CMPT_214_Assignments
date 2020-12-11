#ifndef __statsdb_h__
#define __statsdb_h__
#include "statsdb.h"
#endif // !1

typedef struct encounter
{
  char **desc_name;
  short int encounterCount;
  char **encounterNames;
  short int challengeRating;
} Encounter;


Encounter *generate_random_encounter(Creature *creatures, char encounterName[100], short int c, short int challenge_rating_threshold);

void print_encounter(Creature *creatures, Encounter *encounter);
void destroy_encounter(Encounter *encounter, int c);