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

    printf("�������� ����. ���� ��� �� 3�� �̳��� ���� �Է��ϼ���.\n");

    while(1){
        
        while(count <= 10){
            a = rand() % 9 + 1;
            b = rand() % 9 + 1;
            printf("%d) %d * %d = ", count, a, b);

            clock_t start = clock();
            scanf("%d", &answer);
            clock_t end = clock();

            //vscodeȯ�濡���� 0.001�� ���ؾ� ���������
            type_time = 0.001 * (end - start);

            if(a * b == answer && type_time <= 3){
                score = score + (int)(1000 * (3 - type_time));
                printf("(�¾ҽ��ϴ�.) %.3f�� �ҿ� : Score = %d\n", type_time, score);
            }
            else if(type_time > 3){
                printf("(���ѽð��� �������ϴ�) %.3f�� �ҿ� : Score = %d\n", type_time, score);
            }
            else{
                printf("(Ʋ�Ƚ��ϴ�) %.3f�� �ҿ� : Score = %d\n", type_time, score);
            }
            count++;
        }
        round += 1;
        printf("%d���� Score : %d\n", round, score);
        printf("��� �Ͻðڽ��ϱ�?(1.��   2.�ƴϿ�): ");
        scanf("%d", &select);
        if(select == 2){
            break;
        }
        else if(select == 1){
            count = 1;
            score = 0;
        }
        else{
            printf("�߸� �Է��ϼ̽��ϴ� �ùٸ� ��ȣ�� �ٽ� �Է��ϼ���.\n");
        }
    }
    
    

    printf("\n2023320136 ������\n");
    return 0;
}