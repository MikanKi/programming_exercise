// myfunc2.c
// 入力と出力の処理（ファイル分割版）

#include <stdio.h>
#include "myfunc2.h"

// 指定された文字列を表示し、整数値を入力して、その値を返す
int inputValue(char str[]) {
    int num;

    printf("%s", str);
    scanf("%d",&num);

    return num;
}

// 結果を表示する
void outputMax(int ans) {
    printf("最大値は%dです。\n", ans);
}
