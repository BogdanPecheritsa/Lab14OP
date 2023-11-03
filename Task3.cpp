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
    printf("Введіть реальні розміри масиву (n < %d, m < %d): ", N, M);
    scanf_s("%d %d", &n, &m);

    if (n >= N || m >= M || n <= 0 || m <= 0) {
        printf("Неправильні розміри масиву. Використовуйте n < %d та m < %d.\n", N, M);
        return 1;
    }

    int a, b;
    printf("Введіть інтервал [a, b] для генерації псевдовипадкових чисел: ");
    scanf_s("%d %d", &a, &b);

    if (a >= b) {
        printf("Неправильний інтервал. Використовуйте a < b.\n");
        return 1;
    }

    int matrix[N][M];
    int vector[N * M];

    srand((unsigned int)time(NULL));

    printf("Матриця %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a;
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Одновимірний масив %d елементів:\n", n * m);
    for (int i = 0; i < n * m; i++) {
        vector[i] = rand() % (b - a + 1) + a;
        printf("%d\t", vector[i]);
    }
    printf("\n");

    printf("Заміна елементів матриці на відповідні елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = vector[i * m + j];
        }
    }

    printf("Оновлена матриця %d x %d:\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}