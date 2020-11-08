/*
Name: Mohammed Thamidur Rashid
Subject: CMPT-214
Stdent Number: 11280257
MIDTERM EXAM
*/

#include "randomindex.h"
#include "items.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int count = 0;

Loot generate_loot()
{
  Loot loot;

  char *prefix = prefixes[random_index(NUM_PREFIXES)];
  char *baseTypeName = base_types[random_index(NUM_BASE_TYPES)];
  char *suffix = suffixes[random_index(NUM_SUFFIXES)];

  char *lootName = (char *)malloc(sizeof(char) * 50);

  strcpy(lootName, prefix);
  strcat(lootName, " ");
  strcat(lootName, baseTypeName);
  strcat(lootName, " ");
  strcat(lootName, suffix);

  unsigned int rarityNum = random_index(NUM_RARITIES);
  loot.name = lootName;
  loot.base_type_name = baseTypeName;
  loot.rarity = rarityNum;

  return loot;
}

Loot *create_random_loot_list(unsigned int N)
{
  Loot *loot_list = (Loot *)malloc(sizeof(Loot) * N);

  for (unsigned int i = 0; i < N; i++)
  {
    Loot loot = generate_loot();
    loot_list[i].base_type_name = loot.base_type_name;
    loot_list[i].name = loot.name;
    loot_list[i].rarity = loot.rarity;
  }
  return loot_list;
}

void print_loot(Loot *random_loots)
{

  for (int i = 0; i < 10; i++)
  {
    printf("%s %s, %s\n", random_loots[i].name, rarity[random_loots[i].rarity], random_loots[i].base_type_name);
  }
}
void destroy_random_loot(Loot *random_loots, int N)
{
  printf("Destroying the memory.\n");
  for (int i = 0; i < N; i++)
  {
    free(random_loots[i].name);
  }
  free(random_loots);
}