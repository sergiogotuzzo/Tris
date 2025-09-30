#include <stdio.h>
#include <stdbool.h>

char last = 'X';

void printtable(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
    printf("%c %c %c\n", c1, c2, c3);
    printf("%c %c %c\n", c4, c5, c6);
    printf("%c %c %c\n", c7, c8, c9);
}

char lastPlayerUpdater(char lastPlayer) {
    if (lastPlayer == 'X') {
        return 'O';
    }

    return 'X';
}

bool checkCell(char c) {
    if (c != '-') {
        printf("There is already an %c in this cell\n", c);

        last = lastPlayerUpdater(last);

        return false;
    }

    return true;
}

int main() {
    char c1 = '-', c2 = '-', c3 = '-', c4 = '-', c5 = '-', c6 = '-', c7 = '-', c8 = '-', c9 = '-';

    printtable(c1, c2, c3, c4, c5, c6, c7, c8, c9);

    bool lost = true;

    while (lost) {
        last = lastPlayerUpdater(last);

        printf("It's %c turn!: ", last);

        int c;

        scanf("%d", &c);

        if (c == 1 && checkCell(c1)) c1 = last;
        if (c == 2 && checkCell(c2)) c2 = last;
        if (c == 3 && checkCell(c3)) c3 = last;
        if (c == 4 && checkCell(c4)) c4 = last;
        if (c == 5 && checkCell(c5)) c5 = last;
        if (c == 6 && checkCell(c6)) c6 = last;
        if (c == 7 && checkCell(c7)) c7 = last;
        if (c == 8 && checkCell(c8)) c8 = last;
        if (c == 9 && checkCell(c9)) c9 = last;

        printtable(c1, c2, c3, c4, c5, c6, c7, c8, c9);

        if (
            ((c1 == c2) && (c2 == c3) && c1 != '-' && c2 != '-' && c3 != '-') ||
            ((c4 == c5) && (c5 == c6) && c4 != '-' && c5 != '-' && c6 != '-') ||
            ((c7 == c8) && (c8 == c9) && c7 != '-' && c8 != '-' && c9 != '-') ||
            ((c1 == c4) && (c4 == c7) && c1 != '-' && c4 != '-' && c7 != '-') ||
            ((c2 == c5) && (c5 == c8) && c2 != '-' && c5 != '-' && c8 != '-') ||
            ((c3 == c6) && (c6 == c9) && c3 != '-' && c6 != '-' && c9 != '-') ||
            ((c1 == c5) && (c5 == c9) && c1 != '-' && c5 != '-' && c9 != '-') ||
            ((c3 == c5) && (c5 == c7) && c3 != '-' && c5 != '-' && c7 != '-')
            ) {
                lost = false;
                printf("%c won!", last);
            }
    }

    return 0;
}