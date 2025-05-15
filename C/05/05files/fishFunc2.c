/*
  fish.c
  左右の両端で跳ね返る魚
*/
//2454403 フェリシア・アイヴィー

#include <stdio.h>
#include <math.h>
#include <handy.h>

void fishDir(double x, double y, double size, int dir){
    if(dir==-1){
        int i;

        // 魚を描く
        HgSetColor(HG_RED);     // 線の色を赤色に
        HgSetFillColor(HG_RED); // 塗りつぶしの色を赤色に
        HgFanFill(x, y, size, 1.25 * M_PI, 0.75 * M_PI, 0);  // アタマを描く
        HgMoveTo(x + size, y);
        HgLineTo(x + size * 3.0, y);        // 背骨
        HgLineTo(x + size * 4.0, y - size); // 尾ひれ1
        HgMoveTo(x + size * 3.0, y);
        HgLineTo(x + size * 4.0, y + size); // 尾ひれ2
        HgSetFillColor(HG_WHITE);           // 白色に
        HgCircleFill(x + size / 3.0, y + size / 2.0, size / 4.0, 0); // 目を入れる
        HgSetColor(HG_RED);                 // 赤色に
        for (i = 0; i < 5; i++) {           // 肋骨
            HgLine(x + size * 1.2 + i * size / 3.0, y - size / 2.0,
                   x + size * 1.2 + i * size / 3.0, y + size / 2.0);
        }
    } else {
        int i;

        // 魚を描く
        HgSetColor(HG_RED);     // 線の色を赤色に
        HgSetFillColor(HG_RED); // 塗りつぶしの色を赤色に
        HgFanFill(x, y, size, 0.25 * M_PI, 1.75 * M_PI, 0);  // アタマを描く
        HgMoveTo(x - size, y);
        HgLineTo(x - size * 3.0, y);        // 背骨
        HgLineTo(x - size * 4.0, y - size); // 尾ひれ1
        HgMoveTo(x - size * 3.0, y);
        HgLineTo(x - size * 4.0, y + size); // 尾ひれ2
        HgSetFillColor(HG_WHITE);           // 白色に
        HgCircleFill(x - size / 3.0, y + size / 2.0, size / 4.0, 0); // 目を入れる
        HgSetColor(HG_RED);                 // 赤色に
        for (i = 0; i < 5; i++) {           // 肋骨
            HgLine(x - size * 1.2 - i * size / 3.0, y - size / 2.0,
                   x - size * 1.2 - i * size / 3.0, y + size / 2.0);
        }
    }
}

// メイン
int main(void) {
    double x, y, size, dx, dy; // 1匹の魚の情報
    int count=0;

    // 初期化
    HgOpen(400.0, 400.0);

    x = 200.0;         // x, y 座標の初期位置
    y = 200.0;
    size = 10.0;       // アタマの半径
    dx = -0.9 * size;  // x 方向の移動速度
    dy = 0.5 * size;   // y 方向の移動速度

    while (1) { // 無限ループにつき、グラフィックのウィンドウを閉じて終了
        HgClear();           // 画面を消去
        
        //何回壁に衝突したかによってどの方向に向いているかを決める
        if(count%2==0){
            fishDir(x,y,size,-1);
        } else {
            fishDir(x,y,size,1);
        }

        // 左右方向の壁との衝突判定と移動処理
        if (x + dx < size || x + dx > (400.0 - size)) {
            dx = -dx;
            count++;
        }
        x += dx;
        // 上下方向の壁との衝突判定と移動処理
        if (y + dy < size || y + dy > (400.0 - size)) {
            dy = -dy;
        }
        y += dy;

        HgSleep(0.1);  // 少し待つ
    }
}
