// clickDraw3.c
// ウィンドウをクリック（タップ）した位置情報を得る
// 2454403 フェリシア・アイヴィー

#include <handy.h>
#include <stdio.h>
#include <stdlib.h>

struct node{
    double x;  // x座標
    double y;  // y座標
    struct node *next;  // 次のノードへのポインタ
};

struct list{
    struct node *head;  // リストの先頭へのポインタ
};

void addNode(struct list *ls, double x, double y){
    struct node *new;
    struct node *tail;

    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL){
        perror("addNode");
        exit(1);
    }

    new->x = x;
    new->y = y;
    new->next = NULL;

    if(ls->head == NULL){
        ls->head = new;
    } else {
        tail = ls->head;
        while (tail->next != NULL){
            tail = tail->next;
        }
        tail->next = new;
    }
}

void lineNode(struct list *ls){
    struct node *tail;

    if(ls->head == NULL){
        return;
    }

    HgSetColor(HG_RED);
    HgSetWidth(3);

    tail = ls->head;
    HgMoveTo(tail->x,tail->y);
    tail = tail->next;
    while (tail != NULL){
        HgLineTo(tail->x,tail->y);
        HgSleep(0.1);
        tail = tail->next;
    }
}

int main(void) {
    struct list point = {NULL};
    hgevent *event;     // イベント情報が入る構造体へのポインタ
    
    // 初期化
    HgOpen(400.0, 400.0);
    HgSetFillColor(HG_RED);
    HgBoxFill(0,0,20,20,0);
    HgSetWidth(1.0);                // 線の太さを1にセット
    HgSetEventMask(HG_MOUSE_DOWN);  // マウスのクリックを有効にする

    HgSetColor(HG_BLACK);  // これ以降は黒色で枠を描画
    for (;;) {  // 無限ループ
        event = HgEvent();  // イベント待ち
        if (event->type == HG_MOUSE_DOWN) { // クリックだったら
            // event->x, event->y に座標が入っている
            printf("click! x=%5.2f y=%5.2f\n", event->x, event->y);
            HgBox(event->x, event->y, 5.0, 5.0);  // 小さい四角を描く
            if(event->x <= 20 && event->y <= 20){
                lineNode(&point);
                HgGetChar();
                break;
            } else {
                addNode(&point, event->x, event->y);
            }
        }
    }

    // 終了処理
    HgClose();
    return 0;
}
