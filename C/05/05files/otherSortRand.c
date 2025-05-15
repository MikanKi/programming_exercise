/*
  otherSortRand.c
  バブルソート（関数に分けたもの）
*/
//2454403 フェリシア・アイヴィー

/* 実行結果

ソート前: 50 7 41 59 49 8 
ソート後: 7 8 41 49 50 59 

ソート前: 4 0 9 3 5 9 0 3 0 1 9 9 8 9 0 2 2 5 1 7 
ソート後: 0 0 0 0 1 1 2 2 3 3 4 5 5 7 8 9 9 9 9 9 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6  // ソート対象データの数
#define RANGE 100

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
        data[i]=random()%RANGE;
    }
}

void otherSort(int data[],long binary[]){
    int i,j,k;
    int count=0;
    
    for(i=0;i<SIZE;i++){
        binary[data[i]] = binary[data[i]] + 1;
    }

    for(j=0;j<100;j++){
        if(binary[j]>0){
            for(k=0;k<binary[j];k++){
                data[count]=j;
                count++;
            }
        }
    }
}

// メイン
int main(void) {
    srandom(time(NULL));
    int data[SIZE];
    long data2[100] = {};

    randData(SIZE,data);

    // 配列のデータを表示（ソート前）
    printf("ソート前: ");
    dispData(SIZE, data);

    // ソートを実行
    otherSort(data, data2);

    // 配列のデータを表示（ソート後）
    printf("ソート後: ");
    dispData(SIZE, data);

    return 0;
}
