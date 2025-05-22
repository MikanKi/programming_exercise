// strCopy.c
// 文字列を色々と処理してみる
// (1)文字列の長さ、(2)文字列をコピー、(3)文字列を連結（追加）

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列strの長さを返す関数





// 文字列strを文字列newにコピーする関数





// 文字列strに文字列addを連結する関数





// メイン
int main(void) {
    char str1[MAX_LEN];  // 入力文字列1
    char str2[MAX_LEN];  // 入力文字列2

    // データの入力
    printf("文字列1 ?\n");
    scanf("%s", str1);
    printf("文字列2 ?\n");
    scanf("%s", str2);

    // 処理と結果出力
    printf("文字列1「%s」の長さ: %d\n", str1, strLength(str1));
    printf("文字列2「%s」の長さ: %d\n", str2, strLength(str2));

    strCopy(str2, str1);
    printf("コピー後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    strAppend(str1, str2);
    printf("連結後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    return 0;
}
