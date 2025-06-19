// funcBranch2.c
// 関数ポインタの配列を使って、数値で関数を呼び出す

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
    void (*funcP[3])(void); // 関数ポインタの配列
    int num;

    // 関数のアドレスを関数ポインタの配列にセットする
    funcP[0] = show0;
    funcP[1] = show1;
    funcP[2] = show2;

    printf("どの乗り物を呼び出しますか？（0:車 1:レーシングカー 2:飛行機）\n");
    scanf("%d", &num);

    if (0 <= num && num <= 2) {
        (*funcP[num])();    // 関数ポインタを使って関数を呼び出す
    }

    return 0;
}
