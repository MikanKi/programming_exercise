/*
  selectSortRand.c
  バブルソート（関数に分けたもの）
*/
//2454403 フェリシア・アイヴィー

/* 実行結果

ソート前: 7 2 1 3 6 0 
ソート後: 7 6 3 2 1 0 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void randData(int len, int data[]){
    int i;
    for (i=0;i<len;i++){
        data[i]=random()%10;
    }
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

void selectSort(int len, int data[]){
    int s,t;
    int tmp;

    for(s=0;s<len-1;s++){
        for(t=s+1;t<len;t++){
            if(data[t]>data[s]){
                tmp = data[t];
                data[t] = data[s];
                data[s] = tmp;
            }
        }
    }
}

// メイン
int main(void) {
    srandom(time(NULL));
    int data[SIZE];
    randData(SIZE,data);

    // 配列のデータを表示（ソート前）
    printf("ソート前: ");
    dispData(SIZE, data);

    // ソートを実行
    selectSort(SIZE, data);

    // 配列のデータを表示（ソート後）
    printf("ソート後: ");
    dispData(SIZE, data);

    return 0;
}
