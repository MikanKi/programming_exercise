// pointerScanf.c
// ポインタを使ってscanf()に渡す練習
// ★の行を追記して正しく動くようにする

#include <stdio.h>

int main(void) {
    int a;          // int型変数
    double d;       // double型変数
    char s[100];    // 文字列（文字型の配列）

    int *pa;        // int型変数のポインタ
    double *pd;     // double型変数のポインタ
    char *ps;       // 文字変数のポインタ

    pa =     ;  //★
    pd =     ;  //★
    ps =     ;  //★

    // 以降はポインタだけを使うこと。a, d, sは使ってはいけない
    printf("1つ目の値（int型）？\n");
    scanf("%d",          ); //★ &aと書いてはいけない

    printf("2つ目の値（double型）？\n");
    scanf("%lf",         ); //★ &dと書いてはいけない

    printf("3つ目の値（文字列）？\n");
    scanf("%s",          ); //★ sと書いてはいけない

    // 入力値の表示
    printf("入力された値： %d %lf \"%s\"\n",    ,    ,    );  //★

    return 0;
}
