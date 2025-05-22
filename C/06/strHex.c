//2454403 フェリシア・アイヴィー

/* 実行結果

文字列 ?
2564356
文字列「2564356」, 10進数: 2564356

*/

#include <stdio.h>
#define MAX_LEN 100

int strHex(char str[]) {
    int i, val = 0;


    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            val = val * 10 + (str[i] - '0');  // 1桁くりあげていく
        }
    }
    return val;
}


int main(void) {
    char str[MAX_LEN];  // 入力文字列1

    // データの入力
    printf("文字列 ?\n");
    scanf("%s", str);

    // 処理と結果出力
    printf("文字列「%s」, 10進数: %d\n",str,strHex(str));

    return 0;
}
