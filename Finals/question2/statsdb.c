#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "statsdb.h"

Creature *create_stats_db(char FILENAME[20])
{
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
      creatures[i].name[0] = strdup(name);
    }
    fclose(fp);
  }
    return creatures;
}
// if file doesn't exist or permission-error

void destroy_stats_db(Creature *creatures, int n)
{
  for (short int i = 0; i < n; i++)
  {
    free(creatures[i].name[0]);
  }
  free(creatures);
}

CreatureStats* get_creature(Creature *creatures, char name[100], short int numberOfCreatures)
{
  CreatureStats *creature_stats = (CreatureStats *)malloc(sizeof(CreatureStats *));
  short int i = 0;
  for (i= 0; i < numberOfCreatures; i++)
  {
    if (strcmp(creatures[i].name[0], name) == 0)
    {
      break;
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
  float avg;
  for (short int i = 0; i < numberOfCreatures; i++)
  {
    avg += creatures[i].challengeRating;
  }
  return avg / numberOfCreatures;
}

void print_creature_stats(CreatureStats *creature_stats)
{
  printf("%s, Init: %hd, Armor: %hd, Attack: %hd, Challenge Rating: %hd \n", creature_stats->creatureName[0], creature_stats->creaturesInit, creature_stats->creatureArmor, creature_stats->creatureAttack, creature_stats->creatureChallenge);
  free(creature_stats->creatureName[0]);
  free(creature_stats);
}

// int main()
// {
//   Creature *creatures = create_stats_db("monsters.db");
//   FILE *fp = fopen("monsters.db", "r");
//   int n;
//   fscanf(fp, "%d", &n);
//   for (int i = 0; i < n; i++)
//   {
//     printf("Creatute no. %d: \n", i);
//     printf("Name: %s %hd %hd %hd %hd\n", creatures[i].name[0], creatures[i].initiativeRating, creatures[i].armourRating, creatures[i].attackRating, creatures[i].challengeRating);
//   }

//   fclose(fp);

//   CreatureStats *chosenCreature = get_creature(creatures, "Basilisk", n);

//   printf("Chosen creature: %s\n", chosenCreature->creatureName[0]);

//   printf("Average of all the creatures: %f\n", average_challenge(creatures, n));

//   print_creature_stats(chosenCreature);
//   destroy_stats_db(creatures, n);

//   return 0;
// }