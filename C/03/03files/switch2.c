// switch.c
// break文を忘れたswitch-caseの動作を確認する

#include <stdio.h>

int main(void) {
    int res; 

    printf("整数を入力してください：\n");
    scanf("%d", &res);

    switch(res){
        case 1:
            printf("1が入力されました。\n");
            break;
        case 2:
            printf("2が入力されました。\n");
            break;
        default:
            printf("1でも2でもありません。\n");
            break;
    }

    return 0;
}
