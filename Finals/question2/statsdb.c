/*
# Name: Mohammed Thamidur Rashid
# Class: CMPT-214
# Student Number: 11280257
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "statsdb.h"

Creature *create_stats_db(char FILENAME[20])
{
  /*
  Function: create_stats_db: Reads data from a file to create monster database
  Parameters: FILENAME: the name of a file containing creature statistics data
  Returns: returns a pointer to a creature database;
  */
  FILE *fp = NULL;
  fp = fopen(FILENAME, "r");
  short int n;
  Creature *creatures;
  if (fp != NULL)
  {
    fscanf(fp, "%hd", &n);
    numberOfCreatures = n;
    creatures = (Creature *)malloc(sizeof(Creature) * n);
    for (int i = 0; i < n; i++)
    {
      char name[100]; //max characters that a monster name would hold;
      fscanf(fp, "%s %hd %hd %hd %hd", name, &creatures[i].initiativeRating, &creatures[i].armourRating, &creatures[i].attackRating, &creatures[i].challengeRating);
      short int monsterNameLength = strlen(name);
      creatures[i].name[0] = strndup(name, monsterNameLength); //saving space while allocation.
    }
    fclose(fp);
  }
  else
  {
    printf("File Error!");
    exit(100);
  }
  return creatures;
}

void destroy_stats_db(Creature *creatures, int n)
{
  /*
  Function: destroy_stats_db: de-allocates any and all dynamically allocated
  Parameters: *creatures: a pointer to a creature database as a parameter
  */
  for (short int i = 0; i < n; i++)
  {
    free(creatures[i].name[0]);
  }
  free(creatures);
}

CreatureStats *get_creature(Creature *creatures, char name[100], short int numberOfCreatures)
{
  /*
  Function: get_creature: Creates creature statistics for the named creature
  Parameters: *creatures: a pointer to a creature database as a parameter
              name: the name of the creature to match
              numberofcreatures: the number of creatures in the monster database;
  Returns: pointer to the data structure that holds the statistics for a creature
  */

  CreatureStats *creature_stats = (CreatureStats *)malloc(sizeof(CreatureStats *));
  short int i = 0;
  for (i = 0; i < numberOfCreatures; i++)
  {
    if (strcmp(creatures[i].name[0], name) == 0)
    {
      break; //getting the index when matched
    }
  }
  creature_stats->creatureName[0] = strdup(name);
  creature_stats->creaturesInit = creatures[i].initiativeRating;
  creature_stats->creatureArmor = creatures[i].armourRating;
  creature_stats->creatureAttack = creatures[i].attackRating;
  creature_stats->creatureChallenge = creatures[i].challengeRating;

  return creature_stats;
}

float average_challenge(Creature *creatures, short int numberOfCreatures)
{
  /*
  Function:  average_challenge: Calculate the average challenge rating of the creatures in the database
  Parameters: *creatures: a pointer to a creature database as a parameter
              numberofcreatures: the number of creatures in the monster database;
  Returns: returns the average challenge rating of the creatures in the database
  */

  float avg;
  for (short int i = 0; i < numberOfCreatures; i++)
  {
    avg += creatures[i].challengeRating;
  }
  return avg / numberOfCreatures;
}

void print_creature_stats(CreatureStats *creature_stats)
{
  /*
  Function:  print_creatures_stats: prints out to the console the statistics of the given creature in an aesthetically pleasing manner.
  Parameters: *creatures: a pointer to a creature database as a parameter
  Returns: returns the average challenge rating of the creatures in the database
  */
  printf("%s, Init: %hd, Armor: %hd, Attack: %hd, Challenge Rating: %hd \n", creature_stats->creatureName[0], creature_stats->creaturesInit, creature_stats->creatureArmor, creature_stats->creatureAttack, creature_stats->creatureChallenge);
  free(creature_stats->creatureName[0]); //free the data after its printed for the next call from question2.c
  free(creature_stats);                  //free the data after its printed for the next call from question2.c
}