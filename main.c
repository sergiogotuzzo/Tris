#include <stdio.h>
#include <stdbool.h>
#include "checks.h"

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