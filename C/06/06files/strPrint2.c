// strPrint2.c
// 文字列を出力する
// 2454403 フェリシア・アイヴィー

/* 実行結果

This is test.
漢字も表示できる。
It is a sunny day.
0123456789

*/

#include <stdio.h>

void outStr(char string[]){
    int i; // ループ変数

    // 文字列の中身を1文字ずつ表示する
    for (i = 0; string[i] != '\0'; i++) {
        printf("%c", string[i]);  // "%c"を使って 1文字ずつ出力
    }
}

int main(void) {
    char str[100] = "This is test.\n漢字も表示できる。\n";


    outStr(str);
    outStr("It is a sunny day.\n0123456789\n");


    return 0;
}

