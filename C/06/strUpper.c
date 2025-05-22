//2454403 フェリシア・アイヴィー

/* 実行結果

文字列 ?
hElLo!
文字列「HELLO!」

*/

#include <stdio.h>
#define MAX_LEN 100

void strUpper(char str[]){
    int i;

    for(i=0;str[i]!='\0';i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= ('a' - 'A');
        }
    }
}

int main(void) {
    char str[MAX_LEN];  // 入力文字列

    // データの入力
    printf("文字列 ?\n");
    scanf("%s", str);

    // 処理と結果出力
    strUpper(str);
    printf("文字列「%s」\n",str);

    return 0;
}
