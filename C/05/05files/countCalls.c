// countCalls.c
// 関数が呼び出された回数を記録する（staticを使う）
// 2454403 フェリシア・アイヴィー

/* 実行結果

関数呼出し回数:1 経過時間:1747271565秒 時刻:Thu Jan  1 09:00:00 1970

関数呼出し回数:2 経過時間:3秒 時刻:Thu May 15 10:12:45 2025

関数呼出し回数:3 経過時間:2秒 時刻:Thu May 15 10:12:48 2025

関数呼出し回数:4 経過時間:1秒 時刻:Thu May 15 10:12:50 2025

関数呼出し回数:5 経過時間:3秒 時刻:Thu May 15 10:12:51 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void countCalls(void) {
    static int count = 0;  // static変数: 関数が終了しても値を保持する
    static time_t lastTime = 0;  // 同上: 前回呼ばれた時刻(通算秒)

    int diff = time(NULL) - lastTime;  // 前回との差分を計算

    count++;
    printf("関数呼出し回数:%d 経過時間:%d秒 時刻:%s\n", count, diff, ctime(&lastTime));
    lastTime = time(NULL);
}

int main(void) {
    int i;

    for (i = 0; i < 5; i++) {   // 適当な回数繰り返す
        countCalls();           // 関数呼出し
        sleep(random() % 4);    // 0～3秒待つ
    }

    return 0;
}

