#include <stdio.h>

int main (void){

    int x = 5;  // 0b0101


    // xの最下位ビットが0かどうかをチェックする（つもり）
    if ((x & 1) == 0) {  // どのように評価されるか？
        printf("True\n");
    } else {
        printf("False\n");
    }


    // xと2のORをとると7になるかどうかをチェックする（つもり）
    if ((x | 2) != 7) {  // どのように評価されるか？
        printf("True\n");
    } else {
        printf("False\n");
    }
}
