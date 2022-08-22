#include "input.h"

#define HIT1(thisr, arr, j) ((arr[j].x < (thisr->x + thisr->len)) && ((arr[j].x + arr[j].w) > thisr->x) && (arr[j].y < (thisr->y + thisr->wide)) && ((arr[j].y + arr[j].h) > thisr->y))

int hit_cheese(rat *thisr, struct cheese cheeses[], int *size, int *score);
int hit_trap(rat *thisr, struct trap traps[], int size);
int hit_goal(rat *thisr, struct endgoal end);
void swapCheese(struct cheese cheeses[], int index1, int index2);
void inc_score(int *score);