//
// Created by bedir on 24.04.2022.
//
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

int main() {

    int *p,*q;
    p = (int*)malloc(sizeof(int)*5);
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    q = (int*)malloc(sizeof(int)*10);
    for (int i=0;i<sizeof(p)/sizeof(int);i++) {
        q[i] = p[i];
    }

    q[5] = 6;
    q[6] = 7;
    q[7] = 8;
    q[8] = 9;
    q[9] = 10;

    free(p);
    p = q;
    q = NULL;

    printf("q1 %d, q2 %d \n",p[0],p[1]);

    for (int i = 0 ; i<10;i++) {
        printf("%d ,  %d \n",i,p[i]);
    }
}