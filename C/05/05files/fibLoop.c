/*
  fibLoop.c
  フィボナッチ数列を求める（ループ版）
*/

#include <stdio.h>

// フィボナッチ数列を求める関数
// 定義に従って、ループで処理する
int fib(int m) {
    int a0, a1, a2;
    int i;

    a0 = 1;
    a1 = 1;
    for (i = 0; i < m; i++) {
        a2 = a1 + a0;
        a0 = a1;
        a1 = a2;
    }
    return a0;
}

int main(void) {
    int n, i;

    printf("n = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("%d\n", fib(i));
    }

    return 0;
}
