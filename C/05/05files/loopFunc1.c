// loopFunc.c
// 実行時間の比較（C言語版）
// 処理毎に関数に分割したもの（結果表示以外）
// 2454403 フェリシア・アイヴィー

/*実行結果

C: start
num = -6574

*/

#include <stdio.h>      // printf()などを使うのに必要
#include <stdlib.h>     // random()などを使うのに必要
#include <time.h>       // time()などを使うのに必要

#define MAXCOUNT 10000000   // ループ回数

// 初期化
void init(void) {
    srandom(time(NULL));  // 乱数のシードを初期化

    printf("C: start\n");
}

void dispResult(int res){
    printf("num = %d\n",res);
}

// 乱数を使って処理
int upDown(long max) {
    int count = 0;  // 結果を入れる。0で初期化
    long i;         // ループ変数

    for (i = 0; i < MAXCOUNT; i++) {
        if (random() % 2 == 0) { // 偶数の場合
            count -= 1;          // 1減らす
        } else {                 // 奇数の場合
            count += 1;          // 1増やす
        }
    }

    return count;       // 結果を返す
}

// メイン
int main(void) {
    int result;  // 結果を入れる

    init();                       // 初期化
    result = upDown(MAXCOUNT);    // 処理
    dispResult(result); // 結果を表示

    return 0;
}

