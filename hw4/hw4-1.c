#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int  x, y, com_x, com_y;
    double distance, old_distance = 999, magnetic = 15;
    srand(time(NULL));
    
    com_x = rand() % 61 + 20;
    com_y = rand() % 61 + 20;
    
    printf("비켄디에 착륙했습니다. 자기장 생성기를 찾으세요. 자기장 크기 : %.0f\n", magnetic);
    
    while(1){
        if(magnetic <= 0){
            printf("기회를 모두 사용했습니다.\n");
            printf("자기장 생성기의 좌표는 (%d, %d) 입니다. 찾기 실패!\n", com_x, com_y);
            break;
        }

        printf("좌표는? ");
        scanf("%d %d", &x, &y);
        magnetic = magnetic - 0.5;
        
        distance = sqrt((com_x - x)*(com_x - x) + (com_y - y)*(com_y - y));
        
        if(distance <= 1.5){
            printf("(%d, %d)은 자기장 안입니다. 자기장 생성기를 찾았습니다(거리 %f)\n", x, y, distance);
            printf("자기장 생성기의 좌표는 (%d, %d) 입니다. 오늘은 치킨이닭!\n", com_x, com_y);
            break;
        }
        else{
            if((com_x - magnetic > x || com_x + magnetic < x ) || (com_y - magnetic > y || com_y + magnetic < y )){
                if(distance < old_distance){
                    printf("(%d, %d)은 자기장 밖입니다. 자기장 생성기에 가까워졌습니다. 자기장 크기: %f\n", x, y, magnetic);
                }
                else{
                    printf("(%d, %d)은 자기장 밖입니다. 자기장 생성기에서 멀어졌습니다. 자기장 크기: %f\n", x, y, magnetic);
                }
            }
            else{
                if(distance < old_distance){
                    printf("(%d, %d)은 자기장 안입니다. 자기장 생성기에 가까워졌습니다. 자기장 크기: %f\n", x, y, magnetic);
                }
                else{
                    printf("(%d, %d)은 자기장 안입니다. 자기장 생성기에서 멀어졌습니다. 자기장 크기: %f\n", x, y, magnetic);
                }
            }
        }
        old_distance = distance;
    }
    
    printf("\n2023320136 유윤서\n");

    return 0;
}

