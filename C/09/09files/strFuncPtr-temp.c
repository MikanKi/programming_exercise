// strFuncPtr-temp.c
// 文字列を色々と処理する関数を作る。ポインタを使った版
// (1)文字列の長さを求める、(2)コピー、(3)連結（追加）、(4)比較

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列strの長さを返す関数（ポインタ版）






// 文字列strを文字列newにコピーする関数（ポインタ版）







// 文字列strに文字列addを連結する関数（ポインタ版）







// 文字列str1と文字列str2を比較する関数（ポインタ版）
// 戻り値は、0:等しい、1:異なる








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

    printf("2つの文字列の比較結果: ");
    if (strCompare(str1, str2) == 0) {
        printf("同じ\n");
    } else {
        printf("異なる\n");
    }

    strAppend(str1, str2);  // str1にstr2を追加
    printf("連結後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    strCopy(str2, str1);    // str1をstr2にコピー
    printf("コピー後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    return 0;
}
