// strFuncPtr-temp.c
// 文字列を色々と処理する関数を作る。ポインタを使った版
// (1)文字列の長さを求める、(2)コピー、(3)連結（追加）、(4)比較
// 2454403 フェリシア・アイヴィー

/* 実行結果

文字列1 ?
abc
文字列2 ?
abcd
文字列1「abc」の長さ: 3
文字列2「abcd」の長さ: 4
2つの文字列の比較結果: 異なる
連結後の文字列1「abcabcd」,文字列2「abcd」
コピー後の文字列1「abcabcd」,文字列2「abcabcd」

*/

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列strの長さを返す関数（ポインタ版）
int strLength(char *str){
    int len=0;
    
    while(*str++ != '\0'){
        len++;
    }

    return len;
}





// 文字列strを文字列newにコピーする関数（ポインタ版）
void strCopy(char *s2, char *s1){
    while(*s1 != '\0'){
        *s2++ = *s1++;
    }
    *s2 = '\0';
}






// 文字列strに文字列addを連結する関数（ポインタ版）
void strAppend(char *s1, char *s2){
    int len1 = strLength(s1);

    while(*s2 != '\0'){
        *(s1++ +len1) = *s2++;
    }
    *(s1+len1) = '\0';
}






// 文字列str1と文字列str2を比較する関数（ポインタ版）
// 戻り値は、0:等しい、1:異なる
int strCompare(char *s1, char *s2){
    if(strLength(s1)!=strLength(s2)){
        return 1;
    }
    
    while(*s1 != '\0' || *s2 != '\0'){
        if(*s1++ != *s2++){
            return 1;
        }
    }

    return 0;
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
