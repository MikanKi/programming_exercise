// shoppingPtr.c
// 所持金と品物の単価と個数から、購入できるか判定する（お釣りも計算する）
// 2454403 フェリシア・アイヴィー

/* 実行結果

手持ちの金額： 
524
単価： 
23
個数： 
5
買える。おつりは409円。

手持ちの金額： 
2564
単価： 
142 
個数： 
5243
買えない。18個までなら買える。

*/

#include <stdio.h>

// 所持金、単価、個数 を入力し、その値を返す処理
void inputData(int *shojiP, int *tankaP, int *kosuP) {
    // scanf()関数へはポインタ（アドレス）を渡す
    printf("手持ちの金額： \n");
    scanf("%d",shojiP);

    printf("単価： \n");
    scanf("%d",tankaP);

    printf("個数： \n");
    scanf("%d",kosuP);

}

// 買えるかどうかを判定する関数（買えるときは1を返す）
// また、おつりと購入可能最大数の値も返す
int judge(int shoji, int tanka, int kosu, int *otsuriP, int *maxP) {
    // おつりと購入可能数を単純に計算
    if(shoji/tanka >= kosu){
        *otsuriP = shoji - (tanka*kosu);
        return 1;
    } else {
        *maxP = shoji/tanka;
        return 0;
    }




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
