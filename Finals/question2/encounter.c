/*
# Name: Mohammed Thamidur Rashid
# Class: CMPT-214
# Student Number: 11280257
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "randomindex.h"
#include "encounter.h"

Encounter *generate_random_encounter(Creature *creatures, char encounterName[100], short int c, short int challenge_rating_threshold)
{
  /*
  Function: to genrate random encounters
  Parameters: creatures: A pointer to a creature database containing monsters.
              encounterName: A descriptive name for the encounter (string).
              c: A positive integer indicating c the maximum number of creatures to add to the encounter.
              challenge_rating_threshold: A positive integer called the challenge rating threshold.
  */
  Encounter *encounter = (Encounter *)malloc(sizeof(Encounter));
  encounter->desc_name = malloc(sizeof(char *));                           // allocating  array of char pointers of length 1
  *(encounter->desc_name) = strndup(encounterName, strlen(encounterName)); //only allocating required bytes
  encounter->encounterCount = c;
  encounter->encounterNames = malloc(c * sizeof(char *)); // allocating array of char pointers of length c for c number of monsters
  encounter->challengeRating = 0;
  
  for (short int i = 0; i < c; i++)
  {
    Creature selectedCreature = creatures[random_index(numberOfCreatures)]; //randomly selecting monster with randomindex module
    if (encounter->challengeRating < challenge_rating_threshold)            //checking the threshold
    {
      encounter->encounterNames[i] = strndup(selectedCreature.name[0], strlen(selectedCreature.name[0])); //only allocating required bytes
      encounter->challengeRating = encounter->challengeRating + selectedCreature.challengeRating;
    }
    else
    {
      encounter->encounterCount = i;
      return encounter;
    }
  }
  return encounter;
}

void print_encounter(Creature *creatures, Encounter *encounter)
{
  /*
  Function that prints the
  descriptive name of the encounter followed by a numbered list of monsters in the encounter
  and their statistics in an aesthetically pleasing manner
  Parameter: encoutner: pointer to an encounter,
             creatures: a pointer to the database of the creature;
  */
  printf("%s Encounter:\n", encounter->desc_name[0]);
  for (int i = 0; i < encounter->encounterCount; i++)
  {
    printf("Monster #%d: ", i + 1);
    CreatureStats *stats = get_creature(creatures, encounter->encounterNames[i], numberOfCreatures);
    print_creature_stats(stats);
  }
  printf("Total challenge rating: %hd\n", encounter->challengeRating);
}

void destroy_encounter(Encounter *encounter, int c)
{
  /*
  Function to free the data that has been allocated throught out the running of the encounter database
  */
  for (short int i = 0; i < c; i++)
  {
    free(encounter->encounterNames[i]);
  }
  free(*(encounter->desc_name));
  free(encounter->desc_name);
  free(encounter->encounterNames);
  free(encounter);
}