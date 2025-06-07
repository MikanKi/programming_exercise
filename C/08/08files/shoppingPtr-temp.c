// shoppingPtr.c
// 所持金と品物の単価と個数から、購入できるか判定する（お釣りも計算する）

#include <stdio.h>

// 所持金、単価、個数 を入力し、その値を返す処理
void inputData(int *shojiP, int *tankaP, int *kosuP) {
    // scanf()関数へはポインタ（アドレス）を渡す






}

// 買えるかどうかを判定する関数（買えるときは1を返す）
// また、おつりと購入可能最大数の値も返す
int judge(int shoji, int tanka, int kosu, int *otsuriP, int *maxP) {
    // おつりと購入可能数を単純に計算





}

// メイン（ここは変更しないこと）
int main(void) {
    int shoji;  // 所持金
    int tanka;  // 単価（一個の値段）
    int kosu;   // 個数
    int otsuri; // おつり
    int max;    // 買える場合の最大個数

    inputData( &shoji, &tanka, &kosu );  // データ入力

    if (judge(shoji, tanka, kosu, &otsuri, &max) == 1) {
        printf("買える。");
        printf("おつりは%d円。\n", otsuri);
    } else {
        printf("買えない。");
        printf("%d個までなら買える。\n", max);
    }

    return 0;
}
