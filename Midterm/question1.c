#include "items.h"

int main()
{
  int N = 10;
  Loot *random_loots = create_random_loot_list(N);
  print_loot(random_loots);
  destroy_random_loot(random_loots, N);

  return 0;
}