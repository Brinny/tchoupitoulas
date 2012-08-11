#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void playAgain();
void guess();

void playAgain() {
    char choice;
    printf ("Would you like to play again? Y/N: ");
    scanf ("%s",&choice);
    if(choice == 'y' || choice == 'Y') guess();
    else puts ("Goodbye.");
}

void guess() {
    int guess, random;
    random = rand() % 1000 + 1;
    printf("Guess a number between 1 - 1000.\n");
    do {
        printf ("Your guess: ");
        scanf ("%d", &guess);
        if(guess < random) puts ("Your guess is too low!");
        else if(guess > random) puts ("Your guess is too high!");
    } while (random != guess);
    printf ("You got it! The number was %d.\n", guess);
    playAgain();
}

int main() {
    
    printf ("Feeling lucky?\n");
    guess();
  
    return 0;
}
