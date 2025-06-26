// structCar1.c
// 構造体の基本と使い方
// 2454403 フェリシア・アイヴィー

/* 実行結果

ナンバー? 6969
モデル名? Egoista 
色の番号? 3
燃費? 6.9
Number: 1234
Model: Skyline
Color: 1
Nenpi: 9.5

Number: 2345
Model: Corolla
Color: 3
Nenpi: 18.2

Number: 6969
Model: Egoista
Color: 3
Nenpi: 6.9

sizeof(struct car) = 40
sizeof(cars) = 120

*/

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

// また car_t型を定義する（struct carと同じ扱い)
typedef struct car car_t;


// 指定された構造体の内容を出力する（1つずつ書くしかない）
void printCar(struct car c) {
    printf("Number: %d\n", c.num);      // ナンバー
    printf("Model: %s\n", c.model);     // モデル名
    printf("Color: %d\n", c.color);     // 色は番号で出力
    printf("Nenpi: %0.1lf\n", c.gas);   // 燃費
}

struct car inputCar(void){
    car_t c;

    printf("ナンバー? ");
    scanf("%d",&c.num);

    printf("モデル名? ");
    scanf("%s",c.model);

    printf("色の番号? ");
    scanf("%d",&c.color);

    printf("燃費? ");
    scanf("%lf",&c.gas);

    return c;
}

// メイン
int main(void) {
    struct car car1;    // 構造体の変数を1つ宣言
    struct car car2 = { 2345, "Corolla", C_RED, 18.2 };  // 初期化もできる
    struct car car3;
    struct car cars[3]; // 配列も作ることができる
    int i;

    // 構造体のメンバに値を代入する
    car1.num = 1234;
    strcpy(car1.model, "Skyline");  // strcpyで配列に入れる
    car1.color = C_WHITE;
    car1.gas = 9.5;
    // 現在のコンパイラでは、一気にメンバに代入することもできる
    car1 = (struct car){1234, "Skyline", C_WHITE, 9.5};

    // 構造体ごと代入（コピー）できる
    car3 = inputCar();
    
    // 配列も普通の変数と同じように扱える
    cars[0] = car1;
    cars[1] = car2;
    cars[2] = car3;

    // 関数の引数にもできる
    printCar(car1);
    printf("\n");   // 行を空ける

    // 配列を関数の引数にした場合
    for (i = 1; i < 3; i++) {
        printCar(cars[i]);
        printf("\n");   // 行を空ける
    }

    // 構造体のサイズを求める
    printf("sizeof(struct car) = %zd\n", sizeof(struct car));
    printf("sizeof(cars) = %zd\n", sizeof(cars));

    return 0;
}
