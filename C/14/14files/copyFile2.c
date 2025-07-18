// copyFile2.c
// 標準入力から1文字ずつ読んで、標準出力へ書き出す
// 英小文字をすべて英大文字に変換して出力する
// 2454403 フェリシア・アイヴィー

/* 実行結果

mY nAmE iS iVy
MY NAME IS IVY

*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int c;      // 読み込んだ1文字（char型ではうまく動かない）

    // 1文字読み込みそれを出力に書き込むことを繰り返す
    while ((c = fgetc(stdin)) != EOF) {     // EOFは-1と定義されている
        if(islower(c)>0){
            c = toupper(c);
        }
        fputc(c, stdout);
    }
    
    return 0;
}
