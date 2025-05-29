#include "common.h"
#include "module2.h"

void printBoard(void) {
    int x, y;

    printf("  ");
    for (x = 0; x < SIZE; x++) {
        printf("%2d", x+1);
    }
    printf("\n");

    for (y = 0; y < SIZE; y++) {
        printf("%2d ", y+1);
        for (x = 0; x < SIZE; x++) {
            printf("%c ", board[y][x] ? 'Q' : '.');
        }
        printf("\n");
    }
}
