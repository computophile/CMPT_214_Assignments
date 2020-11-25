#ifndef SOLUTIONS_ITEMS_H
#define SOLUTIONS_ITEMS_H

typedef struct _loot {
    char *base_type_name;
    char *name;
    unsigned int rarity;
} Loot;

// A prefix forms the first component of the 'name' of a loot item.
#define NUM_PREFIXES 10
static char *prefixes[] = { "Leeching", "Icy", "Firey", "Shocking", "Thundering",
                            "Corrosive", "Poisoned", "Reinforced", "Cursed", "Blessed" };

// The base type of an item is its basic form, to be stored in the 'base_name_type' member of Loot,
// and also forms the secondr component of the 'name' of the Loot.
#define NUM_BASE_TYPES 16
static char *base_types[] = { "Helmet", "Shoulder Pads", "Bracers", "Greaves", "Boots", "Cloak", "Ring", "Amulet",
                              "Armor", "Sword", "Shield", "Axe", "Dagger", "Codpiece", "Hammer", "Rapier"  };

// A suffix forms the third component of the 'name' of a loot item.
#define NUM_SUFFIXES 10
static char *suffixes[] = { "of Speed", "of Protection", "of Summoning", "of Danger Sense", "of Insulation",
                     "of Dousing", "of Staunching", "of Warmth", "of Heath", "of Allure"};

#define NUM_RARITIES 4
static char *rarity[] = { "Common", "Magic", "Epic", "Legendary" };


// additional function prototypes for the header file;
Loot generate_loot();

Loot *create_random_loot_list(unsigned int N);

void print_loot(Loot loots);

void destroy_random_loot(Loot *random_loots, int N);


#endif //SOLUTIONS_ITEMS_H
