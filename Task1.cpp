#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows = 3;
    int cols = 4;
    int** table = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        table[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            table[i][j] = j + i;
        }
    }

    printf("Двовимірний масив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%2d ", table[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += table[i][j];
        }
    }
    double average = (double)sum / (rows * cols);

    printf("Середнє арифметичне елементів таблиці: %.2lf\n", average);

    for (int i = 0; i < rows; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}