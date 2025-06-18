#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, score;
    int answer, count = 1;
    double start, end, type_time;
    int select, round = 0;
    srand(time(NULL));

    printf("구구단을 외자. 문제 출력 후 3초 이내에 답을 입력하세요.\n");

    while(1){
        
        while(count <= 10){
            a = rand() % 9 + 1;
            b = rand() % 9 + 1;
            printf("%d) %d * %d = ", count, a, b);

            clock_t start = clock();
            scanf("%d", &answer);
            clock_t end = clock();

            //vscode환경에서는 0.001을 곱해야 정상적용됨
            type_time = 0.001 * (end - start);

            if(a * b == answer && type_time <= 3){
                score = score + (int)(1000 * (3 - type_time));
                printf("(맞았습니다.) %.3f초 소요 : Score = %d\n", type_time, score);
            }
            else if(type_time > 3){
                printf("(제한시간이 지났습니다) %.3f초 소요 : Score = %d\n", type_time, score);
            }
            else{
                printf("(틀렸습니다) %.3f초 소요 : Score = %d\n", type_time, score);
            }
            count++;
        }
        round += 1;
        printf("%d라운드 Score : %d\n", round, score);
        printf("계속 하시겠습니까?(1.예   2.아니오): ");
        scanf("%d", &select);
        if(select == 2){
            break;
        }
        else if(select == 1){
            count = 1;
            score = 0;
        }
        else{
            printf("잘못 입력하셨습니다 올바른 번호를 다시 입력하세요.\n");
        }
    }
    
    

    printf("\n2023320136 유윤서\n");
    return 0;
}