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
  /*
  function: generate_loop
  Purpose: to generate a random loot name
  Parameters: None
  Return: Loot - a randomly generated loot
  */
  Loot loot;

  char *prefix = prefixes[random_index(NUM_PREFIXES)];
  char *baseTypeName = base_types[random_index(NUM_BASE_TYPES)];
  char *suffix = suffixes[random_index(NUM_SUFFIXES)];

  char *lootName = (char *)malloc(sizeof(char *) * 50); //dynamically allocating memory for the loot Name;

  // concatenating the string
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
  /*
  function: create_random_loot_list
  Purpose: to populate N number of loots to a dynamically allocated data structure
  Parameters: N - a positive integere specifying the number of loops
  Return: Loot * - a pointer to a structure of type Loot
  */

  Loot *loot_list = (Loot *)malloc(sizeof(Loot) * N); //dynamically allocating memory for N number of Loots

  for (unsigned int i = 0; i < N; i++)
  {
    Loot loot = generate_loot();
    loot_list[i].base_type_name = loot.base_type_name;
    loot_list[i].name = loot.name;
    loot_list[i].rarity = loot.rarity;
  }
  return loot_list;
}

void print_loot(Loot loot)
{
  /*
  function: print_loot
  Purpose: to print the randomly generated loot in < name > , < rarity_name > < base_type_name > format
  Parameters: Loot * - a pointer to a structure
of type Loot
   N - a positive integere specifying the number of loops
  Return: void 
  */
  printf("%s, %s %s\n", loot.name, rarity[loot.rarity], loot.base_type_name);
}
void destroy_random_loot(Loot *random_loots, int N)
{
  /*
  function: destroy_random_loot
  Purpose: to free the dynamically allocated memory
Parameters: Loot * - a pointer to a structure
of type Loot
  allocated Loot Structure Array.
   N - a positive integere specifying the number of loops
  Return: void
  */
  for (int i = 0; i < N; i++)
  {
    free(random_loots[i].name); //freeing the memory of the dynamically allocated lootNames
  }
  free(random_loots); // freeing the dynamically allocated Loot Structure Array.
}