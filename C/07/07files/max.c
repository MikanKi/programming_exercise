// max.c
// 2つの入力の大きな方を出力するのメイン部分（ファイル分割版）

#include <stdio.h>
#include "myfunc1.h"
#include "myfunc2.h"

// メイン
int main(void) {
    int num1, num2, ans;

    num1 = inputValue("1番目の数値を入力してください。\n");  // 数値1の入力
    num2 = inputValue("2番目の数値を入力してください。\n");  // 数値2の入力
    ans = max(num1, num2);  // 大きな方の数値を返す関数の呼び出し
    outputMax(ans);         // 結果の出力

    return 0;
}
