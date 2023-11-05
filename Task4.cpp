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

    printf("Введіть кількість рядків (n < %d): ", N);
    scanf_s("%d", &n);
    printf("Введіть кількість стовпців (m < %d): ", N);
    scanf_s("%d", &m);

    if (n <= 0 || n > N || m <= 0 || m > N) {
        printf("Некоректні розміри матриці. Перевірте введені дані.\n");
        return 1;
    }

    int matrix[N][N];

    printf("Введіть інтервал для генерації чисел (a < b): ");
    scanf_s("%d %d", &a, &b);

    if (a >= b) {
        printf("Некоректний інтервал. Перевірте введені дані.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (b - a + 1) + a;
        }
    }

    printf("Матриця:\n");
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

    printf("Сума елементів заштрихованої частини: %d\n", sum);

    return 0;
}