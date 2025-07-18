// copyFile1.c
// 標準入力から1文字ずつ読んで、標準出力へ書き出す
// 最も基本的なもの

#include <stdio.h>

int main(int argc, char *argv[]) {
    int c;      // 読み込んだ1文字（char型ではうまく動かない）

    // 1文字読み込みそれを出力に書き込むことを繰り返す
    while ((c = fgetc(stdin)) != EOF) {     // EOFは-1と定義されている
        fputc(c, stdout);
    }
    
    return 0;
}
