#include <stdio.h>
#include <stdbool.h>

void printGame(char cells[9]) {
    for (int i = 0; i < 9; i++) {
        printf("%c ", cells[i]);

        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

void printResult(bool shouldResultBePrinted, int c1, int c2, int c3, char lastPlayer) {
    if (shouldResultBePrinted) {
        printf("%c won!\n", lastPlayer);

        char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};

        cells[c1] = lastPlayer;
        cells[c2] = lastPlayer;
        cells[c3] = lastPlayer;

        printGame(cells);
    }
}