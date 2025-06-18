#include <stdio.h>

int main(){
    int num, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    scanf("%d", &num);
    a1 = num / 10;
    a1 = a1 % 10;

    a2 = num / 100;
    a2 = a2 % 100;

    a3 = num / 1000;
    a3 = a3 % 1000;

    a4 = num / 10000;
    a4 = a4 % 10000;

    a5 = num / 100000;
    a5 = a5 % 100000;

    a6 = num / 1000000;
    a6 = a6 % 1000000;

    a7 = num / 10000000;
    a7 = a7 % 10000000;

    a8 = num / 100000000;
    a8 = a8 % 100000000;

    a9 = num / 1000000000;
    a9 = a9 % 1000000000;


}