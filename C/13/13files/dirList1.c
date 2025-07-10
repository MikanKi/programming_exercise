// dirList1.c
// 指定されたディレクトリにあるファイルの種類を表示する
// 通常ファイルとディレクトリしか判別できないバージョン

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
            default:      printf("その他"); break;
        }
        printf("\t%s\n", entry->d_name);  // ファイル名を表示
    }

    closedir(dirp);
}

// メイン
int main(int argc, char *argv[]) {
    char *dirname;

    if (argc > 1) {
        dirname = argv[1];
    } else {
        fprintf(stderr, "ディレクトリが指定されていません\n");
        exit(1);
    }

    listFiles(dirname);

    return 0;
}
