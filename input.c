#include "input.h"
#include "images/cheese.h"
#include "images/trap_im.h"

/*
* Function to create individual cheese structures for the array
*/
struct cheese createCheese(void) {
    struct cheese che;
    che.x = randint(20, HEIGHT - 20);
    che.y = randint(30, WIDTH - 30);
    che.w = CHEESE_WIDTH;
    che.h = CHEESE_HEIGHT;

    return che;
}

/*
* This function creates a trap structure that logs the location of trap and the space it occupies
*/
struct trap createTrap(void) {
    struct trap tra;
    tra.x = randint(20, HEIGHT - 20);
    tra.y = randint(30, WIDTH - 30);
    tra.w = TRAP_IM_WIDTH;
    tra.h = TRAP_IM_HEIGHT;

    return tra;
}

/*
* Creates the array of traps and cheese locations, and in each step, it ensures there is no collision bectween
* the cheeses, the traps and cheeses, and the traps and themselves. It also omits traps that generate on the 
* spawn point.
*/
void createArrs(struct cheese cheeses[], struct trap traps[], int size) {
    for (int i = 0 ; i < size; i++) {
        struct cheese holder = createCheese();
        for (int j = 0 ; j < size; j++) {
            if (cheeses[j].x < holder.x + holder.w &&
                cheeses[j].x + cheeses[j].w > holder.x &&
                cheeses[j].y < holder.y + holder.h &&
                cheeses[j].y + cheeses[j].h > holder.y) {
                    i -= 1;
                    break;
            }
        }
        cheeses[i] = holder;
    }

    for (int i = 0; i < size; i++) {
        struct trap holder_trap = createTrap();
        for (int j = 0; j < size; j++) {
            if ((holder_trap.x < 140 && holder_trap.x + holder_trap.w > 100) &&
            (holder_trap.y < 135 && holder_trap.y + holder_trap.h > 80)) {
                    i -= 1;
                    break;
            }
            if (traps[j].x < holder_trap.x + holder_trap.w &&
                traps[j].x + holder_trap.w > holder_trap.x &&
                traps[j].y < holder_trap.y + holder_trap.h &&
                traps[j].y + holder_trap.h > holder_trap.y) {
                    i -= 1;
                    break;
            }

            if (cheeses[j].x < holder_trap.x + holder_trap.w &&
                cheeses[j].x + cheeses[j].w > holder_trap.x &&
                cheeses[j].y < holder_trap.y + holder_trap.h &&
                cheeses[j].y + cheeses[j].h > holder_trap.y) {
                    i -= 1;
                    break;
            }
        }
        traps[i] = holder_trap;
    }
}

/*
* Function to draw all the traps in the array of trap structures
*/
void drawTrap(struct trap traps[], int size) {
    for (int i = 0; i < size; i++) {
        struct trap tr = traps[i];
        drawImageDMA(tr.x, tr.y, tr.w, tr.h, trap_im);
    }
}

/*
* Same as last, but for cheeses
*/

void drawCheese(struct cheese cheeses[], int size) {
    for (int i = 0; i < size; i++) {
        struct cheese che = cheeses[i];
        drawImageDMA(che.x, che.y, che.w, che.h, cheese);
    }
}

/*
* Initializes the rat structure
*/
void createRat(rat* newrat) {
    newrat->x = 120;
    newrat->y = 105;
    newrat->len = 20;
    newrat->wide = 10;
    newrat->velx = 0;
    newrat->vely = 0;
    newrat->accx = 1;
    newrat->accy = 1;
    newrat->delax = 1;
    newrat->delay = 1;
}

/*
* Initializes the structure containng the info on the end goal
*/
void createEnd(struct endgoal* end) {
    end->x_lower = 0;
    end->y_lower = 120;
    end->x_upper = 17;
    end->y_upper = 130;
}