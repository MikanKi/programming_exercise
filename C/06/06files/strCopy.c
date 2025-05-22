// strCopy.c
// 文字列を色々と処理してみる
// (1)文字列の長さ、(2)文字列をコピー、(3)文字列を連結（追加）
// 2454403 フェリシア・アイヴィー

/* 実行結果

文字列1 ?
Hello
文字列2 ?
World
文字列1「Hello」の長さ: 5
文字列2「World」の長さ: 5
コピー後の文字列1「Hello」,文字列2「Hello」
連結後の文字列1「HelloHello」,文字列2「Hello」

*/

#include <stdio.h>

#define MAX_LEN 100     // 文字列バッファの大きさ（適当）

// 文字列strの長さを返す関数
int strLength(char string[]){
    int len = 0;

    while (string[len] != '\0'){
        len++;
    }
    
    return len;
}




// 文字列strを文字列newにコピーする関数
void strCopy(char new[], char string[]){
    int i,j;
    
    for(i=0;string[i] != '\0';i++){
        new[i] = string[i];
    }
    new[i] = '\0';
}




// 文字列strに文字列addを連結する関数
void strAppend(char string[], char add[]){
    int p = 0, i = 0;

    while(string[p] != '\0'){
        p++;
    }

    while(add[i] != '\0'){
        string[p++] = add[i++];
    }

    string[p] = '\0';
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

    strCopy(str2, str1);
    printf("コピー後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    strAppend(str1, str2);
    printf("連結後の文字列1「%s」,文字列2「%s」\n", str1, str2);

    return 0;
}
