// dirList2.c
// 指定されたディレクトリにあるファイルの種類を表示する
// 通常ファイルとディレクトリしか判別できるバージョン
// 2454403 フェリシア・アイヴィー

/* 実行結果

% ./dirList2
ディレクトリ '.' の内容:
ディレクトリ    .
ディレクトリ    ..
ディレクトリ    dirList2.dSYM
通常ファイル    word9.txt
通常ファイル    word1kd.txt
通常ファイル    dispTime2
通常ファイル    find_file.py
通常ファイル    dirList2.c
通常ファイル    Makefile
通常ファイル    word236kd.txt
通常ファイル    dirList2
通常ファイル    shuffleLine
通常ファイル    bsTree1-temp.c
通常ファイル    dirList1.c
通常ファイル    word50kd.txt
通常ファイル    shuffleLine.c
通常ファイル    dispTime1
通常ファイル    dispTime1.c
通常ファイル    linkedList1-temp.c
通常ファイル    dirList1
通常ファイル    dispTime2.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>     // opendir(),readdir()などを使うため
#include <errno.h>      // errno変数を使うため

// 指定されたディレクトリの中にあるファイルの種類を表示する
void listFiles(char *dir) {
    DIR *dirp;      // opendir()が返すディレクトリストリームのポインタ
    struct dirent *entry = NULL; // readdir()が返す次のディレクトリエントリ構造体のポインタ

    // ディレクトリを読み出す
    dirp = opendir(dir);
    if (dirp == NULL) {
        fprintf(stderr, "ディレクトリ '%s' を開けませんでした: %s\n", dir, strerror(errno));
        exit(1);
    }

    // ディレクトリ内のエントリを1つずつ読み出す
    printf("ディレクトリ '%s' の内容:\n", dir);
    while ((entry = readdir(dirp)) != NULL) {
        switch (entry->d_type) {
            case DT_REG:  printf("通常ファイル"); break;
            case DT_DIR:  printf("ディレクトリ"); break;
            case DT_FIFO: printf("FIFO(名前付きパイプ)"); break;
            case DT_CHR: printf("キャラクタ型デバイス"); break;
            case DT_BLK: printf("ブロック型デバイス"); break;
            case DT_LNK: printf("シンボリックリンク"); break;
            case DT_SOCK: printf("ソケット"); break;
            case DT_WHT: printf("ホワイトアウト"); break;
            default:      printf("その他"); break;
        }
        printf("\t%s\n", entry->d_name);  // ファイル名を表示
    }

    closedir(dirp);
}

// メイン
int main(int argc, char *argv[]) {
    char *dirname;
    char string[2] = ".";

    if (argc > 1) {
        dirname = argv[1];
    } else {
        dirname = &string[0];
    }

    listFiles(dirname);

    return 0;
}
