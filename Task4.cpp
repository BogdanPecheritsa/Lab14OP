#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 10;
    int sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = size / 2; j < size; j++) {
            sum += (i * size) + j;
        }
    }

    printf("Сума елементів заштрихованої частини: %d\n", sum);

    return 0;
}