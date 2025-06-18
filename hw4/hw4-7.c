#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Generate_Lotto(int number[6]);

double lottoNumbers[45] = {
};

void Generate_Lotto(int number[6]) {
    int i, j;
    int temp;
    int is_duplicate;
    

    for (i = 0; i < 6; i++) {
        number[i] = 0;
    }
    
    
    for (i = 0; i < 6; i++) {
        do {
            is_duplicate = 0; 
            temp = rand() % 45 + 1; 

            for (j = 0; j < i; j++) {
                if (number[j] == temp) {
                    is_duplicate = 1;
                    break;
                }
            }
        } while (is_duplicate); 
        number[i] = temp; 
    }
}

int main() {
    int nth;
    int lotto[6];
    int i, j;
    srand((unsigned)time(NULL));
    printf("�� ��Ʈ�� �ζ� ��ȣ�� �����ұ��?");
    scanf("%d", &nth);
    for (i = 0; i < nth; i++) {
        Generate_Lotto(lotto);
        printf("%3dth Lotto : ", i + 1);
        for (j = 0; j < 6; j++)
            printf("%d ", lotto[j]);
        printf("\n");
    }
    
    printf("\n2023320136 ������\n");
    return 0;
}


