#include "movement.h"

#define sizevar 3

struct cheese createCheese(void);
struct trap createTrap(void);
void createRat(rat* newrat);
void createEnd(struct endgoal* end);
void createArrs(struct cheese cheeses[], struct trap traps[], int size);
void drawTrap(struct trap traps[], int size);
void drawCheese(struct cheese cheeses[], int size);