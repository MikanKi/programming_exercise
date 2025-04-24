// binary8.c
// 入力された整数の下位8ビット分を2進数で表示する

#include <stdio.h>

int main(void) {
    int num;   // 入力値
    int data;  // 下位8ビット分
    int i;     // ループ変数

    printf("整数を入力してください: ");
    scanf("%d", &num);

    data = num & 0xFF;  // 下位8ビットだけにする（不要かも）
    for (i = 7; i >= 0; i--) {
        printf("%d", (data >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(":");    // 区切り文字
        }
    }
    printf("\n");

    return 0;
}

