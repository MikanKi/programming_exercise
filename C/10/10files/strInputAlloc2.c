// strInputAlloc1.c
// 入力された文字列をmallocで確保した領域に記憶する
// 今回はMAX_LINE行分の固定行数を入力する
// 2454403 フェリシア・アイヴィー

/* 実行結果

1 行目？
134345 rgrgh
2 行目？
1234 sgdf
3 行目？
*END*
入力されたもの:
  0(0x134f04080): "134345 rgrgh"
  1(0x134f04090): "1234 sgdf"

1 行目？
2345245 dffghd
2 行目？
1345 se
3 行目？
5 sfh
4 行目？
256456
5 行目？
354
入力されたもの:
  0(0x13af04080): "2345245 dffghd"
  1(0x13c004080): "1345 se"
  2(0x13af04090): "5 sfh"
  3(0x13c104080): "256456"
  4(0x13c104090): "354"

*/

#include <stdio.h>
#include <stdlib.h>     // malloc(),exit()を使うため
#include <string.h>

#define MAX_CHAR 100    // 1行の最大文字数(読み取る時のバッファ用)
#define LINES 5         // 行数

int main(void) {
    int i,limit=LINES;
    size_t len;             // 文字数
    char *ptr;              // malloc用
    char input[MAX_CHAR];   // 入力文字列
    char *strs[LINES];      // 行毎の記憶領域へのポインタ（アドレス）

    // 1行ずつ入力して、mallocした領域に格納する
    for (i = 0; i < LINES; i++) {
        printf("%d 行目？\n", i + 1);
        fgets(input, MAX_CHAR, stdin);      // 1行の入力を取得
        if(strcmp(input,"*END*\n")==0){
            limit = i;
            break;
        }

        len = strlen(input);                // 文字数を求める
        if (input[len - 1] == '\n') {       // 最後の改行を削除
            input[len - 1] = '\0';
            len--;      // 長さを調整
        }

        // mallocして、そこに入力文字列をコピー
        ptr = malloc(len + 1);      // +1を忘れないように！（終端文字の分）
        if (ptr == NULL) {
            fprintf(stderr, "%zdバイトのメモリ確保に失敗しました\n", len);
            exit(1);
        }
        strcpy(ptr, input);     // 入力をコピー
        strs[i] = ptr;          // そこを行毎のポインタの配列に入れる
    }

    // 入力を出力
    printf("入力されたもの:\n");
    for (i = 0; i < limit; i++) {
        printf("  %d(%p): \"%s\"\n", i, strs[i], strs[i]);
    }

    // mallocした領域を開放
    for (i = 0; i < limit; i++) {
        free(strs[i]);
    }

    return 0;
}
