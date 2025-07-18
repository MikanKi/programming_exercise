// fileStat.c
// ファイルのメタ情報をstat()システムコールで取得する

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char *fname;    // ファイル名
    struct stat st; // stat()の結果を入れる構造体

    if (argc != 2) {
        fprintf(stderr, "usage: %s file_for_stat\n", argv[0]);
        return 1;
    }
    fname = argv[1];

    // stat()でファイルの情報を取得
    if (stat(fname, &st) < 0) {
        perror(fname);
        return 1;
    }

    // その内容（の一部）を表示
    printf("Filename: %s\n", fname);
    printf("Permission: %04o\n", st.st_mode & 07777); // 07777=0xFFF
    printf("File type: %d\n", (st.st_mode >> 12) & 0xF);
    printf("File size: %lld\n", st.st_size);	// 64bit整数

    return 0;
}
