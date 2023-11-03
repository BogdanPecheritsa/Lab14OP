#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned int)time(NULL));

    int k = 6;
    int n = 5;
    int i = 3;

    int votes[6][5];

    for (int j = 0; j < n; j++) {
        for (int l = 0; l < k; l++) {
            votes[l][j] = rand() % (10 * i) + 50;
        }
    }

    int candidate1Votes = 0;
    int candidate3Votes = 0;

    for (int l = 0; l < k; l++) {
        candidate1Votes += votes[l][0];
        candidate3Votes += votes[l][2];
    }

    printf("Кількість голосів за 1 кандидата: %d\n", candidate1Votes);
    printf("Кількість голосів за 3 кандидата: %d\n", candidate3Votes);

    return 0;
}