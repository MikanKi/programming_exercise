// strDiff.c
// 入力された2つの文字列が同じであるか判定する

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列str1と文字列str2を比較する ★現状バグあり
// 戻り値は、0:同じ、1:異なる
int strDiff(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 1;  // 違いがある
        }
        i++;    // 次の文字へ
    }
    return 0;   // 同じだった
}

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
    printf("文字列1「%s」,文字列2「%s」、結果: %d (%s)\n", str1, str2,
      strDiff(str1, str2), strDiff(str1, str2) ? "違う" : "同じ");

    return 0;
}
