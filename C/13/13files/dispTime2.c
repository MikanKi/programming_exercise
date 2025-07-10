// dispTime2.c
// 現在時刻を表示する（秒未満の値も）
// 2454403 フェリシア・アイヴィー

/* 実行結果

現在時刻: 1752107544.446637  2025/7/10  (木)  9:32:24.446637  JST(+9)

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>   // gettimeofday()のため
#include <time.h>       // localtime()のため

int main(int argc, char *argv[]) {
    struct timeval tv;  // 秒とマイクロ秒での時刻が入る構造体
    struct tm *tp;      // 詳しい時刻情報を格納する構造体
    char *dow[7] = {"日","月","火","水","木","金","土"};

    // 現在時刻を取得（マイクロ秒単位で）
    if (gettimeofday(&tv, NULL) != 0) {
        perror("gettimeofday");
        exit(1);
    }

    // タイムゾーンを考慮して現地時間に変換
    tp = localtime(&tv.tv_sec);
    if (tp == NULL) {
        fprintf(stderr, "Error in localtime\n");
        exit(2);
    }

    // 表示
    printf("現在時刻: %ld.%06d  %d/%d/%d  (%s)  %d:%d:%d.%06d  %s(%+ld)\n",
            tv.tv_sec, tv.tv_usec,

            tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday,

            dow[tp->tm_wday],

            tp->tm_hour, tp->tm_min, tp->tm_sec, tv.tv_usec,

            tp->tm_zone, tp->tm_gmtoff / 3600);

    return 0;
}
