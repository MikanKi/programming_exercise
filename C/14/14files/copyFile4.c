// copyFile4.c
// 標準入力から1文字ずつ読んで、標準出力へ書き出す
// 指定したファイルから読み出し、指定したファイルに出力する
// 2454403 フェリシア・アイヴィー

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c;      // 読み込んだ1文字（char型ではうまく動かない）
    char input[FILENAME_MAX];
    char output[FILENAME_MAX];


    printf("入力ファイル名？ ");
    scanf("%s",input);
    printf("出力ファイル名？ ");
    scanf("%s",output);

    FILE *ip = fopen(input,"r");
    if(ip == NULL){
        perror(input);
        exit(1);
    }

    FILE *op = fopen(output,"w");
    if(op == NULL){
        perror(output);
        exit(1);
    }

    // 1文字読み込みそれを出力に書き込むことを繰り返す
    while ((c = fgetc(ip)) != EOF) {     // EOFは-1と定義されている
        fputc(c, op);
    }

    fclose(ip);
    fclose(op);
    
    return 0;
}
