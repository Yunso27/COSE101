#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int N;
    printf("������ ����� ���� �Է��ϼ��� (3 <= N <= 9): ");
    scanf("%d", &N);

    if (N < 3 || N > 9) {
        printf("���� �ο��� 3�� �̻� 9�� �����̾�� �մϴ�.\n");
        return 1;
    }

    int ladder[10][9];
    int height = 10;
    int width = N;
    int num_lines = 3 * N;

    // ��ٸ� �ʱ�ȭ
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
            // ������ ���μ��� ������ Ȯ��
            if (c > 0 && ladder[r][c - 1] == 1) continue;
            if (c < width - 2 && ladder[r][c + 1] == 1) continue;
            ladder[r][c] = 1;
            count++;
        }
    }

    // ��ٸ� ���
    printf("��ٸ�:\n");
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

    // ��ٸ� ��� ����
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

    // ��� ���
    char labels[9] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    printf("���:\n");
    for (int i = 0; i < N; i++) {
        printf("%d -> %c\n", i + 1, labels[results[i] - 1]);
    }

    printf("\n2023320136 ������\n");

    return 0;
}

