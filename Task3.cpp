#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define N 5
#define M 5

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m;
    printf("������ ������ ������ ������ (n < %d, m < %d): ", N, M);
    scanf_s("%d %d", &n, &m);

    if (n >= N || m >= M || n <= 0 || m <= 0) {
        printf("���������� ������ ������. �������������� n < %d �� m < %d.\n", N, M);
        return 1;
    }

    int a, b;
    printf("������ �������� [a, b] ��� ��������� ���������������� �����: ");
    scanf_s("%d %d", &a, &b);

    if (a >= b) {
        printf("������������ ��������. �������������� a < b.\n");
        return 1;
    }

    int matrix[N][M];
    int vector[N * M];

    srand((unsigned int)time(NULL));

    printf("������� %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("����������� ����� %d ��������:\n", n * m);
    for (int i = 0; i < n * m; i++) {
        vector[i] = rand() % (b - a + 1) + a;
        printf("%d\t", vector[i]);
    }
    printf("\n");

    printf("����� �������� ������� �� ������� �������� ������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = vector[i * m + j];
        }
    }

    printf("�������� ������� %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}