// charCount1.c
// 1行を入力して、その中に含まれる文字種別をカウントする
// 配列版

#include <stdio.h>
#include <string.h> // strlen()などを使うため
#include <ctype.h>  // isdigit()やisupper()などを使うため

#define MAX_LEN 1000    // 入力文字の最大数

int main(void) {
    char str[MAX_LEN];  // 入力用文字配列
    size_t len, i;      // 文字列の長さ、ループカウンタ
    int digits = 0;     // 数字の数
    int alphabets = 0;  // アルファベットの数
    int uppercase = 0;  // 小文字の数
    int lowercase = 0;  // 大文字の数
    int spaces = 0;     // スペース,TABの数
    int others = 0;     // その他の文字の数
    int total = 0;      // 全体の数

    printf("文字列？ ");
    fgets(str, MAX_LEN, stdin);  // 1行の入力を取得
    
    // 文字列の長さを取得
    len = strlen(str);

    // 文字列をスキャンして種類別にカウント
    for (i = 0; i < len; i++) {
        total++;
        if (isdigit(str[i])) {
            digits++;
        } else if (isalpha(str[i])) {
            alphabets++;
            if (isupper(str[i])) {
                uppercase++;
            } else if (islower(str[i])) {
                lowercase++;
            }
        } else if (isspace(str[i])) {
            spaces++;
        } else {
            others++;
        }
    }

    // 結果を出力
    printf("数字    : %d\n", digits);
    printf("英文字  : %d\n", alphabets);
    printf(" 大文字 : %d\n", uppercase);
    printf(" 小文字 : %d\n", lowercase);
    printf("スペース: %d\n", spaces);
    printf("その他  : %d\n", others);
    printf("トータル: %d\n", total);

    return 0;
}
