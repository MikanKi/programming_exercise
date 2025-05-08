/*
  handy.c
  Handy Graphicの簡単なサンプルプログラム
*/
#include <stdio.h>
#include <handy.h>  // Handy Graphicを使うとき必要

int main(void) {
    HgOpen(600, 400);         // Handy Graphicの初期化

    HgCircle(300, 200, 50);  // 円を描く
    HgGetChar();              // 1文字入力を待つ

    HgClose();                // Handy Graphicの終了処理

    return 0;
}

