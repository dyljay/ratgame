# Program Rundown!

You are a rat looking for a snack, but the homeowner is not going down without a fight. Maneuver your way through the mouse traps while securing the cheese! You utlimately win when you reach your home, but more cheese gives more points!

## Controls
Controls are very basic:

Arrow Keys: Move the rat in the respective direction
A: Increases velocity in the x direction, like a nitro of sorts. Had to be set to KEY_JUST_PRESSED because KEY_DOWN made you move way to fast due to limitations of integer math. 
B: Lowers acceleration and halts player
L: Flips player direction perpendicular to current trajectory
R: Flips player direction perpedicular to current trajectory, but then flips the direction of the x vector. Essentially the same as L, but your x-direction will be flipped.
SELECT: Reset game and return to the start screen
START: When on loss/win screen, use to play again