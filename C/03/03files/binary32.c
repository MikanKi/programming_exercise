// binary32.c
// 入力された整数の下位32ビット分を2進数で表示する
// 2454403 フェリシア・アイヴィー

/* 実行結果

整数を入力してください: 143264538765
0101:1011:0011:1011:0110:0000:1000:1101

*/

#include <stdio.h>

int main(void) {
    int num;   // 入力値
    int data;  // 下位8ビット分
    int i;     // ループ変数

    printf("整数を入力してください: ");
    scanf("%d", &num);

    data = num & 0xFFFFFFFF;  // 下位8ビットだけにする（不要かも）
    for (i = 31; i >= 0; i--) {
        printf("%d", (data >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(":");    // 区切り文字
        }
    }
    printf("\n");

    return 0;
}

