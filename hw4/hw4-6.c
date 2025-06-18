#include <stdio.h>
#include <math.h>


//���� 2 �� Ȱ��
void draw_circle(int radius, int center_x, int center_y, char canvas[40][80]) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -2 * radius; x <= 2 * radius; x++) {
            if ((int)(sqrt(pow(x / 2.0, 2) + pow(y, 2))) == radius) {
                if (center_y + y >= 0 && center_y + y < 40 && center_x + x >= 0 && center_x + x < 80) {
                    canvas[center_y + y][center_x + x] = '*';
                }
            }
        }
    }
}

void print_canvas(char canvas[40][80]) {
    for (int y = 0; y < 40; y++) {
        for (int x = 0; x < 80; x++) {
            putchar(canvas[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    char canvas[40][80];
    for (int y = 0; y < 40; y++) {
        for (int x = 0; x < 80; x++) {
            canvas[y][x] = ' ';
        }
    }

    // �������� �� ���� �߽� ��ġ ����
    int radius = 5;
    int ring_positions[5][2] = {
        {15, 8},
        {25, 16},
        {35, 8},
        {45, 16},
        {55, 8}
    };

    draw_circle(5, 35, 32, canvas); //1�� �� �׸���(������ ��ǥ�� �ٲٴ°ͺ��� �׳� 1���� ���� �Ʒ��� ǥ���ϴ°� ���ؼ� �� ������� ������)

    for (int i = 0; i < 5; i++) {
        draw_circle(radius, ring_positions[i][0], ring_positions[i][1], canvas);
    }

    print_canvas(canvas);

    printf("\n2023320136 ������\n");

    return 0;
}
