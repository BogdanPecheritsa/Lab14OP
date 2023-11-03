#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 5;
    int m = 5;
    double** b = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        b[i] = (double*)malloc(m * sizeof(double));
    }

    printf("Введіть елементи масиву b (%d рядків, %d стовпців):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%lf", &b[i][j]);
        }
    }

    printf("Двовимірний масив b:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf\t", b[i][j]);
        }
        printf("\n");
    }

    double max_element = b[0][0];
    int max_row_index = 0;
    int max_col_index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] > max_element) {
                max_element = b[i][j];
                max_row_index = i;
                max_col_index = j;
            }
        }
    }
    printf("Максимальний елемент: %.2lf, його індекси: [%d][%d]\n", max_element, max_row_index, max_col_index);

    double min_element = b[0][0];
    int min_row_index = 0;
    int min_col_index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] < min_element) {
                min_element = b[i][j];
                min_row_index = i;
                min_col_index = j;
            }
        }
    }
    printf("Мінімальний елемент: %.2lf, його індекси: [%d][%d]\n", min_element, min_row_index, min_col_index);

    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < m; j++) {
            sum += b[i][j];
        }
        double average = sum / m;
        printf("Середнє арифметичне рядка %d: %.2lf\n", i, average);
    }

    double diagonal_product = 1.0;
    for (int i = 0; i < n; i++) {
        diagonal_product *= b[i][i];
    }
    printf("Добуток елементів головної діагоналі: %.2lf\n", diagonal_product);

    double diagonal_sum = 0.0;
    for (int i = 0; i < n; i++) {
        diagonal_sum += b[i][i];
    }
    printf("Сума елементів головної діагоналі: %.2lf\n", diagonal_sum);

    double below_diagonal_sum = 0.0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            below_diagonal_sum += b[i][j];
        }
    }
    printf("Сума елементів під головною діагоналлю: %.2lf\n", below_diagonal_sum);

    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}