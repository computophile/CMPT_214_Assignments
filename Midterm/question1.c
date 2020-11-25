#include "items.h"

int main()
{
  unsigned int N = 5;
  Loot *random_loots = create_random_loot_list(N);
  for (unsigned int i = 0; i < N; i++){
   print_loot(random_loots[i]);
  }
  destroy_random_loot(random_loots, N);
  return 0;
}