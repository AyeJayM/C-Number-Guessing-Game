#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
MAIN MENU
1. Create a function (main) that will act as the main menu and have this main able to call
        3 functions that will serve as Play, Change Max, and Quit.

OPTION 1:
    1. Use srand to generate a random number based on time, a volitaile variable.
    2. Have multiple if statements that execute based on the proximity of the user
        to the correct number (too low, high, bingo!)
    3. Incorporate an if statement that executes on the hitting "q" and returns to main.

OPTION 2:
    1. Tell them the max number they can set the value (Default 10)
        > This will require a read of the file that holds the saved max number.

OPTION 3:
    1. End the game/program by the exit() method.

BRANCH - SAVE USER MAX
    1. Use w+ to read/write/overwrite the current saved max.
        >This will be useful as it allows us to overwrite the previous max.
*/