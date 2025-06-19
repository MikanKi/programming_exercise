// strArray.c
// 複数の文字列を配列で記憶する方法の例

#include <stdio.h>

#define LENGTH 30   // 文字列の最大サイズ

int main(void) {
    int i;
    // ポインタの配列
    char *strs[] = { "No1", "no.2", "3banme", "4", "sono5" };
    int strsSize = sizeof(strs) / sizeof(char *);

    // 2次元配列
    char string[][LENGTH] = { "No1", "no.2", "3banme", "4", "sono5" };
    int stringSize = sizeof(string) / (LENGTH * sizeof(char));

    printf("ポインタの配列:\n");
    for (i = 0; i < strsSize; i++) {
        printf("  %d: \"%s\"\n", i, strs[i]);
    }

    printf("2次元配列:\n");
    for (i = 0; i < stringSize; i++) {
        printf("  %d: \"%s\"\n", i, string[i]);
    }

    return 0;
}
