#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "randomindex.h"
#include "encounter.h"

Encounter *generate_random_encounter(Creature *creatures, char encounterName[100], short int c, short int challenge_rating_threshold)
{
  Encounter *encounter = (Encounter *)malloc(sizeof(Encounter));
  encounter->desc_name = malloc(sizeof(char *));
  *(encounter->desc_name) = strdup(encounterName);
  encounter->encounterCount = c;
  encounter->encounterNames = malloc(c * sizeof(char *));
  encounter->challengeRating = 0;
  for (short int i = 0; i < c; i++)
  {
    Creature selectedCreature = creatures[random_index(numberOfCreatures)];

    // printf("challenge count at i %d, is : %hd\n", i, encounter->challengeRating);
    // printf("The selected creature name: %s\n", selectedCreature.name[0]);
    if (encounter->challengeRating < challenge_rating_threshold)
    {
      encounter->encounterNames[i] = strdup(selectedCreature.name[0]);
    encounter->challengeRating = encounter->challengeRating + selectedCreature.challengeRating;
      // printf("The selected creature name after assignment is : %s\n", encounter->encounterNames[i]);
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
  printf("%s Encounter:\n", encounter->desc_name[0]);
  for (int i = 0; i < encounter->encounterCount; i++)
  {
    printf("Monster #%d: ", i+1);
    // printf("In the encounter.c get_creature() returned: %s\n", stats->creatureName[0]);
    CreatureStats *stats = get_creature(creatures, encounter->encounterNames[i], numberOfCreatures);
    print_creature_stats(stats);

  }
  printf("Total challenge rating: %hd\n", encounter->challengeRating);
}

void destroy_encounter(Encounter *encounter, int c){
        for (short int i = 0; i < c; i++)
      {
        free(encounter->encounterNames[i]);
      }
      free(*(encounter->desc_name));
      free(encounter->desc_name);
      free(encounter->encounterNames);
      free(encounter);
}

// int main()
// {
//   Creature *creatures = create_stats_db("monsters.db");
//   // printf("The number of creatures: %d\n", numberOfCreatures);
//   Encounter *encounter = generate_random_encounter(creatures, "Dark Spell", 10, 1000);


//   destroy_encounter(encounter , 10);
//   destroy_stats_db(creatures, numberOfCreatures);

//   print_encounter(creatures, encounter);

//   printf("Encounter details: \n");
//   printf("Encounter Name: %s \n Encoutner count: %d\n", encounter->desc_name[0], encounter->encounterCount);
//   for (short int i = 0; i < encounter->encounterCount; i++)
//   {
//     printf("%s ", encounter->encounterNames[i]);
//   }
//   printf("\n");

      
//   return 0;
// }
