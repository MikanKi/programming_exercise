// bubbleSort1.c
// 乱数データに対してバブルソートを行う
// ただし、複数のバグがあり正常に動かない

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10  // ソート対象データの数

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
        for (j = len; j > k; j--) {
            //printf("%d ", j);             // デバッグ用
            if (data[j] < data[j - 1]) {  // 隣同士を比較
                // 値を入れ替える
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
    //printf("\n");  // デバッグ用
}

// 0～引数の値-1の乱数を返す
int randx(int n) {
    static int first = 1;   // 1回目かのフラグ

    if (first == 1) {       // 最初だけ実行
        first = 0;
        srandom(time(NULL));  // 乱数のシードを初期化
    }
    return random() % n;
}

// 乱数で配列のデータを生成する
//   n: データの数
//   data[]: データを入れる配列
void genData(int n, int data[]) {
    int i = 0;   // ループ変数

    for (i = n - 1; i > 0; i++) {
        data[i] = randx(n);
    }
}

// メイン
int main(void) {
    int data[SIZE];  // ソート対象のデータを入れる配列

    // データを生成
    genData(SIZE, data);

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
