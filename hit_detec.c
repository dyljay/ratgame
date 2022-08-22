#include "hit_detec.h"
#include "images/background.h"

/*
* Function to increment the score for when the player collects cheese
*/
void inc_score(int* score) {
    *score += 100;
}


/*
* Function to detect whether the player has collided with the end goal location to go to win screen
*/
int hit_goal(rat *thisr, struct endgoal end) {
    if ((end.x_lower <= thisr->x + thisr->wide) && 
        (end.x_upper >= thisr->x) && 
        (end.y_lower <= thisr->y + thisr->len) && 
        (end.y_upper >= thisr->y)) {
            return 1;
    } else {
        return 0;
    }
}

/*
* Uses the macro defined in the .h file to see whether a collision has been detected
* We go through all the cheeses in the array of cheese structures and checks for collision between any one of them
* If one is found, we take that cheese structure in the array and swap it with the last element, and then decrement the size of the array
* This effectively removes the cheese that was collected from being rendered from then on
*/
int hit_cheese(rat *thisr, struct cheese cheeses[], int *size, int *score) {
    for (int j = 0; j < *size; j++) {
        if (HIT1(thisr, cheeses, j) != 0) {
            inc_score(score);
            undrawImageDMA(cheeses[j].x, cheeses[j].y, cheeses[j].w, cheeses[j].h, background); 
            swapCheese(cheeses, j, *size - 1);
            *size -= 1;
            return 1;
        }
    }
    return 0;
}

/*
* Function to swap the cheese structure array for use in hit_cheese
*/
void swapCheese(struct cheese cheeses[], int index1, int index2) {
    struct cheese holder = cheeses[index2];
    cheeses[index2] = cheeses[index1];
    cheeses[index1] = holder;
}

/*
* Also uses the same macro used in hit_cheese, but just returns a value of 1 if hit because there is nothing to do but say 
* the player lost if a trap is hit.
*/
int hit_trap(rat *thisr, struct trap traps[], int size) {
    for (int j = 0; j < size; j++) {
        if (HIT1(thisr, traps, j) != 0) {
            return 1;
        }
    }
    return 0;
}