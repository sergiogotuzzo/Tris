#include <stdio.h>
#include <stdbool.h>
#include "prints.h"

bool checkEmptyCell(char c) {
    return c == '-';
}

bool checkEqualCells(char cells[9], int c1, int c2, int c3) {
    return cells[c1] == cells[c2] && cells[c2] == cells[c3];
}

bool keepPlaying(char cells[9], char lastPlayer, bool shouldResultBePrinted) {
    if (checkEqualCells(cells, 0, 1, 2) && !checkEmptyCell(cells[0]) && !checkEmptyCell(cells[1]) && !checkEmptyCell(cells[2])) {
        printResult(shouldResultBePrinted, 0, 1, 2, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 3, 4, 5) && !checkEmptyCell(cells[3]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[5])) {
        printResult(shouldResultBePrinted, 3, 4, 5, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 6, 7, 8) && !checkEmptyCell(cells[6]) && !checkEmptyCell(cells[7]) && !checkEmptyCell(cells[8])) {
        printResult(shouldResultBePrinted, 6, 7, 8, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 0, 3, 6) && !checkEmptyCell(cells[0]) && !checkEmptyCell(cells[3]) && !checkEmptyCell(cells[6])) {
        printResult(shouldResultBePrinted, 0, 3, 6, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 1, 4, 7) && !checkEmptyCell(cells[1]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[7])) {
        printResult(shouldResultBePrinted, 1, 4, 7, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 2, 5, 8) && !checkEmptyCell(cells[2]) && !checkEmptyCell(cells[5]) && !checkEmptyCell(cells[8])) {
        printResult(shouldResultBePrinted, 2, 5, 8, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 0, 4, 8) && !checkEmptyCell(cells[0]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[8])) {
        printResult(shouldResultBePrinted, 0, 4, 8, lastPlayer);

        return false;
    } else if (checkEqualCells(cells, 2, 4, 6) && !checkEmptyCell(cells[2]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[6])) {
        printResult(shouldResultBePrinted, 2, 4, 6, lastPlayer);

        return false;
    } else if (!checkEmptyCell(cells[0]) && !checkEmptyCell(cells[1]) && !checkEmptyCell(cells[2]) && !checkEmptyCell(cells[3]) && !checkEmptyCell(cells[4]) && !checkEmptyCell(cells[5]) && !checkEmptyCell(cells[6]) && !checkEmptyCell(cells[7]) && !checkEmptyCell(cells[8])) {
        if (shouldResultBePrinted) {
            printf("Tie!\n");
        }

        return false;
    }

    return true;
}