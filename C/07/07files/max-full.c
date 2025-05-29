// max-full.c
// 2つの入力の大きな方を出力する（1つのソースコード版）

#include <stdio.h>

// 大きな方の数値を返すmax関数の定義
int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

// メイン
int main(void) {
    int num1, num2, ans;

    printf("1番目の数値を入力してください。\n");
    scanf("%d",&num1);

    printf("2番目の数値を入力してください。\n");
    scanf("%d",&num2);

    ans = max(num1, num2);

    printf("最大値は%dです。\n", ans);

    return 0;
}
