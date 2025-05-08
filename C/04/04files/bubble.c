/*
  bubble.c
  バブルソートの実装例（Cバージョン）
*/
#include <stdio.h>

#define SIZE 6  // ソート対象データの数

int main(void) {
    int data[SIZE] = {7, 5, 1, 2, 8, 3};  // ソート対象のデータ
    int tmp;    // テンポラリ（一時的に使う）変数
    int k, j;   // ループ変数

    // 配列のデータを表示（ソート前）
    printf("ソート前: ");
    for (k = 0; k < SIZE; k++) {
        printf("%d ", data[k]);
    }
    printf("\n");

    // バブルソートの処理
    for (k = 1; k < SIZE; k++) {
        for (j = SIZE - 1; j >= k; j--) {
            printf("%d ", j);             // デバッグ用
            if (data[j] < data[j - 1]) {  // 隣同士を比較
                // 値を入れ替える
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
    printf("\n");  // デバッグ用

    // 配列のデータを表示（ソート後）
    printf("ソート後: ");
    for (k = 0; k < SIZE; k++) {
        printf("%d ", data[k]);
    }
    printf("\n");

    return 0;
}
