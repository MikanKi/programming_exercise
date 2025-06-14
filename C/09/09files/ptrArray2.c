// ptrArray1.c
// 配列とポインタの関係を理解するための例、その1
// 2454403 フェリシア・アイヴィー

/* 実行結果

iarray[0]の値: 11
iarray[0]のアドレス : 0x16b8b33c0
iarray[1]のアドレス : 0x16b8b33c4
iarrayの値(アドレス): 0x16b8b33c0
iarray全体の大きさ: 20
iarray配列の要素数: 5

darray[0]の値: 1.100000
darray[0]のアドレス : 0x16b8b3398
darray[1]のアドレス : 0x16b8b33a0
darrayの値(アドレス): 0x16b8b3398
darray全体の大きさ: 40
darray配列の要素数: 5

moji[0]の値: G
moji[0]のアドレス : 0x16b8b3368
moji[1]のアドレス : 0x16b8b3369
mojiの値(アドレス): 0x16b8b3368
moji全体の大きさ: 5
moji配列の要素数: 5

strs[0]の値: No1
strs[0]のアドレス : 0x16b8b3370
strs[1]のアドレス : 0x16b8b3378
strsの値(アドレス): 0x16b8b3370
strs全体の大きさ: 40
strs配列の要素数: 5


*/

#include <stdio.h>

// メイン
int main(void) {
    // int型の配列
    int iarray[5] = { 11, 22, 33, 44, 55 };

    // double型の配列
    double darray[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    // 文字の配列(=文字列)  // moji[5] = "Good"; と同じ
    char moji[5] = { 'G', 'o', 'o', 'd', '\0' };

    // 文字列の配列
    char *strs[5] = { "No1", "no.2", "3banme", "4", "sono5" };

    // 配列の要素のアドレスがどうなっているかを調べてみる
    printf("iarray[0]の値: %d\n", iarray[0]);       // %dで表示
    printf("iarray[0]のアドレス : %p\n", &iarray[0]);
    printf("iarray[1]のアドレス : %p\n", &iarray[1]);
    printf("iarrayの値(アドレス): %p\n", iarray);
    printf("iarray全体の大きさ: %zd\n", sizeof(iarray));
    printf("iarray配列の要素数: %zd\n", sizeof(iarray)/sizeof(iarray[0]));
    printf("\n");

    printf("darray[0]の値: %lf\n", darray[0]);      // %lfで表示
    printf("darray[0]のアドレス : %p\n", &darray[0]);
    printf("darray[1]のアドレス : %p\n", &darray[1]);
    printf("darrayの値(アドレス): %p\n", darray);
    printf("darray全体の大きさ: %zd\n", sizeof(darray));
    printf("darray配列の要素数: %zd\n", sizeof(darray)/sizeof(darray[0]));
    printf("\n");

    printf("moji[0]の値: %c\n", moji[0]);           // %cで表示
    printf("moji[0]のアドレス : %p\n", &moji[0]);
    printf("moji[1]のアドレス : %p\n", &moji[1]);
    printf("mojiの値(アドレス): %p\n", moji);
    printf("moji全体の大きさ: %zd\n", sizeof(moji));
    printf("moji配列の要素数: %zd\n", sizeof(moji)/sizeof(moji[0]));
    printf("\n");

    printf("strs[0]の値: %s\n", strs[0]);           // %sで表示
    printf("strs[0]のアドレス : %p\n", &strs[0]);
    printf("strs[1]のアドレス : %p\n", &strs[1]);
    printf("strsの値(アドレス): %p\n", strs);
    printf("strs全体の大きさ: %zd\n", sizeof(strs));
    printf("strs配列の要素数: %zd\n", sizeof(strs)/sizeof(strs[0]));
    printf("\n");
}
