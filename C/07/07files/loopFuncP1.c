// loopFuncP1.c
// loopFunc.cで、main()関数を最初に移動しただけのもの
// コンパイルエラーになる

#include <stdio.h>      // printf()などを使うのに必要
#include <stdlib.h>     // random()などを使うのに必要
#include <time.h>       // time()などを使うのに必要

#define MAXCOUNT 10000000   // ループ回数

// メイン
int main(void) {
    int result;  // 結果を入れる

    init();                       // 初期化
    result = upDown(MAXCOUNT);    // 処理
    printf("num = %d\n", result); // 結果を表示

    return 0;
}

// 初期化
void init(void) {
    srandom(time(NULL));  // 乱数のシードを初期化

    printf("C: start\n");
}

// 乱数を使って処理
int upDown(long max) {
    int count = 0;  // 結果を入れる。0で初期化
    long i;         // ループ変数

    for (i = 0; i < max; i++) {
        if (random() % 2 == 0) { // 偶数の場合
            count -= 1;          // 1減らす
        } else {                 // 奇数の場合
            count += 1;          // 1増やす
        }
    }

    return count;       // 結果を返す
}
