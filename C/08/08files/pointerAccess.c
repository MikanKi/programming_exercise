// pointerAccess.c
// ポインタとそれを使ったアクセスの例

#include <stdio.h>

int main(void) {
    int a, b;
    int *pA;

    a = 5;
    pA = &a;    // pAは変数aを指す
    printf("変数aの値: %d\n", a);
    printf("変数aのアドレス: %p\n", &a);
    printf("変数bのアドレス: %p\n", &b);
    printf("ポインタpAの値 : %p\n", pA);    // 変数のアドレスが入っている
    printf("*pAの値: %d\n", *pA);   // ポインタを使って読み出す（★）
    printf("\n");

    *pA = 50;                       // ポインタを使って書き込む
    printf("*pAに50を代入しました。\n");
    printf("*pAの値: %d\n", *pA);
    printf("変数aの値: %d\n", a);   // 変数aの値も変化している
    printf("\n");

    b = 10;
    pA = &b;    // pAは変数bを指すように変更
    printf("pAを&bにしました。\n");
    printf("変数bの値: %d\n", b);
    printf("ポインタpAの値 : %p\n", pA);
    printf("*pAの値: %d\n", *pA);   // ★と同じだが、変数bの値になった

    return 0;
}
