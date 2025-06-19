// funcSignal.c
// 関数のポインタを使った例
// シグナルを受け取ると事前に設定した関数を呼び出す

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// シグナル処理関数その1: 表示だけして元に戻る
void signalHandler(int sig) {
    printf("\nsignal=%d を受信しました。\n", sig);
}

// シグナル処理関数その2： プログラムを終了する
void signalHandlerExit(int sig) {
    printf("\nsignal=%d を受信しました。\n", sig);
    if (sig == SIGINT) {
        printf("SIGINT (Ctrl+C) につき、プログラムを終了します。\n");
    } else if (sig == SIGTERM) {
        printf("SIGTERM につき、プログラムを終了します。\n");
    }
    exit(sig); // プログラム終了
}

// メイン
int main(void) {
    int n = 0;

    // いくつかのsinalについて、関数のポインタ（アドレス）を登録
    signal(SIGINT, signalHandlerExit);    // Ctrl-C で送られるシグナル
    signal(SIGTERM, signalHandlerExit);   // kill コマンドで送られるシグナル
    signal(SIGQUIT, signalHandler);       // Ctrl-\ で送られるシグナル
    signal(SIGUSR1, signalHandler);       // kill -USR1 コマンドで送られるシグナル

    printf("このプログラムのプロセスIDは %d です\n", getpid()); // プロセスIDを表示
    printf("Ctrl-C や kill コマンドでシグナルを送信してください\n");
    // 何か適当な処理を行っておく
    while (1) {
        printf("%d", n++ % 10); // 0～9を繰り返す
        fflush(stdout);         // すぐにターミナルに出力
        sleep(1);               // 少し時間をおく
    }

    return 0;
}
