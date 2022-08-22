#ifndef MAIN_H
#define MAIN_H

// TODO: Create any necessary structs

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/

/* structure indicating all the parameters for the player (the rat)
* 
*/
typedef struct {
    int x;
    int y;
    int wide;
    int len;
    int velx;
    int vely;
    int accx;
    int accy;
    int delax;
    int delay;
} rat;

/*
* Parameters for the cheeses x position, y position, width, and height in that order
*/
struct cheese {
    int x;
    int y;
    int w;
    int h;
};

/*
* Parameters for the cheeses x position, y position, width, and height in that order
*/
struct trap {
    int x;
    int y;
    int w;
    int h;
};

/*
* Parameters for the end goal. The bounds more specifically
*/
struct endgoal {
    int x_lower;
    int y_lower;
    int x_upper;
    int y_upper;
};

extern rat *rp;
#endif