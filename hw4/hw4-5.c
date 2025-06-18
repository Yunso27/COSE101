#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int N;
    printf("참여할 사람의 수를 입력하세요 (3 <= N <= 9): ");
    scanf("%d", &N);

    if (N < 3 || N > 9) {
        printf("참여 인원은 3명 이상 9명 이하이어야 합니다.\n");
        return 1;
    }

    int ladder[10][9];
    int height = 10;
    int width = N;
    int num_lines = 3 * N;

    // 사다리 초기화
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width - 1; j++) {
            ladder[i][j] = 0;
        }
    }

    srand(time(NULL));
    int count = 0;
    while (count < num_lines) {
        int r = rand() % height;
        int c = rand() % (width - 1);
        if (ladder[r][c] == 0) {
            // 인접한 가로선이 없는지 확인
            if (c > 0 && ladder[r][c - 1] == 1) continue;
            if (c < width - 2 && ladder[r][c + 1] == 1) continue;
            ladder[r][c] = 1;
            count++;
        }
    }

    // 사다리 출력
    printf("사다리:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width - 1; j++) {
            printf("|");
            if (j < width - 1 && ladder[i][j]) {
                printf("---");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }

    // 사다리 결과 추적
    int results[9];
    for (int i = 0; i < width; i++) {
        int pos = i;
        for (int j = 0; j < height; j++) {
            if (pos > 0 && ladder[j][pos - 1]) {
                pos--;
            } else if (pos < width - 1 && ladder[j][pos]) {
                pos++;
            }
        }
        results[i] = pos + 1;
    }

    // 결과 출력
    char labels[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    printf("결과:\n");
    for (int i = 0; i < N; i++) {
        printf("%d -> %c\n", i + 1, labels[results[i] - 1]);
    }

    printf("\n2023320136 유윤서\n");

    return 0;
}

