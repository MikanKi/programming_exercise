// funcParam1.c
// 5人のテストの点数を入力し、その平均点を表示する
// 入力は配列に格納し、その計算は関数で処理する
// ★配列で処理するバージョン

#include <stdio.h>

// 与えられた整数の配列の平均値を返す
double average(int score[], int size) {
    int i;
    double sum;

    // まず合計を求める
    sum = 0.0;
    for (i = 0; i < size; i++) {
        sum += score[i];
    }

    return sum / size;
}

#define N   5   // データの数

// メイン
int main(void) {
    int data[N];    // 入力データ
    int i;
    double result;  // 結果を入れる

    printf("%d人のテストの点数を入力してください。\n", N);

    for (i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    result = average(data, N);
    printf("%d人の平均点は %.2lf点です。\n", N, result);

    return 0;
}
