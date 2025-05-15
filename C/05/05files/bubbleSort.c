/*
  bubbleSort.c
  バブルソート（関数に分けたもの）
*/
#include <stdio.h>

#define SIZE 6  // ソート対象データの数

// 配列のデータを表示する
//   len: データの数
//   data[]: データが入っている配列
void dispData(int len, int data[]) {
    int k;   // ループ変数

    for (k = 0; k < len; k++) {
        printf("%d ", data[k]);
    }
    printf("\n");
}

// バブルソートの処理
//   len: データの数
//   data[]: データが入っている配列
void bubbleSort(int len, int data[]) {
    int k, j;   // ループ変数
    int tmp;    // テンポラリ（一時的に使う）変数

    for (k = 1; k < len; k++) {
        for (j = len - 1; j >= k; j--) {
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
}

// メイン
int main(void) {
    int data[SIZE] = {7, 5, 1, 2, 8, 3};  // ソート対象のデータ

    // 配列のデータを表示（ソート前）
    printf("ソート前: ");
    dispData(SIZE, data);

    // ソートを実行
    bubbleSort(SIZE, data);

    // 配列のデータを表示（ソート後）
    printf("ソート後: ");
    dispData(SIZE, data);

    return 0;
}
