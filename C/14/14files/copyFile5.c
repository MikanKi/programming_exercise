// copyFile5.c
// 標準入力から1文字ずつ読んで、標準出力へ書き出す
// コマンドラインの第1引数で指定したファイル名から入力し、第2引数で指定したファイル名のファイルに出力する
// 2454403 フェリシア・アイヴィー

/* 実行結果

./copyFile5                     
./copyFile5 (インプットファイル) (アウトプットファイル) として記入

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int c;      // 読み込んだ1文字（char型ではうまく動かない）
    char input[FILENAME_MAX];
    char output[FILENAME_MAX];

    if(argc!=3){
        fprintf(stderr,"./copyFile5 (インプットファイル) (アウトプットファイル) として記入\n");
        exit(1);
    }

    sprintf(input,"%s",argv[1]);
    sprintf(output,"%s",argv[2]);

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
