// clickDraw1.c
// ウィンドウをクリック（タップ）した位置情報を得る

#include <handy.h>
#include <stdio.h>

int main(void) {
    hgevent *event;     // イベント情報が入る構造体へのポインタ

    // 初期化
    HgOpen(400.0, 400.0);
    HgSetWidth(1.0);                // 線の太さを1にセット
    HgSetEventMask(HG_MOUSE_DOWN);  // マウスのクリックを有効にする

    HgSetColor(HG_BLACK);  // これ以降は黒色で枠を描画
    for (;;) {  // 無限ループ
        event = HgEvent();  // イベント待ち
        if (event->type == HG_MOUSE_DOWN) { // クリックだったら
            // event->x, event->y に座標が入っている
            printf("click! x=%5.2f y=%5.2f\n", event->x, event->y);
            HgBox(event->x, event->y, 5.0, 5.0);  // 小さい四角を描く
        }
    }

    // 終了処理
    HgClose();
    return 0;
}
