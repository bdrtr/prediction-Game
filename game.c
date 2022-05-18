
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "game.h"


void turnUser(int *guessHuman) {
    printf("enter your predict \n"); //for take a prediction from user
    if(scanf("%d",guessHuman) != 1) {
        printf("lütfen bir sayı giriniz, oyun sonlandırılıyor.\n");
        exit(1);
    }

    if (*guessHuman > 100) {
        *guessHuman = 100;
    }
    if (*guessHuman < 0) {
        *guessHuman = 0;
    }

}

void turnBot(int *guessBot, int min, int max) { // min -> sensible minimum number, max -> sensible maximum number
    *guessBot = min+(rand()%(max-min)); //random number between 0 and (max-min) then + min example -> i want to a number between 70 - 90
    // random number 0 - 20 = 12 ,  70 + 12 = 82 my random number is 82
    printf("bot predicted %d \n",*guessBot);

}
int  update(int *guessed, int randomNumb, char who[], int *min, int *max) { // this control for about winner and for next move
    if (*guessed == randomNumb) {
        printf("congratulations %s you're winner. \n",who);
        return 1;
    }
    else if (*guessed < randomNumb) {
        printf("Random number is big number ,INCREASE your prediction.\n");
        *min = (*guessed>*min) ? *guessed: *min; // if this min prediction is small enough it's is new basement minimum number for computer predictions
        // if guess is small and ever holded number until now is bigger than of that
        return 2;
    }
    else if (*guessed > randomNumb) {
        printf("Random number is small number ,DECREASE your prediction.\n");
        *max = (*guessed<*max ) ? *guessed: *max;
        return 3;
    }

    else {
        printf("wrong entry");
        return 0;
    }
}

int startGame() {
    int min = 0, max = 100;
    int flag=-1;
    int *guess_list, *q; // for hold the predictions
    int guessHuman, guessBot;

    guess_list = (int*)malloc(sizeof(int)*1);

    int randomNumb = rand()%100;
    int turn = 1, round = 0;

    while (flag != 1) {

        if (turn % 2 != 0) {
            turnUser(&guessHuman);
            guess_list[round] = guessHuman; // round number index of list will fill with guess
            flag = update(&guessHuman, randomNumb,"user",&min,&max);
        } else {
            turnBot(&guessBot, min, max);
            guess_list[round] = guessBot;
            flag = update(&guessBot, randomNumb," bot",&min,&max);
        }

        turn++;
        round++;


        q = (int *) malloc(sizeof(int)*round+1); // for extends the prediction list for one integer size
        for (int i = 0; i < round; i++) {
            q[i] = guess_list[i]; // copy to new list
        }

        free(guess_list); //this important avoid for stackoverflow
        guess_list = q;
        q = NULL; // q list have to leave free

        printf("predicts:  \n");

        for (int i = 0; i < round; i++) {
            printf("%d, ", guess_list[i]);
        }
        printf("\n");
        printf("---------------\n");

    }

    min = 0;
    max = 100;
    free(guess_list);



}

int main(int argc, char *argv[]) {

    int request;

    char openText[] = "hello, welcome to guess game.\n";
    printf("%s",openText);

    while (true) {

        printf("1-) start the game\n");
        printf("2-) how can i play?\n");
        printf("3-) project and developer about\n");
        printf("4-) quit\n");

        scanf("%d", &request);

        switch (request) {
            case 1:
                startGame();
                break;
            case 2:
                description();
                break;
            case 3:
                about_text();
                break;
            case 4:
                exit(0);
            default:
                printf("the request is wrongly entered. \n");
                break;
        }

    }
}
