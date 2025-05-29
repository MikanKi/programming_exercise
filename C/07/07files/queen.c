// queen.c
// エイトクイーンのメイン部分（ファイル分割版）
// ！！このファイルは変更しないこと！！

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "module1.h"
#include "module2.h"

int board[SIZE][SIZE] = {};  // 盤面のデータ

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
