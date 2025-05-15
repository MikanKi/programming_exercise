// staticVar.c
// staticを付けたローカル変数の動作の違い

#include <stdio.h>

int g = 0;          // グローバル変数

void func(void) {
    int a = 0;      // ローカル変数
    static int s = 0;  // staticを付けたローカル変数

    printf("グローバル変数gは%d ローカル変数aは%d staticローカル変数sは%d\n", g, a, s);

    g++; a++; s++;  // それぞれ1ずつ増やす
}

int main(void) {
    int i;

    for (i = 0; i < 5; i++) {
        func();
    }

    return 0;
}

