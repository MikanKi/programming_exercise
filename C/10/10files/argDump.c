// argDump.c
// コマンドラインの引数を表示する

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("引数の個数: %d\n", argc);

    // argv[0]は実行時のコマンド名が入る
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: \"%s\"\n", i, argv[i]);
    }

    return 0;
}
