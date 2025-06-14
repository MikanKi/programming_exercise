// ptrCalc1.c
// 配列とポインタの関係を理解するための例、その2

#include <stdio.h>

// メイン
int main(void) {
    int i;  // ループ変数
    int iarray[5] = { 11, 22, 33, 44, 55 };           // int型の配列
    double darray[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };   // double型の配列
    char moji[5] = { 'G', 'o', 'o', 'd', '\0' };      // 文字の配列(=文字列)
    char *strs[5] = { "No1", "no.2", "3banme", "4", "sono5" }; // 文字列の配列

    int *pi;    // int型へのポインタ
    double *pd; // double型へのポインタ
    char *pc;   // char型へのポインタ
    char **ps;  // char型の配列へのポインタ（char *ps[]と書いても同じ意味）

    // 各要素へのポインタ変数を使ったアクセスの例
    pi = iarray;    // &iarray[0] と同じ
    printf("*pi つまり iarray[0]の値: %d\n", *pi );
    printf("piのアドレス     : %p\n", pi );
    printf("pi + 1 のアドレス: %p\n", pi + 1 );   // 1増えるわけではない！
    printf("*(pi+1) つまり iarray[1]の値: %d\n", *(pi + 1) );
    pi++;   // つまり、インクリメントすると、次の要素になる！
    printf("pi++後の *pi の値: %d\n", *pi );  // iarray[1]になっている
    printf("*pi++ の値: %d\n", *pi++ );  // 1行でも書ける
    printf("*++pi の値: %d\n", *++pi );  // ++を先に書くと、事前にインクリメントされる
    printf("現在のpiとiarrayの差: %ld\n", pi - iarray );  // バイト数ではなく要素数になる
    printf("\n");

    // 以下、配列の要素指定[]を使わないでポインタを使って連続的にアクセス

    // int型の配列の要素を全て表示する
    pi = iarray;	// 注：iarrayは定数なので、++はできない
    for (i = 0; i < sizeof(iarray) / sizeof(int); i++) {
        printf("iarray %d: %d\n", i, *pi++ );  // pi[i]は使わない
    }
    printf("\n");

    // double型の配列の要素を全て表示する
    pd = darray;    // &darray[0] と同じ



    // charの配列の要素を全て表示する
    pc = moji;      // &moji[0] と同じ



    // 文字列（文字へのポインタ）の配列の要素を全て表示する
    ps = strs;      // &strs[0] と同じ
    
    

}
