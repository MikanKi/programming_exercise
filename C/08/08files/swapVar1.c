// swapVar1.c
// 変数の値を入れ換える（正しく動かない版）

#include <stdio.h>

// 誤ったswap関数
void swap(int x, int y) {   // 仮引数はローカル変数！
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

int main(void) {
    int num1 = 5;
    int num2 = 10;

    printf("変数num1の値は%dです。\n", num1);
    printf("変数num2の値は%dです。\n", num2);
    printf("変数num1とnum2の値を交換します。\n");

    swap(num1, num2);   // 変数の値のコピーが渡る

    printf("変数num1の値は%dです。\n", num1);
    printf("変数num2の値は%dです。\n", num2);

    return 0;
}
