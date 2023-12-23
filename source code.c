#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ATTEMPTS 5
#define MAX_RANDOM_NUMBER 100
int main()
{
    srand(time(NULL));
    int tempRv = MAX_RANDOM_NUMBER, tempAv = MAX_ATTEMPTS;
    int randomNumber = rand() %tempRv + 1;
    int attempts = tempAv;
    int guess;

    printf("Welcome to Guess The Number Game.");
    printf("\nI've guessed a nummber between 1 to %d. You have %d chances to guess the number...", tempRv, tempAv);
    for(;;)
    {
        printf("\n\nYOUR GUESS:  ");
        if (scanf(" %d", &guess) != 1){
            printf("\nThere occured an unexpected failure in reading the input...\nPlease try again.");
            return 101;
        }

        if (guess == randomNumber){
            printf("\n***CORRECT***\nYou've successfully guessed the right number which was %d.\n\n\n", randomNumber);
            break;
        }

        else if (guess > randomNumber){
            printf("\nToo High. Try a smaller number. You have %d chance(s) left.", --attempts);
        }

        else if (guess < randomNumber){
            printf("\nToo low. Try a larger number. You have %d chance(s) left.", --attempts);
        }

        if (attempts <= 0){
            printf("\n***GAME OVER***\nYou are out of your %d chances to guess the correct number which was %d.", tempAv, randomNumber);
            printf("\nRestart the program to play again :)\n\n\n");
            break;
        }
    }
    return 0;
}
