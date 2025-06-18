#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int scores[30];
    int ranks[30];
    int temp_scores[30];
    int temp_indices[30];

    srand(time(NULL));
    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101;
    }

    for (int i = 0; i < 30; i++) {
        int rank = 1;
        for (int j = 0; j < 30; j++) {
            if (scores[j] > scores[i]) {
                rank++;
            }
        }
        ranks[i] = rank;
    }


    printf("1) ��ȣ��\n");
    for (int i = 0; i < 30; i++) {
        printf("%d�� %d�� %d��\n", i + 1, scores[i], ranks[i]);
    }


    for (int i = 0; i < 30; i++) {
        temp_scores[i] = scores[i];
        temp_indices[i] = i + 1;
    }

    // ���������� ���� (���� ���� ���� ��ó : https://popbox.tistory.com/6)
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 29 - i; j++) {
            if (temp_scores[j] < temp_scores[j + 1]) {
                int temp = temp_scores[j];
                temp_scores[j] = temp_scores[j + 1];
                temp_scores[j + 1] = temp;
                
                temp = temp_indices[j];
                temp_indices[j] = temp_indices[j + 1];
                temp_indices[j + 1] = temp;
            }
        }
    }

    // ������ ���
    printf("\n2) ������\n");
    for (int i = 0; i < 30; i++) {
        printf("%d�� %d�� %d��\n", i + 1, temp_scores[i], temp_indices[i]);
    }

    printf("\n2023320136 ������\n");
    
    return 0;
}

