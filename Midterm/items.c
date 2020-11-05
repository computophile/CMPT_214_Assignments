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

typedef struct loots_linked_list
{
  Loot *first_loot;
  unsigned int num_loots;
} loots_list;

Loot* create_random_loot_list(unsigned int N)
{
  Loot *loot_list = (Loot *)malloc(sizeof(Loot) * N);

  for (int i = 0; i < N; i++)
  {
    char *prefix = prefixes[random_index(NUM_PREFIXES)];
    char *baseTypeName = base_types[random_index(NUM_BASE_TYPES)];
    char *suffix = suffixes[random_index(NUM_SUFFIXES)];
    char nameLoot[36];
    strcpy(nameLoot, prefix);
    strcat(nameLoot, " ");
    strcat(nameLoot, baseTypeName);
    strcat(nameLoot, " ");
    strcat(nameLoot, suffix);
    // printf("%s \n", nameLoot);
    unsigned int rarityNum = random_index(NUM_RARITIES);
    loot_list[i].base_type_name = baseTypeName;
    loot_list[i].name = nameLoot;
    loot_list[i].rarity = rarityNum;
    printf(" %s %s %d\n", loot_list[i].name, loot_list[i].base_type_name, loot_list[i].rarity);
  }
  // free(loot_list);
  printf("%p\n", loot_list);
  return loot_list;
}

int main()
{
  int N = 10;
  unsigned int random_number = random_index(50);
  printf("The list of randomly generated loot list: \n");

  Loot *random_loots_list = create_random_loot_list(N);
  printf("%p\n", random_loots_list);

  for (int i = 0; i < N; i++)
  {
    printf(" %s \n", random_loots_list[i].name);
  }
  return 0;
}