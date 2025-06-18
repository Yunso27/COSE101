#include <stdio.h>
#include <time.h>

int main() {
    long long x = time(NULL); 
    x += 9 * 3600; // UTC+9 �ð���� ��ȯ

    long long seconds_minute = 60;
    long long seconds_hour = 3600;
    long long seconds_day = 86400;
    long long seconds_year = 31536000; 
    long long seconds_leap_year = 31622400; // �����ΰ��


    int year = 1970;

    while (1) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            // ������ ���
            if (x >= seconds_leap_year) {
                x -= seconds_leap_year;
                year++;
            } else {
                break;
            }
        } else {
            // ������ �ƴ� ���
            if (x >= seconds_year) {
                x -= seconds_year;
                year++;
            } else {
                break;
            }
        }
    }

    int month = 1;
    int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days_month[1] = 29; // ���� 2���� 29��
    }

    while (x >= seconds_day) {
        if (x >= days_month[month - 1] * seconds_day) {
            x -= days_month[month - 1] * seconds_day;
            month++;
        } else {
            break;
        }
    }

    int day = x / seconds_day + 1;
    x %= seconds_day;

    int hour = x / seconds_hour;
    x %= seconds_hour;

    int minute = x / seconds_minute;
    x %= seconds_minute;

    int second = x;

    printf("%lld\n", time(NULL)); // ���� �� ���
    printf("���� �ð��� %d�� %d�� %d�� %02d�� %02d�� %02d�� �Դϴ�.\n", year, month, day, hour, minute, second);

    printf("\n2023320136 ������\n");

    return 0;
}