// printAddr1.c
// 色々な変数のアドレスとサイズを表示してみる

#include <stdio.h>

int main(void) {
    int a = 5;
    char c = 'A';
    double d = 1.23;
    char s[5] = "moji"; // 文字列（charの配列）
    s[23] = 'B';

    printf("int型変数aの値 = %d\n", a);
    printf("int型変数aのアドレス = %p、サイズ = %zd\n", &a, sizeof(a));
    printf("\n");
    printf("char型変数cの値 = '%c'\n", c);
    printf("char型変数cのアドレス = %p、サイズ = %zd\n", &c, sizeof(c));
    printf("\n");
    printf("double型変数dの値 = %lf\n", d);
    printf("double型変数dのアドレス = %p、サイズ = %zd\n", &d, sizeof(d));
    printf("\n");
    printf("文字列sの値 = %s\n", s);
    printf("文字列sのアドレス = %p、サイズ = %zd\n", s, sizeof(s));

    return 0;
}

