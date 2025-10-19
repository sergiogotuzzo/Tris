#include <stdio.h>
#include <stdbool.h>

char lastPlayer = 'X';

void printtable(char cells[9]) {
    for (int i = 0; i < 9; i++) {
        printf("%c", cells[i]);

        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
}

void updateLastPlayer() {
    if (lastPlayer == 'X') {
        lastPlayer = 'O';
    } else {
        lastPlayer = 'X';
    }
}

bool checkCell(char c) {
    if (c != '-') {
        printf("This cell is already taken by %c\n", c);

        updateLastPlayer();

        return false;
    }

    return true;
}

int main() {
    char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};

    printtable(cells);

    bool play = true;

    while (play) {
        updateLastPlayer();

        int c;

        do {
            printf("It's %c turn!\n", lastPlayer);
            scanf("%d", &c);
        } while (c < 1 || c > 9);

        if (checkCell(cells[c - 1])) cells[c - 1] = lastPlayer;

        printtable(cells);

        if (
            (cells[0] == cells[1] && cells[1] == cells[2] && cells[0] != '-' && cells[1] != '-' && cells[2] != '-') ||
            (cells[3] == cells[4] && cells[4] == cells[5] && cells[3] != '-' && cells[4] != '-' && cells[5] != '-') ||
            (cells[6] == cells[7] && cells[7] == cells[8] && cells[6] != '-' && cells[7] != '-' && cells[8] != '-') ||
            (cells[0] == cells[3] && cells[3] == cells[6] && cells[0] != '-' && cells[3] != '-' && cells[6] != '-') ||
            (cells[1] == cells[4] && cells[4] == cells[7] && cells[1] != '-' && cells[4] != '-' && cells[7] != '-') ||
            (cells[2] == cells[5] && cells[5] == cells[8] && cells[2] != '-' && cells[5] != '-' && cells[8] != '-') ||
            (cells[0] == cells[4] && cells[4] == cells[8] && cells[0] != '-' && cells[4] != '-' && cells[8] != '-') ||
            (cells[2] == cells[4] && cells[4] == cells[6] && cells[2] != '-' && cells[4] != '-' && cells[6] != '-')
            ) {
                play = false;
                printf("%c won!\n", lastPlayer);
            } else if (cells[0] != '-' && cells[1] != '-' && cells[2] != '-' && cells[3] != '-' && cells[4] != '-' && cells[5] != '-' && cells[6] != '-' && cells[7] != '-' && cells[8] != '-') {
                play = false;
                printf("Tie!");
            }
    }

    return 0;
}