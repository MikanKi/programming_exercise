/*
  outOfBounds.c
  配列の添字の範囲を超えてみる
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array[10]; // 10個分の配列を作る
    int max;  // アクセスする要素番号の最大値
    int i;    // カウンタ変数

    printf("input max number: ");
    scanf("%d", &max);

    for (i = 0; i < max; i++) {
        array[i] = i;  // 範囲チェックはないので、maxまで書き込む
        printf("%d: %d\n", i, array[i]);  // 読み出してみる
    }

    return 0;
}
