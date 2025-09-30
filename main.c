#include <stdio.h>
#include <stdbool.h>

void printtable(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9) {
    printf("%c %c %c\n", c1, c2, c3);
    printf("%c %c %c\n", c4, c5, c6);
    printf("%c %c %c\n", c7, c8, c9);
}

int main() {
    char c1 = '-', c2 = '-', c3 = '-', c4 = '-', c5 = '-', c6 = '-', c7 = '-', c8 = '-', c9 = '-';
   
    printtable(c1, c2, c3, c4, c5, c6, c7, c8, c9);
   
    bool lost = true;
    char last = 'X';
   
    while (lost) {
        printf("It's %c turn!: ", last);

        int c;
       
        scanf("%d", &c);
       
        char ccur;
       
        if (last == 'X') {
            ccur = 'O';
            last = 'O';
        } else {
            ccur = 'X';
            last = 'X';
        }
       
        if (c == 1) c1 = ccur;
        if (c == 2) c2 = ccur;
        if (c == 3) c3 = ccur;
        if (c == 4) c4 = ccur;
        if (c == 5) c5 = ccur;
        if (c == 6) c6 = ccur;
        if (c == 7) c7 = ccur;
        if (c == 8) c8 = ccur;
        if (c == 9) c9 = ccur;
       
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