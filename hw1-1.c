#include <stdio.h>

int main(){
    int a, b;

    printf("정수 두 개를 입력하세요 : ");
    scanf("%d %d", &a, &b);
    
    printf("%d + %d = %4d\n", a, b, a+b);
    printf("%d - %d = %4d\n", a, b, a-b);
    printf("%d * %d = %4d\n", a, b, a*b);
    printf("%d / %d = %4d\n", a, b, a/b);

    return 0;
}