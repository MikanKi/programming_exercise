// funcParam2.c
// 5人のテストの点数を入力し、その平均点を表示する
// 入力は配列に格納し、その計算は関数で処理する
// ★ポインタで処理するバージョン
// 2454403 フェリシア・アイヴィー

/* 実行結果

5人のテストの点数を入力してください。
23
56
69
78
98
5人の平均点は 64.80点です。
最高点: 98
最低点: 23

*/

#include <stdio.h>

// 与えられた整数の配列の平均値を返す
double average(int *scoreP, int size) {
    int i;
    double sum;

    // まず合計を求める
    sum = 0.0;
    for (i = 0; i < size; i++) {
        sum += *scoreP++;    // scoreP[i] や *(scoreP + i)とも書ける
    }

    return sum / size;
}

#define N   5   // データの数

int min(int *scoreP, int size){
    int i;
    int min = 101;

    for (i=0;i<size;i++){
        if(*scoreP<min){
            min = *scoreP++;
        }
    }

    return min;
}

int max(int *scoreP, int size){
    int i;
    int max = -1;

    for (i=0;i<size;i++){
        if(*scoreP>max){
            max = *scoreP++;
        }
    }

    return max;
}

// メイン
int main(void) {
    int data[N];    // 入力データ
    int *dp;        // データへのポインタ
    int i;
    double result;  // 結果を入れる
    int maximum;
    int minimum;

    printf("%d人のテストの点数を入力してください。\n", N);

    dp = data;  // 配列の最初に設定
    for (i = 0; i < N; i++) {
        scanf("%d", dp++);    // &dp[i] や dp + iとも書ける
    }

    result = average(data, N);
    printf("%d人の平均点は %.2lf点です。\n", N, result);

    maximum = max(data, N);
    printf("最高点: %d\n",maximum);

    minimum = min(data,N);
    printf("最低点: %d\n",minimum);

    return 0;
}
