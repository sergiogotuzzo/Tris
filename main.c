#include <stdio.h>
#include <stdbool.h>

void printtable(char cells[9]) {
    for (int i = 0; i < 9; i++) {
        printf("%c ", cells[i]);

        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

bool checkEmptyCell(char c) {
    return c == '-';
}

bool checkEqualCells(char cells[9], int c1, int c2, int c3) {
    return cells[c1] == cells[c2] && cells[c2] == cells[c3];
}

bool checkGame(char cells[9], char lastPlayer, bool printResult) {
    if (
            (checkEqualCells(cells, 0, 1, 2) && !checkEmptyCell(cells[0]) && !checkEmptyCell(cells[1]) && !checkEmptyCell(cells[2])) ||
            (checkEqualCells(cells, 3, 4, 5) && !checkEmptyCell(cells[3]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[5])) ||
            (checkEqualCells(cells, 6, 7, 8) && !checkEmptyCell(cells[6]) && !checkEmptyCell(cells[7]) && !checkEmptyCell(cells[8])) ||
            (checkEqualCells(cells, 0, 3, 6) && !checkEmptyCell(cells[0]) && !checkEmptyCell(cells[3]) && !checkEmptyCell(cells[6])) ||
            (checkEqualCells(cells, 1, 4, 7) && !checkEmptyCell(cells[1]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[7])) ||
            (checkEqualCells(cells, 2, 5, 8) && !checkEmptyCell(cells[2]) && !checkEmptyCell(cells[5]) && !checkEmptyCell(cells[8])) ||
            (checkEqualCells(cells, 0, 4, 8) && !checkEmptyCell(cells[0]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[8])) ||
            (checkEqualCells(cells, 2, 4, 6) && !checkEmptyCell(cells[2]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[6]))
        ) {
            if (printResult) {
                printf("%c won!\n", lastPlayer);
            }

            return false;
        } else if (!checkEmptyCell(cells[0]) && !checkEmptyCell(cells[1]) && !checkEmptyCell(cells[2]) && !checkEmptyCell(cells[3]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[5]) && !checkEmptyCell(cells[6]) && !checkEmptyCell(cells[7]) && !checkEmptyCell(cells[8])) {
            if (printResult) {
                printf("Tie!\n");
            }

            return false;
        }

    return true;
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

            printtable(cells);

            if (checkGame(cells, lastPlayer, false)) {
                if (lastPlayer == 'X') {
                    lastPlayer = 'O';
                } else {
                    lastPlayer = 'X';
                }
            }
        } else {
            printf("This cell is already taken by %c\n", cells[c - 1]);
        }
    } while (checkGame(cells, lastPlayer, true));

    return 0;
}