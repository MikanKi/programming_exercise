// argSearch1.c
// コマンドの引数から特定の文字列を探す（完全一致）

#include <stdio.h>
#include <stdlib.h>     // exit()を使うため
#include <string.h>

int main(int argc, char *argv[]) {
    char *target;
    int found = 0;

    if (argc <= 2) {    // 引数が少なければ、使い方を表示して終了
        fprintf(stderr, "使い方: %s 検索語 検索対象1 ...\n", argv[0]);
        exit(1);        // プログラムを終了ステータス=1で終了
    }

    printf("引数の個数: %d\n", argc);
    target = argv[1];   // 第1引数は検索語

    // 文字列を検索
    for (int i = 2; i < argc; i++) {
        printf("argv[%d]: \"%s\"\n", i, argv[i]);
        if (strcmp(argv[i], target) == 0) {
            found = 1;
        }
    }

    printf("指定した文字列 \"%s\" ", target);
    if (found) {
        printf("が見つかりました！\n");
    } else {
        printf("は含まれていません。\n");
    }

    return 0;
}
