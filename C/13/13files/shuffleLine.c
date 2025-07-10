// shuffleLine.c
// 標準入力の行をシャッフルして出力する
// -d 100 とかのオプションで100分の1の確率で重複単語を作る

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES  500000   // 行の最大数
#define MAX_LENGTH 1000     // 1行の最大文字数

#define DUP_PRB 100         // 重複させる割合

int main(int argc, char *argv[]) {
    char *words[MAX_LINES];     // 入力行へのポインタの配列
    char buffer[MAX_LENGTH];    // 入力文字バッファ
    int count = 0;              // 単語数
    int optD = 0;       // いくつかの単語を重複させるオプション
    int dupRate;        // 単語を重複させる割合（dupRate分の1）

    // オプション解釈
    if (argc == 3 && strcmp(argv[1], "-d") == 0) {
        optD = 1;   // duplicate mode
        dupRate = atoi(argv[2]);
    }

    // 乱数初期化
    //srandom((unsigned int)time(NULL));

    // 標準入力から読み込む
    while (fgets(buffer, sizeof(buffer), stdin) != NULL && count < MAX_LINES) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';  // 最後の改行を削除
        }
        // 行を格納するメモリを確保して記憶する
        words[count] = malloc(strlen(buffer) + 1);
        if (words[count] == NULL) {
            fprintf(stderr, "メモリ確保に失敗しました\n");
            exit(1);
        }
        strcpy(words[count], buffer);
        count++;
    }

    // フィッシャー・イェーツのシャッフルアルゴリズムでバラバラの順番に
    for (int j = 0; j < 10; j++) {   // 複数回やって重複を増やす
        for (int i = count - 1; i > 0; i--) {
            char *tmp;
            int k = random() % (i + 1);
            if (optD && random() % dupRate == 0) {
                // 一定の確率で、行のポインタをコピー（同じ単語にする）
                //fprintf(stderr, "dup %d\n", i);
                words[k] = words[i];
            } else {
                // 行のポインタを入れ替え
                tmp = words[i];
                words[i] = words[k];
                words[k] = tmp;
            }
        }
    }

    // 結果を出力
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
