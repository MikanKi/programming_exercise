// charCount1.c
// 1行を入力して、その中に含まれる文字種別をカウントする
// 配列版
// 2454403 フェリシア・アイヴィー

/* 実行結果

文字列？ 28 stab wounds! You didn't want to leave him a chance, huh? Did you feel anger?   Hate? He was bleeding, begging you for mercy, but you stabbed him, again and again and again!...
数字    : 2
英文字  : 129
 大文字 : 4
 小文字 : 125
スペース: 35
その他  : 13
トータル: 179

*/

#include <stdio.h>
#include <string.h> // strlen()などを使うため
#include <ctype.h>  // isdigit()やisupper()などを使うため

#define MAX_LEN 1000    // 入力文字の最大数

int main(void) {
    char str[MAX_LEN];  // 入力用文字配列
    int digits = 0;     // 数字の数
    int alphabets = 0;  // アルファベットの数
    int uppercase = 0;  // 小文字の数
    int lowercase = 0;  // 大文字の数
    int spaces = 0;     // スペース,TABの数
    int others = 0;     // その他の文字の数
    int total = 0;      // 全体の数
    char *strP;

    printf("文字列？ ");
    fgets(str, MAX_LEN, stdin);  // 1行の入力を取得
    strP = str;

    // 文字列をスキャンして種類別にカウント
    while(*strP != '\0') {
        total++;
        if (isdigit(*strP)) {
            digits++;
        } else if (isalpha(*strP)) {
            alphabets++;
            if (isupper(*strP)) {
                uppercase++;
            } else if (islower(*strP)) {
                lowercase++;
            }
        } else if (isspace(*strP)) {
            spaces++;
        } else {
            others++;
        }
        *strP++;
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
