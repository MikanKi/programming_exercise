// filePerm.c
// ファイルのパーミッション情報を表示する
// 2454403 フェリシア・アイヴィー

/* 実行結果

% ./filePerm fileStat.c
fileStat.c      809     Mode:0x81A4 (0o100644) Owner:rw- Group:r-- Others:r-- 

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>   // stat()のために必要

// ファイルのモード情報のための共用体
typedef union mode {
    mode_t raw; // 全体をまとめてアクセスするとき（生データ）

    struct {    // 以下、ビットフィールドでビット単位でアクセス可能
        // other(bit2-0)
        unsigned int other_exec   : 1;
        unsigned int other_write  : 1;
        unsigned int other_read   : 1;

        // group(bit5-3)
        unsigned int group_exec    : 1;
        unsigned int group_write   : 1;
        unsigned int group_read    : 1;

        // owner(bit8-6)
        unsigned int owner_exec    : 1;
        unsigned int owner_write   : 1;
        unsigned int owner_read    : 1;

        // special(bit11-9)
        unsigned int sticky        : 1;
        unsigned int setgid        : 1;
        unsigned int setuid        : 1;

        // ファイルタイプ（bit12-15）
        unsigned int file_type     : 4;

        // 予約（ビット16以降）
        unsigned int reserved      : 16;
    } bits;
} ModeField;

// ファイルのモードビットの状態を表示
void printMode(ModeField *m) {
    printf("Mode:0x%04X (0o%06o) ", m->raw, m->raw);

    printf("Owner:%c%c%c ",
        m->bits.owner_read  ? 'r' : '-',
        m->bits.owner_write ? 'w' : '-',
        m->bits.owner_exec  ? 'x' : '-');

    printf("Group:%c%c%c ",
        m->bits.group_read ? 'r' : '-',
        m->bits.group_write ? 'w' : '-',
        m->bits.group_exec ? 'x' : '-'
    );

    printf("Others:%c%c%c ",
        m->bits.other_read ? 'r' : '-',
        m->bits.other_write ? 'w' : '-',
        m->bits.other_exec ? 'x' : '-'
    );







    if (m->bits.setuid || m->bits.setgid || m->bits.sticky) {
        printf("Special: ");
        if (m->bits.setuid)  printf("setuid ");
        if (m->bits.setgid)  printf("setgid ");
        if (m->bits.sticky)  printf("sticky ");
    }

    printf("\n");
}

// メイン
int main(int argc, char *argv[]) {
    struct stat st;     // stat()の情報を入れる構造体
    ModeField mf;       // st_modeを解釈するための共用体
    char *fname;        // ファイル名

    if (argc <= 1) {
        fprintf(stderr, "Usage: %s files...\n", argv[0]);
        exit(1);
    }

    fname = argv[1];
    // ファイルの情報を取得
    if (stat(fname, &st) != 0) {
        perror("stat");
        exit(2);
    }

    // 得られた情報を表示
    printf("%s\t", fname);          // ファイル名
    printf("%lld\t", st.st_size);

    mf.raw = st.st_mode;    // 共用体になっている構造体に代入
    printMode(&mf);         // ファイルのモードビットを表示

    return 0;
}
