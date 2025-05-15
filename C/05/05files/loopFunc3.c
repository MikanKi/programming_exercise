// loopFunc3.c
// 実行時間の比較（C言語版）
// 処理毎に関数に分割したもの（結果表示以外）
// 2454403 フェリシア・アイヴィー

/*実行結果

C: start
max = 1, num = -1334
max = 10, num = 6654
max = 100, num = -3104
max = 1000, num = -4564
max = 10000, num = 4682
max = 100000, num = 2116
max = 1000000, num = 2834
max = 10000000, num = -2712

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

void dispResult(long max, int res){
    printf("max = %ld, num = %d\n",max,res);
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
    int i;

    init();                       // 初期化
    
    for(i=1;i<=MAXCOUNT;i=i*10){
        result = upDown(MAXCOUNT);    // 処理
        dispResult(i, result); // 結果を表示
    }
    return 0;
}

