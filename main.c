#include <stdio.h>
#include <stdbool.h>
#include <checks.h>

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

int main() {
    char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    char lastPlayer = 'X';

    do {
        int c;

        do {
            printf("It's %c turn!\n", lastPlayer);
            scanf("%d", &c);
        } while (c < 1 || c > 9);

        if (checkEmptyCell(cells[c - 1])) {
            cells[c - 1] = lastPlayer;

            printGame(cells);

            if (keepPlaying(cells, lastPlayer, false)) {
                if (lastPlayer == 'X') {
                    lastPlayer = 'O';
                } else {
                    lastPlayer = 'X';
                }
            }
        } else {
            printf("This cell is already taken by %c\n", cells[c - 1]);
        }
    } while (keepPlaying(cells, lastPlayer, true));

    return 0;
}