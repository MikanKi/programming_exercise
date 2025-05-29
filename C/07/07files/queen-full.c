// queen-full.c
// エイトクイーンを解く（1つのソースコード版）

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8  // 盤面サイズ

int board[SIZE][SIZE] = {}; // 盤面のデータ
int count = 0;              // solve8Queens()が何回呼ばれたかを記憶する

// 盤面の出力を行う
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

// 指定された場所にクイーンを置けるかどうかを判定する
// （1: 置ける、0: 置けない）
int is_safe(int row, int col) {
    int x, y;

    for (y = 0; y < row; y++) {
        if (board[y][col]) {
            return 0;
        }
    }

    for (y = row, x = col; y >= 0 && x >= 0; y--, x--) {
        if (board[y][x]) {
            return 0;
        }
    }

    for (y = row, x = col; y >= 0 && x < SIZE; y--, x++) {
        if (board[y][x]) {
            return 0;
        }
    }

    return 1;
}

// エイトクイーンを解く再帰呼び出し関数
int solve8Queens(int row) {
    int cols[SIZE];
    int x, y, temp;

    count++;    // 何回呼び出されたか記憶しておく

    if (row >= SIZE) {
        return 1;  // 最後まで行った
    }

    for (y = 0; y < SIZE; y++) {
        cols[y] = y;
    }

    for (y = 0; y < SIZE; y++) {
        x = random() % SIZE; // 配置をランダムにする
        temp = cols[y];
        cols[y] = cols[x];
        cols[x] = temp;
    }

    for (y = 0; y < SIZE; y++) {
        int col = cols[y];  // 何度も使うので、簡単な変数に入れておく
        if (is_safe(row, col)) {  // 置くことができるなら
            board[row][col] = 1;  // いったん、置いてみて
            if (solve8Queens(row + 1) == 1) { // 次を探す
                return 1;  // 置けたか、最後まで行った
            }
            board[row][col] = 0;  // 元に戻しておく
        }
    }
    return 0;  // 解は見つからなかった
}

// 再帰関数が呼び出された回数を表示する
void dispCount(void) {
    printf("count=%d\n", count);
}

// メイン
int main(void) {
    printf("<Eight Queens Problem>\n");

    // 乱数の初期化
    srandom(time(NULL));

    if (solve8Queens(0)) {  // 解く
        printBoard();       // 盤面を表示
        dispCount();        // 再帰関数の呼出し回数を表示
    } else {
        printf("解は見つかりませんでした。\n");
    }

    return 0;
}
