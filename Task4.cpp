#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned int)time(NULL));

    const int N = 10;
    int n, m;
    int a, b;

    printf("������ ������� ����� (n < %d): ", N);
    scanf_s("%d", &n);
    printf("������ ������� �������� (m < %d): ", N);
    scanf_s("%d", &m);

    if (n <= 0 || n > N || m <= 0 || m > N) {
        printf("��������� ������ �������. �������� ������ ���.\n");
        return 1;
    }

    int matrix[N][N];

    printf("������ �������� ��� ��������� ����� (a < b): ");
    scanf_s("%d %d", &a, &b);

    if (a >= b) {
        printf("����������� ��������. �������� ������ ���.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a;
        }
    }

    printf("�������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m / 2; j < m; j++) {
            sum += matrix[i][j];
        }
    }

    printf("���� �������� ������������ �������: %d\n", sum);

    return 0;
}