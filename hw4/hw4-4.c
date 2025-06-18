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


    printf("1) 번호순\n");
    for (int i = 0; i < 30; i++) {
        printf("%d번 %d점 %d등\n", i + 1, scores[i], ranks[i]);
    }


    for (int i = 0; i < 30; i++) {
        temp_scores[i] = scores[i];
        temp_indices[i] = i + 1;
    }

    // 성적순으로 정렬 (버블 정렬 관련 출처 : https://popbox.tistory.com/6)
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

    // 성적순 출력
    printf("\n2) 성적순\n");
    for (int i = 0; i < 30; i++) {
        printf("%d등 %d점 %d번\n", i + 1, temp_scores[i], temp_indices[i]);
    }

    printf("\n2023320136 유윤서\n");
    
    return 0;
}

