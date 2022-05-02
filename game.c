
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "game.h"


void turnUser(int *guessHuman) {
    printf("enter your predict \n");
    scanf("%d",guessHuman);
}

void turnBot(int *guessBot, int min, int max) {
    *guessBot = min+(rand()%(max-min));
    printf("bot predicted %d \n",*guessBot);

}
int  update(int *guessed, int randomNumb, char who[], int *min, int *max) {
    if (*guessed == randomNumb) {
        printf("congratulations %s you're winner. \n",who);
        return 1;
    }
    else if (*guessed < randomNumb) {
        printf("it's big number INCREASE your predict.\n");
        *min = (*guessed>*min) ? *guessed: *min;
        return 2;
    }
    else if (*guessed > randomNumb) {
        printf("it's small number DECREASE your predict.\n");
        *max = (*guessed<*max ) ? *guessed: *max;
        return 3;
    }

    else {
        printf("wrong entry");
        return 0;
    }
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int startGame() {
    int min = 0, max = 100;
    int flag=-1;
    int *guess_list, *q;
    int guessHuman, guessBot;

    guess_list = (int*)malloc(sizeof(int)*1);

    int randomNumb = rand()%100;
    int turn = 1, round = 0;

    while (flag != 1) {

        if (turn % 2 != 0) {
            turnUser(&guessHuman);
            guess_list[round] = guessHuman;
            flag = update(&guessHuman, randomNumb,"user",&min,&max);
        } else {
            turnBot(&guessBot, min, max);
            guess_list[round] = guessBot;
            flag = update(&guessBot, randomNumb," bot",&min,&max);
        }

        turn++;
        round++;

        //printf("guess leng : %d \n", sizeof(guess_list) / sizeof(int));

        q = (int *) malloc(sizeof(int)*round);
        for (int i = 0; i < round; i++) {
            q[i] = guess_list[i];
        }

        free(guess_list);
        guess_list = q;
        q = NULL;

        //qsort(guess_list, round, sizeof(int), cmpfunc);
        printf("predicts:  \n");

        for (int i = 0; i < round; i++) {
            printf("%d, ", guess_list[i]);
        }
        printf("\n");
        printf("---------------\n");


    }


}

int main(int argc, char *argv[]) {

    // oyun ekranı ok
    // giriş ok
    //rastgele sayı olustur ok
    // tahmin kisi ok
    // tahmin bilgisayar -
    // bilinen sayılar ekrana yazılcak -
    // az veya cok demek gerektiği yazılcak ok
    // dogru bilen oyun sonunda kutlanıcak ok

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
                //about_text();
                break;
            case 4:
                exit(0);
            default:
                printf("the request is wrongly entered. \n");
                break;
        }

    }
}
