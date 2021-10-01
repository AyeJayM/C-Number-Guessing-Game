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
    2. Allow user to input desired max value.
        > This will require a write to the file that holds the saved max number.

OPTION 3:
    1. End the game/program by breaking from the loop and concluding main.

BRANCH - SAVE USER MAX
    1. Use w+ to read/write/overwrite the current saved max.
        >This will be useful as it allows us to overwrite the previous max.
*/

void option1(); //Declaring option1 method
void option2(); //Declaring option2 method
int numberPicker(int PassedArg); //Declare the number generator

FILE *fp; //This points to the Max Number sava data file.
void main()
{
    int maxNumber; //Set the max number based on reading the save file.

    printf("\nWelcome to the Number Guessing Game!\n");
    printf("From this main menu, input \"1\" to play, input \"2\" to change the number range by"
        " increasing the max number limit, and input \"3\" to exit the menu and end the game!\n");

    int userInput;
    
    while(userInput != 3)
    {
        fp = fopen("maxsave.txt", "r"); //Open the text file to READ the previous max number saved. 
                                                               //By default, file contains "10"
        fscanf(fp, "%d", &maxNumber); //Make sure we read from the file every loop.

        printf("\nSelect an Option:\n");
        printf("1. Play \n2. Set Number Limit \n3. Quit Game\n");
        scanf("%d", &userInput);

        if(userInput == 1)
        {
            option1(maxNumber);
        }

        if(userInput == 2)
        {
            option2();
        }
        if((userInput <= 0) || (userInput >= 4))
        {
            printf("Invalid Input. Please enter either 1, 2, or 3.");
        }

    }
    printf("Thank you for playing!"); //OPTION 3
}


    void option1(int maxNumber)
    {
        int randNumber = numberPicker(maxNumber);
        int userGuess;

        printf("\nWelcome to the number guessing game! We picked a number from 0 to %d, try finding it!"
               " Enter your first guess!\n", maxNumber);

        while(userGuess != randNumber)
        {
            scanf("%d", &userGuess);
            char qCheck = getchar();

            if(( userGuess < randNumber) && (qCheck != 'q')) //TOO LOW
            {
                printf("\nYour guess is too low! Try again!\n");
            }

            if( (userGuess > randNumber) && (qCheck != 'q')) //TOO HIGH
            {
                printf("\nYour guess was too high! Try again!\n");
            }

            if(qCheck == 'q') //QUIT GAME
            {
                printf("\nThank you for playing! Returning to main menu!\n");
                return;

            }
        }

        printf("\nBingo! Cha! Now returning to game menu.\n"); //WIN PROMPT
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

    void option2() //Pass the file.
    {
        int desiredValue = 277; //Set the value out of range initially so we enter the while loop.

        printf("\nAdjust the number range by setting the max possible value. "
                "\nThe max possible value is 256. Negative numbers are not allowed.\n");

        while(desiredValue > 256 || desiredValue < 0)
        {
            printf("\nPlease input your desired max value. ");
            scanf("%d", &desiredValue);

                if(desiredValue > 256)
                {
                    printf("\nSorry, that value is beyond the max possible value."
                            " Please enter a value from 0-256\n");
                }

                if(desiredValue < 0)
                {
                    printf("\nSorry, that value is negative. Please enter a value from "
                            "0-256\n");
                }
        }

        fp =  fopen("maxsave.txt", "w+");
        fprintf(fp,"%d", desiredValue); //Saves the desired value to the file.
                                        //Overwrites previous max number saved.
        fclose(fp);
        printf("\nAll set! Returning to main menu!\n");

        return;
    }