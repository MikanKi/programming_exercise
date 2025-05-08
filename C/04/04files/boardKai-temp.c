//2454403 フェリシア・アイヴィー
/*
  boardKai.c
  9x9のゲーム盤にランダムにコマを配置し、
  縦か横（か斜め）に4つ並んでいるか判定する
*/

/* 実行結果

1 0 0 1 0 0 0 1 0 
0 1 0 0 1 1 1 1 0 
1 1 0 1 1 0 1 0 0 
1 0 1 0 1 0 0 0 0 
0 0 0 1 0 0 0 0 0 
0 1 0 0 1 1 1 1 0 
1 1 0 1 0 0 0 1 0 
1 1 1 0 1 0 1 0 0 
1 1 0 0 0 0 1 0 1 
BINGO!(yoko1)
BINGO!(yoko5)
BINGO!(tate1)
BINGO!(naname21)

*/

#include <stdio.h>
#include <stdlib.h>  // random関数を使うために必要
#include <time.h>    // time関数を使うために必要

#define KOMASU 25    // 何個のコマ(1)を置くか

int main(void) {
    int board[9][9] = {};  // 盤、0は駒無し、1は駒あり、初期状態はすべて0
                           // 0で埋めておくために、{}で初期化している
    int x, y, z;  // コマを配置する座標(yが行)
    int koma;  // 配置するコマの個数を数えるカウンタ変数
    int count;

    srandom(time(NULL));  // 乱数を現在時刻で初期化する

    // KOMASU個のコマをランダムな座標に配置する
    koma = 0;
    do {
        x = random() % 9;        // xの値を0〜8の乱数値とする
        y = random() % 9;        // yの値を0〜8の乱数値とする
        if (board[y][x] == 0) {  // (x,y)の位置にコマがなければ
            board[y][x] = 1;     // コマ有りにする
            koma++;              // 置いたコマの個数を1増やす
        }
    } while (koma < KOMASU);  // KOMASUのコマを置くまで繰り返す

    // 盤の表示
    for (y = 0; y < 9; y++) {
        for (x = 0; x < 9; x++) {
            printf("%d ", board[y][x]);
        }
        printf("\n");  // 1行分表示したら改行する
    }

    // BINGO状態を判定する

    /* この部分を書いて完成させよ */

    //横判定
    for(y=0;y<9;y++){
        //行を変えるとcountを0に戻す
        count = 0;
        for(x=0;x<9;x++){
            //1を見つけたらcountを増やす
            if(board[y][x] == 1){
                count++;
                //連続で4つの1を見つけたらBINGO判定
                if(count==4){
                    printf("BINGO!(yoko%d)\n",y);
                    count=0;
                }
                //次の値が1じゃなかったら、countを0に戻す
                if(board[y][x+1]==0){
                    count=0;
                }
            }
        }
    }

    //縦判定 (横判定と同じが、xとyを入れ替えただけ)
    for(x=0;x<9;x++){
        count = 0;
        for(y=0;y<9;y++){
            if(board[y][x] == 1){
                count++;
                if(count==4){
                    printf("BINGO!(tate%d)\n",x);
                    count=0;
                }
                if(board[y+1][x]==0){
                    count=0;
                }
            }
        }
    }

    //斜め判定
    for(y=0;y<9;y++){
        //行ずつ判定する
        count = 0;
        for(x=0;x<9;x++){
            //1を見つけたらcountを増やし、判定を行う
            if(board[y][x] == 1){
                count++;
                //右下に行く斜め判定
                if(x<=4){
                    for(z=1;z<4;z++){
                        //右下に1が見つかったら、countを増やす
                        if(board[y+z][x+z]==1){
                            count++;
                        }
                        //見つからなかったら、countを0に戻し、判定を止める(ループから抜ける)
                        else{
                            count=0;
                            break;
                        }
                    }
                }
                //左下に行く斜め判定
                if(x>=4){
                    for(z=1;z<4;z++){
                        //左下に1が見つかったら、countを増やす
                        if(board[y+z][x-z]==1){
                            count++;
                        }
                        //見つからなかったら、countを0に戻し、判定を止める(ループから抜ける)
                        else{
                            count=0;
                            break;
                        }
                    }
                }
                //連続で4つの1を見つけたらBINGO判定
                if(count==4){
                    //一番上の1の座標を出力する
                    printf("BINGO!(naname%d %d)\n",y,x);
                    count=0;
                }
            }
        }
    }

    return 0;
}
