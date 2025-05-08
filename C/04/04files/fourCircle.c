//2454403 フェリシア・アイヴィー
/*
  oneCircle.c
  青色の1つの円を描く
*/

#include <stdio.h>
#include <handy.h>

int main(void) {
    HgOpen(400, 400);  // Handy Graphicの初期化

    HgSetFillColor(HG_RED);        
    HgCircleFill(120, 120, 100, 1);
    
    HgSetFillColor(HG_BLUE);        // 塗りつぶしの色を青に
    HgCircleFill(120, 280, 100, 1); // 塗りつぶしありの円を描く

    HgSetFillColor(HG_GREEN);        
    HgCircleFill(280, 280, 100, 1);

    HgSetFillColor(HG_YELLOW);        
    HgCircleFill(280, 120, 100, 1);
    
    HgGetChar();  // 1文字入力を待つ
    HgClose();    // Handy Graphicの終了処理

    return 0;
}
