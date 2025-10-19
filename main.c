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

bool checkCell(char c) {
    return c == '-';
}

bool checkGame(char cells[9], char lastPlayer, bool printResult) {
    if (
            (cells[0] == cells[1] && cells[1] == cells[2] && !checkCell(cells[0]) && !checkCell(cells[1]) && !checkCell(cells[2])) ||
            (cells[3] == cells[4] && cells[4] == cells[5] && !checkCell(cells[3]) && !checkCell(cells[4]) && !checkCell(cells[5])) ||
            (cells[6] == cells[7] && cells[7] == cells[8] && !checkCell(cells[6]) && !checkCell(cells[7]) && !checkCell(cells[8])) ||
            (cells[0] == cells[3] && cells[3] == cells[6] && !checkCell(cells[0]) && !checkCell(cells[3]) && !checkCell(cells[6])) ||
            (cells[1] == cells[4] && cells[4] == cells[7] && !checkCell(cells[1]) && !checkCell(cells[4]) && !checkCell(cells[7])) ||
            (cells[2] == cells[5] && cells[5] == cells[8] && !checkCell(cells[2]) && !checkCell(cells[5]) && !checkCell(cells[8])) ||
            (cells[0] == cells[4] && cells[4] == cells[8] && !checkCell(cells[0]) && !checkCell(cells[4]) && !checkCell(cells[8])) ||
            (cells[2] == cells[4] && cells[4] == cells[6] && !checkCell(cells[2]) && !checkCell(cells[4]) && !checkCell(cells[6]))
        ) {
            if (printResult) {
                printf("%c won!\n", lastPlayer);
            }

            return false;
        } else if (!checkCell(cells[0]) && !checkCell(cells[1]) && !checkCell(cells[2]) && !checkCell(cells[3]) && !checkCell(cells[4]) && !checkCell(cells[5]) && !checkCell(cells[6]) && !checkCell(cells[7]) && !checkCell(cells[8])) {
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

        if (checkCell(cells[c - 1])) {
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