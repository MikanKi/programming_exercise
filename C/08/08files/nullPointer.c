// nullPointer.c
// 値がない、または不正なアドレスを入れたポインタを使ったアクセス

#include <stdio.h>

int main(void) {
    int *initP;         // 初期化していないポインタ
    int *nullP = NULL;  // 不正なアドレスを指定したポインタ

    // 未初期化ポインタのアクセス
    printf("初期化してないポインタを使ったアクセスを実行:\n");
    printf("ポインタの値: %p\n", initP);
    printf("参照先: %d\n", *initP);  // 何が起こるか分からない
    printf("\n");

    // 不正なアドレスへのアクセス
    printf("不正なアドレスを指定したポインタを使ったアクセスを実行:\n");
    printf("ポインタの値: %p\n", nullP);
    printf("参照先: %d\n", *nullP); // セグメンテーションフォルトを引き起こす可能性

    printf("プログラム終了\n");  // ここに達することはないはず
    return 0;
}
