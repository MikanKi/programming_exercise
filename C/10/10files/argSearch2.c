// argSearch1.c
// コマンドの引数から特定の文字列を探す（完全一致）
// 2454403 フェリシア・アイヴィー

/* 実行結果

% ./argSearch2 qwerty uiop 1234qwerty qwe erty qwerty780
引数の個数: 7
argv[2]: "uiop" 
argv[3]: "1234qwerty" *
argv[4]: "qwe" 
argv[5]: "erty" 
argv[6]: "qwerty780" *
指定した文字列 "qwerty" が見つかりました！

% ./argSearch2 str *.c                                  
引数の個数: 14
argv[2]: "argDump.c" 
argv[3]: "argSearch1.c" 
argv[4]: "argSearch2.c" 
argv[5]: "funcArray1.c" 
argv[6]: "funcBranch1.c" 
argv[7]: "funcBranch2.c" 
argv[8]: "funcSignal.c" 
argv[9]: "strArray.c" *
argv[10]: "strInput-temp.c" *
argv[11]: "strInput.c" *
argv[12]: "strInputAlloc1.c" *
argv[13]: "strInputAlloc2.c" *
指定した文字列 "str" が見つかりました！

*/

#include <stdio.h>
#include <stdlib.h>     // exit()を使うため
#include <string.h>

int main(int argc, char *argv[]) {
    char *target;
    int found = 0;
    int count = 0;

    if (argc <= 2) {    // 引数が少なければ、使い方を表示して終了
        fprintf(stderr, "使い方: %s 検索語 検索対象1 ...\n", argv[0]);
        exit(1);        // プログラムを終了ステータス=1で終了
    }

    printf("引数の個数: %d\n", argc);
    target = argv[1];   // 第1引数は検索語
    int tgt_len = strlen(target);

    for (int i = 2; i < argc; i++) {
        printf("argv[%d]: \"%s\" ", i, argv[i]);
        for(int j=0; j < strlen(argv[i]);j++){
            if(argv[i][j]== *target){
                target++;
                count++;
            } else {
                target = argv[1];
                count = 0;
            }
            if(count == tgt_len){
                found = 1;
                printf("*");
            }
        }
        printf("\n");
    }

    printf("指定した文字列 \"%s\" ", target);
    if (found) {
        printf("が見つかりました！\n");
    } else {
        printf("は含まれていません。\n");
    }

    return 0;
}
