/*
  fibRecursive.c
  フィボナッチ数列を求める（再帰呼び出し版）
*/

#include <stdio.h>

// フィボナッチ数列の再帰呼び出し関数
// 漸化式をそのまま使っている
int fib(int m) {
    if (m == 0 || m == 1) {
        return 1;
    }
    return fib(m - 1) + fib(m - 2);  // 再帰呼び出しを実施
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
