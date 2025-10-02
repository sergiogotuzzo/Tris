#include <stdio.h>
#include <stdbool.h>

char lastPlayer = 'X';

void printtable(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
    printf("%c %c %c\n", c1, c2, c3);
    printf("%c %c %c\n", c4, c5, c6);
    printf("%c %c %c\n", c7, c8, c9);
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
    char c1 = '-', c2 = '-', c3 = '-', c4 = '-', c5 = '-', c6 = '-', c7 = '-', c8 = '-', c9 = '-';

    printtable(c1, c2, c3, c4, c5, c6, c7, c8, c9);

    bool lost = true;

    while (lost) {
        updateLastPlayer();

        int c;

        do {
            printf("It's %c turn!\n", lastPlayer);
            scanf("%d", &c);
        } while (c > 1 && c < 9);

        if (c == 1 && checkCell(c1)) c1 = lastPlayer;
        else if (c == 2 && checkCell(c2)) c2 = lastPlayer;
        else if (c == 3 && checkCell(c3)) c3 = lastPlayer;
        else if (c == 4 && checkCell(c4)) c4 = lastPlayer;
        else if (c == 5 && checkCell(c5)) c5 = lastPlayer;
        else if (c == 6 && checkCell(c6)) c6 = lastPlayer;
        else if (c == 7 && checkCell(c7)) c7 = lastPlayer;
        else if (c == 8 && checkCell(c8)) c8 = lastPlayer;
        else if (c == 9 && checkCell(c9)) c9 = lastPlayer;

        printtable(c1, c2, c3, c4, c5, c6, c7, c8, c9);

        if (
            (c1 == c2 && c2 == c3 && c1 != '-' && c2 != '-' && c3 != '-') ||
            (c4 == c5 && c5 == c6 && c4 != '-' && c5 != '-' && c6 != '-') ||
            (c7 == c8 && c8 == c9 && c7 != '-' && c8 != '-' && c9 != '-') ||
            (c1 == c4 && c4 == c7 && c1 != '-' && c4 != '-' && c7 != '-') ||
            (c2 == c5 && c5 == c8 && c2 != '-' && c5 != '-' && c8 != '-') ||
            (c3 == c6 && c6 == c9 && c3 != '-' && c6 != '-' && c9 != '-') ||
            (c1 == c5 && c5 == c9 && c1 != '-' && c5 != '-' && c9 != '-') ||
            (c3 == c5 && c5 == c7 && c3 != '-' && c5 != '-' && c7 != '-')
            ) {
                lost = false;
                printf("%c won!\n", lastPlayer);
            }
    }

    return 0;
}