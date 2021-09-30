#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
MAIN MENU
    1. Have our program read from a file that contains the last saved max value. Default is 10.
    2. Create a function (main) that will act as the main menu and have this main able to call
        2 functions that will serve as Play and Change Max. Quit will execute when the user
        inputs 3 and breaks out of the while loop this will be held in.

OPTION 1:
    1. Call a function to use srand to generate a random number based on time, a volitaile variable.
    2. Have multiple if statements that execute based on the proximity of the user
        to the correct number (too low, high, bingo!)
    3. Incorporate an if statement that executes on the hitting "q" and returns to main.

OPTION 2:
    1. Tell them the max number they can set the value (Default 10)
        > This will require a read of the file that holds the saved max number.

OPTION 3:
    1. End the game/program by breaking from the loop and concluding main.

BRANCH - SAVE USER MAX
    1. Use w+ to read/write/overwrite the current saved max.
        >This will be useful as it allows us to overwrite the previous max.
*/

void option1(); //Declaring option1 method
void option2(); //Declaring option2 method
int numberPicker(int PassedArg); //Declare the number generator

int maxNumber; //Set the max number based on reading the save file.

void main()
{
    printf("Welcome to the Number Guessing Game!\n");
    printf("From this main menu, input \"1\" to play, input \"2\" to change the number range by"
        " increasing the max number limit, and input \"3\" to exit the menu and end the game!");

    int userInput;
    
    while(userInput != 3)
    {
        printf("Select an Option:");
        printf("1. Play \n2. Set Number Limit \n3.Quit Game");
        scanf("%d", userInput);

        if(userInput == 1)
        {
            option1();
        }

        if(userInput == 2)
        {
            option2();
        }
        else
        {
            printf("Invalid Input. Please enter either 1, 2, or 3.");
        }

    }
    printf("Thank you for playing!");
}




    void option1()
    {
        int randNumber = numberPicker(maxNumber);
        int userGuess;
        char q = "q";

        while(userGuess != randNumber)
        {

            if(userGuess < randNumber) //TOO LOW
            {
                printf("Your guess is too low! Try again!");
            }

            if(userGuess > randNumber) //TOO HIGH
            {
                printf("Your guess was too high! Try again!");
            }

            else //CHECK FOR Q INPUT
            {
            char userChar = userGuess + '0';
            
            if (userChar == "q")
                {
                    printf("Thank you for playing!");
                    return;
                }
            }
        }

        printf("Bingo! Aw yeah! Now returning to game menu."); //WIN PROMPT
        return;

    }




    int numberPicker(int MaxValue)
    {
        time_t t;
        MaxValue++; //Increment so that we get a random int from a range that INCLUDES MaxValue. 
                    //Which is what the user wanted

        srand((unsigned)time(&t)); //Set our random generation based on time.

        int number = (rand() % MaxValue);

        return number;
    }