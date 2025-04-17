// output.c
// 色々な種類のデータを表示、また
// 変数の型毎のサイズ（メモリ上の大きさ）を表示する
#include <stdio.h>

int main(void) {
    int a = 1;
    int b = 2;

    printf("10進数の 10 は %d です\n", 10);
    printf("8進数の 010 は %d です\n", 010);
    printf("16進数の 0x10 は %d です\n", 0x10);
    printf("16進数の 0xF は %d です\n", 0xF);
    printf("2進数の 0b01001011 は %d です\n", 0b01001011);
    printf("\n");

    printf("%d は整数、%f は小数です\n", 123, 10.5);
    printf("%c は文字、%d は整数です\n", 'A', 123);
    printf("%c は文字、%s は文字列です\n", 'S', "String Data");
    printf("\n");

    printf("short型のサイズは %lu バイトです\n", sizeof(short));
    printf("int型のサイズは %lu バイトです\n", sizeof(int));
    printf("long型のサイズは %lu バイトです\n", sizeof(long));
    printf("long long型のサイズは %lu バイトです\n", sizeof(long long));
    printf("float型のサイズは %lu バイトです\n", sizeof(float));
    printf("double型のサイズは %lu バイトです\n", sizeof(double));
    printf("long double型のサイズは %lu バイトです\n", sizeof(long double));
    printf("int型の変数aのサイズは %lu バイトです\n", sizeof(a));
    printf("int型の式a+bのサイズは %lu バイトです\n", sizeof(a+b));

    return 0;
}
