// funcBranch1.c
// if文やswitch-case文で分岐する例

#include <stdio.h>

// それぞれの処理を行う関数
void show0(void) {
    printf("車です。\n");
}

void show1(void) {
    printf("レーシングカーです。\n");
}

void show2(void) {
    printf("飛行機です。\n");
}

// メイン
int main(void)
{
    int num;

    printf("どの乗り物を呼び出しますか？（0:車 1:レーシングカー 2:飛行機）\n");
    scanf("%d", &num);

    // numの番号に従って、対応する関数を呼び出す
    if (num == 0) {
        show0();
    } else if (num == 1) {
        show1();
    } else if (num == 2) {
        show2();
    }

    /* 同じことを、switch-caseで記述すると次のようになる
    switch (num) {
        case 0:
            show0();
            break;
        case 1:
            show1();
            break;
        case 2:
            show2();
            break;
    }
    */

    return 0;
}
