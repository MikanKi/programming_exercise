// othello.c
// オセロの盤のようなものを文字で表示する
// 2454403 フェリシア・アイヴィー

/* 実行結果

  0 1 2 3 4 5 6 7
0 . . . . . . . . 
1 . . . . . . . . 
2 . . . . . . . . 
3 . . . O X . . . 
4 . . . X O . . . 
5 . . . . . . . . 
6 . . . . . . . . 
7 . . . . . . . . 

*/

#include <stdio.h>

#define SIZE 8

int main(void) {
    int x, y;

    // 1行目
    printf(" ");
    for (x = 0; x < SIZE; x++) {
        printf(" %d", x);
    }
    printf("\n");

    // 盤面
    for (y = 0; y < SIZE; y++) {
        // 1行ずつ表示
        printf("%d ", y);
        for (x = 0; x < SIZE; x++) {
            if (y == x && (y == 3 || y == 4)){
                printf("O");
                printf(" ");
            } else if ((y == 3 && x == 4)||(y==4 && x==3)){
                printf("X");
                printf(" ");
            } else {
                printf(".");
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
