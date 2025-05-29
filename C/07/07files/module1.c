#include "common.h"
#include "module1.h"

static int count = 0;

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

static int is_safe(int row, int col) {
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

void dispCount(void) {
    printf("count=%d\n", count);
}
