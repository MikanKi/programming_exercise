// swapVar1.c
// 変数の値を入れ換える（正しく動かない版）
// 2454403 フェリシア・アイヴィー

/* 実行結果

変数num1の値は5です。
変数num2の値は10です。
変数num1とnum2の値を交換します。
変数num1の値は10です。
変数num2の値は5です。

*/

#include <stdio.h>

// 誤ったswap関数
void swap(int *px, int *py) {   // 仮引数はローカル変数！
    int tmp;

    tmp = *px;
    *px = *py;
    *py = tmp;
}

int main(void) {
    int num1 = 5;
    int num2 = 10;

    printf("変数num1の値は%dです。\n", num1);
    printf("変数num2の値は%dです。\n", num2);
    printf("変数num1とnum2の値を交換します。\n");

    swap(&num1, &num2);   // 変数の値のコピーが渡る

    printf("変数num1の値は%dです。\n", num1);
    printf("変数num2の値は%dです。\n", num2);

    return 0;
}
