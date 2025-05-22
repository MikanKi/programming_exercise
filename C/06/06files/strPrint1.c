// strPrint1.c
// 文字列を出力する

#include <stdio.h>

int main(void) {
    char str[100] = "This is test.\n漢字も表示できる。\n";
    int i; // ループ変数

    // 文字列の中身を1文字ずつ表示する
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);  // "%c"を使って 1文字ずつ出力
    }

    return 0;
}

