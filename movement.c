#include "movement.h"

/*
* Functions for the button maps
* Arrows: move player in indicated direction
* B: If not holding any arrow keys, stops movement of mouse
* A: increases acceleration of player vertially of the player
* L: flips movement perpendicular to the player's direction
* R: flips perpendicularly but flips the x-direction. basically same as L but other way horizontally
* Also updates position of player
*/
void performCalcs(u32 currentButtons, u32 prevBut, rat* rp) {
    if (KEY_JUST_PRESSED(BUTTON_L, currentButtons, prevBut) != 0) {
        rp->velx = -1 * rp->vely;
        rp->vely = rp->velx;
    }

    if (KEY_JUST_PRESSED(BUTTON_R, currentButtons, prevBut) != 0) {
        rp->velx = -1 * rp->vely;
        rp->vely = -1 * rp->velx;
    }

    if (KEY_JUST_PRESSED(BUTTON_A, currentButtons, prevBut) != 0) {
        if (rp->accx < 3) {
            rp->accx = rp->accx + rp->delax;
        }
        rp->velx = rp->velx + rp->accx;
    }

    if (KEY_JUST_PRESSED(BUTTON_B, currentButtons, prevBut) != 0) {
        if (rp->accx > 1) {
            rp->accx = rp->accx - rp->delax;
        }
        if (rp->accy > 1) {
            rp->accy = rp->accy - rp->delay;
        }
        rp->vely = 0;
        rp->velx = 0;
    }

    if (KEY_DOWN(BUTTON_RIGHT, currentButtons) != 0) {
        if (rp->vely < 2) {
            rp->vely = rp->vely + rp->accy;
        }
    }

    if (KEY_DOWN(BUTTON_LEFT, currentButtons) != 0) {
        if (rp->vely > -2) {
            rp->vely = rp->vely - rp->accy;
        }
    }

    if (KEY_DOWN(BUTTON_UP, currentButtons) != 0) {
        if (rp->velx > -2) {
            rp->velx = rp->velx - rp->accx;
        }
    }

    if (KEY_DOWN(BUTTON_DOWN, currentButtons) != 0) {
        if (rp->velx < 2) {
            rp->velx = rp->velx + rp->accx;
        }
    }

    if ((rp->x + rp->wide) > 140 || rp->x < 10) { //changes dimensions of top/bottom
        rp->velx = -1 * rp->velx;
    } else {

    }
    if ((rp->y + rp->len) > 240 || rp->y < 13) { //this changes the dimensions of the sides (235 is right end, 13 is left end)
        rp->vely = -1 * rp->vely;
    }
    
    //halts the movement if player is holding key down
    if (KEY_DOWN(BUTTON_B, currentButtons) == 0) {
        rp->x = rp->x + rp->velx;
        rp->y = rp->y + rp->vely;
    }
}