#include <stdio.h>
#include <stdlib.h>

#include "encounter.h"

int main(int argc, char *argv[])
{
  /* code */
  if (argc == 3)
  {
    Creature *creatures = create_stats_db(argv[1]);
    FILE *fp = fopen(argv[2], "r");

    if (fp != NULL)
    {
      short int numberofPlayers;
      float playerChallengeRating = 0.0;
      fscanf(fp, "%hd", &numberofPlayers);
      for (short int i = 0; i < numberofPlayers; i++)
      {
        char temp[20];
        for (short int j = 0; j < 4; j++)
        {
          fscanf(fp, "%s", temp);
        }
        float rating;
        fscanf(fp, "%f", &rating);
        playerChallengeRating += rating;
      }
      playerChallengeRating = playerChallengeRating / numberofPlayers;
      float challengeThreshold = playerChallengeRating * 2;
      // printf("The challenge Threshold: %f", challengeThreshold);
      char encounterName[30] = {"Death Valley"};
      int maxCreature = 10;
      Encounter *encounter = generate_random_encounter(creatures, encounterName, maxCreature, challengeThreshold);
      print_encounter(creatures, encounter);
      destroy_encounter(encounter, maxCreature);
      destroy_stats_db(creatures, numberOfCreatures);
    }
    return 0;
  }
  else
  {
    return 1; // error in teminal file input
  }
}
