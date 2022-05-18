//
// Created by bedir on 15.05.2022.
//

#include "leetcode.h"
#include "stdio.h"


struct ListNode {
    int val;
    struct ListNode *next;
};

int topla(int a, int b) {
    return a+b;
}
 int pow(int a, int b) {
    int sum=a;
    for (int i=1;i<b;i++){
        sum *= a;
    }

    return sum;
}

int (*fonk) (int a, int b);

int main(int argc, char *argv[]) {

    int x = 121;
    int digit = 1;
    for (int i = 9;i<=x;i+=pow(10,digit)-pow(10,digit-1),digit++) {
        i -= pow(10,digit-2);
        if (i+pow(10,digit)>=x)
            break;
    }

    int dg[digit];
    for (int i=0,basamak = pow(10,digit-1);i<digit;i++) {
        dg[i] = x/basamak;
        x -= dg[i]*basamak;
        basamak /= 10;
        printf("i -> %d \n",dg[i]);

    }

    int s = sizeof(dg)/4;
    printf("%d \n",s);

    for (int i = 0,j = (sizeof(dg)/4)-1;i<j+1;i++,j--) {
        printf("i-> %d, j-> %d \n",dg[i],dg[j]);
        if (dg[i] != dg[j]) {
            printf("false");
        }

    }
}
