// fishStruct1.c
// 左右の両端で跳ね返る魚
// 魚の情報を構造体にしたもの
// 2454403 フェリシア・アイヴィー

#include <handy.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define XSIZE   400.0   // 描画ウィンドウの横方向のサイズ
#define YSIZE   400.0   // 描画ウィンドウの縦方向のサイズ
#define NUM_FISH 10

// 魚の情報を入れる構造体を定義（typedefで Fish型にしておく）
typedef struct fish {
    double x, y;    // 魚の位置
    double size;    // 魚のサイズ
    double dx, dy;  // 魚の移動速度（ベクトル）
} Fish;

// 指定された値をセットした Fish型の値を返す
Fish fishSetup(void) {
    Fish fish;  // fish 変数を用意する
    double angle;

    fish.x = rand() % (int)(XSIZE * 0.9) + (XSIZE * 0.05);
    fish.y = rand() % (int)(YSIZE * 0.9) + (YSIZE * 0.05);
    angle = (rand() % (int)(2.0 * M_PI * 100.0));
    fish.size = rand() % 20 + 5.0;
    fish.dx = cos(angle) * fish.size;
    fish.dy = sin(angle) * fish.size / 2.0;
    

    return fish;
}

// 移動したあとの Fish 変数を返す
Fish fishMove(Fish fish) {
    fish.x += fish.dx;
    fish.y += fish.dy;
    return fish;
}

// 1匹の魚を描く(左向き)
void fishLeft(Fish f) {
    int i;

    HgSetColor(HG_RED);     // 線の色を赤色に
    HgSetFillColor(HG_RED); // 塗りつぶしの色を赤色に
    HgFanFill(f.x, f.y, f.size, 1.25 * M_PI, 0.75 * M_PI, 0); // アタマを描く
    HgMoveTo(f.x + f.size, f.y);
    HgLineTo(f.x + f.size * 3.0, f.y);                      // 背骨
    HgLineTo(f.x + f.size * 4.0, f.y - f.size);             // 尾ひれ1
    HgMoveTo(f.x + f.size * 3.0, f.y);
    HgLineTo(f.x + f.size * 4.0, f.y + f.size);             // 尾ひれ2
    HgSetFillColor(HG_WHITE);                               // 白色に
    HgCircleFill(f.x + f.size / 3.0, f.y + f.size / 2.0, f.size / 4.0, 0); // 目を入れる
    HgSetColor(HG_RED);                                     // 赤色に
    for (i = 0; i < 5; i++) {                               // 肋骨
        HgLine(f.x + f.size * 1.2 + i * f.size / 3.0, f.y - f.size / 2.0,
               f.x + f.size * 1.2 + i * f.size / 3.0, f.y + f.size / 2.0);
    }
}

// 1匹の魚を描く(右向き)
void fishRight(Fish f) {
    int i;

    HgSetColor(HG_RED);     // 線の色を赤色に
    HgSetFillColor(HG_RED); // 塗りつぶしの色を赤色に
    HgFanFill(f.x, f.y, f.size, 0.25 * M_PI, 1.75 * M_PI, 0); // アタマを描く
    HgMoveTo(f.x - f.size, f.y);
    HgLineTo(f.x - f.size * 3.0, f.y);                      // 背骨
    HgLineTo(f.x - f.size * 4.0, f.y - f.size);             // 尾ひれ1
    HgMoveTo(f.x - f.size * 3.0, f.y);
    HgLineTo(f.x - f.size * 4.0, f.y + f.size);             // 尾ひれ2
    HgSetFillColor(HG_WHITE);                               // 白色に
    HgCircleFill(f.x - f.size / 3.0, f.y + f.size / 2.0, f.size / 4.0, 0); // 目を入れる
    HgSetColor(HG_RED);                                     // 赤色に
    for (i = 0; i < 5; i++) {                               // 肋骨
        HgLine(f.x - f.size * 1.2 - i * f.size / 3.0, f.y - f.size / 2.0,
               f.x - f.size * 1.2 - i * f.size / 3.0, f.y + f.size / 2.0);
    }
}

void fishMark (Fish f){
    HgSetColor(HG_BLUE);
    HgCircle(f.x,f.y,f.size*1.4);
}

int tooClose(Fish f1, Fish f2){
    if(hypot(f2.x-f1.x,f2.y-f1.y)>(f1.size+f2.size) || f2.dx == f1.dx){
        return 0;
    } else {
        return 1;
    }
}

// メイン
int main(int argc, char *argv[]) {
    srandom(time(NULL));
    Fish fish[NUM_FISH];  // 構造体Fish型の変数を用意する
    int i,j;

    // 初期化
    HgOpen(XSIZE, YSIZE);

    // 魚の初期値をセットする
    for(i=0; i<NUM_FISH; i++){
        fish[i] = fishSetup();
    }
    

    while (1) { // 無限ループにつき、グラフィックのウィンドウを閉じて終了
        HgClear();  // 画面を消去

        for(j=0;j<NUM_FISH;j++){

            // 魚の描画
            if (fish[j].dx > 0.0) {
                fishRight(fish[j]);   // 右向きの魚を描く
            } else {
                fishLeft(fish[j]);    // 左向きの魚を描く
            }

            if(j==0){
                fishMark(fish[j]);
            }

            // 左右方向の壁との衝突判定
            if ((fish[j].x < fish[j].size && fish[j].dx <= 0.0) || (fish[j].x > (XSIZE - fish[j].size) && fish[j].dx > 0)) {
                fish[j].dx = -fish[j].dx;
            }
            if (fish[j].y < fish[j].size || fish[j].y > (YSIZE - fish[j].size)) {
                fish[j].dy = -fish[j].dy;
            }

            // 移動処理
            fish[j] = fishMove(fish[j]);
        }

        for(j=1; j<NUM_FISH;j++){
            if(tooClose(fish[0],fish[j])==1){
                fish[j].dx = fish[0].dx;
                fish[j].dy = fish[0].dy;
            }
        }

        HgSleep(0.1);           // 少し待つ
    }
}
