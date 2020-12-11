// data structure for the creatures

int numberOfCreatures;

typedef struct creature
{
  char *name[1]; //character array holding the name of the creature
  short int initiativeRating;
  short int armourRating;
  short int attackRating;
  short int challengeRating;
} Creature;

typedef struct creature_stats
{
  char *creatureName[1]; //character array holding the name of the creature
  short int creaturesInit;
  short int creatureArmor;
  short int creatureAttack;
  short int creatureChallenge;
} CreatureStats;

Creature *create_stats_db(char FILENAME[20]);
void destroy_stats_db(Creature *creatures, int n);
CreatureStats* get_creature(Creature *creatures, char name[100], short int numberOfCreatures);
float average_challenge(Creature *creatures, short int numberOfCreatures);
void print_creature_stats(CreatureStats *creature_stats);