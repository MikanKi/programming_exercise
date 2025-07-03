// structCarPtr1.c
// srructCar1.cの構造体をポインタでアクセスするようにしてみたもの
// 出力と入力の一部は未完成

#include <stdio.h>
#include <string.h>

// 車の色の定義
#define C_UNKNOWN 0 // 不明。その他のような値は0にしておくと便利
#define C_WHITE 1   // 白色
#define C_BLACK 2   // 黒色
#define C_RED   3   // 赤色
#define C_BLUE  4   // 青色

// 自動車の属性を扱うための構造体を定義
struct car {
    int    num;         // ナンバー
    char   model[20];   // モデル名
    int    color;       // 色
    double gas;         // 燃費
};  // ここにはセミコロン;が必要

// 指定された構造体の内容を出力する
void printCar(struct car *pt) {
    printf("Number: %d\n",    pt->num);   // ナンバー




}

// 構造体のメンバの値を入力する
void inputCar(struct car *pt) {
    printf("ナンバー？ "); scanf("%d", &pt->num);




}

// メイン
int main(void) {
    struct car car1;    // 構造体の変数を宣言
    struct car car2;
    struct car car3;
    int i;
    struct car *pt1;            // 構造体を指すポインタ★
    struct car *pt2 = &car2;    // 宣言と同時に初期化もできる★
    struct car *pt3 = &car3;
    struct car *pts[3];         // ポインタの配列も作ることができる

    // 構造体を指すポインタを使う★
    pt1 = &car1;

    // 構造体のメンバに値を代入する★
    pt1->num = 1234;
    strcpy(pt1->model, "Skyline");  // strcpyで配列に入れる
    pt1->color = C_WHITE;
    pt1->gas = 9.5;

    // 構造体のポインタを関数の引数とした例1
    inputCar(pt2);  // inputCar(&car2); でも同じ

    // 構造体ごと代入（コピー）できる
    *pt3 = *pt1;    // memcpy(pt3, pt1, sizeof(struct car)); でも同じ
    
    // 構造体のポインタの配列の例
    pts[0] = pt1;
    pts[1] = pt2;
    pts[2] = pt3;

    // 構造体のポインタを関数の引数とした例2
    printCar(pt1);
    printf("\n");   // 行を空ける

    // 配列の要素を関数の引数にした場合
    for (i = 1; i < 3; i++) {
        printCar(pts[i]);
        printf("\n");   // 行を空ける
    }

    return 0;
}
