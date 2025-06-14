// strSample.c
// strFuncArray.cやstrFuncPtr.cを標準関数を使うようにした

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

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
    printf("文字列1「%s」の長さ: %ld\n", str1, strlen(str1));
    printf("文字列2「%s」の長さ: %ld\n", str2, strlen(str2));

    printf("2つの文字列の比較結果: ");
    if (strcmp(str1, str2) == 0) {
        printf("同じ\n");
    } else {
        printf("異なる\n");
    }

    strcat(str1, str2);
    printf("連結後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    strcpy(str2, str1);
    printf("コピー後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    return 0;
}
