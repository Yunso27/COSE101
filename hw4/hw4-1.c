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
    
    printf("���˵� �����߽��ϴ�. �ڱ��� �����⸦ ã������. �ڱ��� ũ�� : %.0f\n", magnetic);
    
    while(1){
        if(magnetic <= 0){
            printf("��ȸ�� ��� ����߽��ϴ�.\n");
            printf("�ڱ��� �������� ��ǥ�� (%d, %d) �Դϴ�. ã�� ����!\n", com_x, com_y);
            break;
        }

        printf("��ǥ��? ");
        scanf("%d %d", &x, &y);
        magnetic = magnetic - 0.5;
        
        distance = sqrt((com_x - x)*(com_x - x) + (com_y - y)*(com_y - y));
        
        if(distance <= 1.5){
            printf("(%d, %d)�� �ڱ��� ���Դϴ�. �ڱ��� �����⸦ ã�ҽ��ϴ�(�Ÿ� %f)\n", x, y, distance);
            printf("�ڱ��� �������� ��ǥ�� (%d, %d) �Դϴ�. ������ ġŲ�̴�!\n", com_x, com_y);
            break;
        }
        else{
            if((com_x - magnetic > x || com_x + magnetic < x ) || (com_y - magnetic > y || com_y + magnetic < y )){
                if(distance < old_distance){
                    printf("(%d, %d)�� �ڱ��� ���Դϴ�. �ڱ��� �����⿡ ����������ϴ�. �ڱ��� ũ��: %f\n", x, y, magnetic);
                }
                else{
                    printf("(%d, %d)�� �ڱ��� ���Դϴ�. �ڱ��� �����⿡�� �־������ϴ�. �ڱ��� ũ��: %f\n", x, y, magnetic);
                }
            }
            else{
                if(distance < old_distance){
                    printf("(%d, %d)�� �ڱ��� ���Դϴ�. �ڱ��� �����⿡ ����������ϴ�. �ڱ��� ũ��: %f\n", x, y, magnetic);
                }
                else{
                    printf("(%d, %d)�� �ڱ��� ���Դϴ�. �ڱ��� �����⿡�� �־������ϴ�. �ڱ��� ũ��: %f\n", x, y, magnetic);
                }
            }
        }
        old_distance = distance;
    }
    
    printf("\n2023320136 ������\n");

    return 0;
}

