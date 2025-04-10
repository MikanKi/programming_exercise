// 実行時間の比較（C言語版）
// loop.c

#include <stdio.h>      // printf()などを使うのに必要
#include <stdlib.h>     // random()などを使うのに必要
#include <time.h>       // time()などを使うのに必要

#define MAXCOUNT 100000000   // ループ回数(1億回)

int main(void) {
    int count = 0;  // 結果を入れる。0で初期化
    long i;         // ループ変数

    srandom(time(NULL));  // 乱数のシードを初期化

    printf("C: start\n");

    for (i = 0; i < MAXCOUNT; i++) {
        if (random() % 2 == 0) { // 偶数の場合
            count -= 1;          // 1減らす
        } else {                 // 奇数の場合
            count += 1;          // 1増やす
        }
    }

    printf("num = %d\n", count); // 結果を表示

    return 0;
}
