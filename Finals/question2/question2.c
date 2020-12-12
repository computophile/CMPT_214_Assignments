/*
# Name: Mohammed Thamidur Rashid
# Class: CMPT-214
# Student Number: 11280257
*/
#include <stdio.h>
#include <stdlib.h>

#ifndef __encounter_h__
#define __encounter_h__
#include "encounter.h"
#endif // !1

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

      char encounterName[30] = {"Death Valley"};
      int maxCreature = 10;
      Encounter *encounter = generate_random_encounter(creatures, encounterName, maxCreature, challengeThreshold);
      print_encounter(creatures, encounter);
      destroy_encounter(encounter, maxCreature);//free encounter
      destroy_stats_db(creatures, numberOfCreatures);// free creatures
    }
    else
    {
      printf("File not found/Not enough permission!");
    }
    
    return 0;
    fclose(fp);
  }
  else
  {
    printf("Not enought arguments! Expected 2!!");
    exit(100);
    return 1; // error in teminal file input
  }
}
