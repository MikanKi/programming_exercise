// funcArray1.c
// 文字列処理と関数のポインタを使って、3 + 4 のような2項演算を行う
// if文を並べるのではなく、演算子とその処理関数の配列を使って実装する
// 2454403 フェリシア・アイヴィー

/* 実行結果

2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
6 min 9
6 min 9 は 6 です

2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
6 - 9
6 - 9 は -3 です

6 * 9
6 * 9 は 54 です

2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
6 / 9
6 / 9 は 0 です

2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
6 % 9
6 % 9 は 6 です

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2項演算の関数を幾つか用意して、「関数のポインタ」を使って呼び出す

// max: x,yの最大値を返す
int max(int x, int y)
{
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int min(int x, int y){
    if(x<y){
        return x;
    } else{
        return y;
    }
}

// add: x,yの加算をする
int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y){
    return x-y;
}

int mult(int x, int y){
    return x*y;
}

int divi(int x, int y){
    return x/y;
}

int mod(int x, int y){
    return x%y;
}


//
// 演算子の名前リストと関数のポインタ、それぞれの配列
//
char *opNames[] = { "max",  "+", "min", "-", "*", "/", "%"}; // 演算子
int (*calcFuncs[])(int, int) = { max, add, min, sub, mult, divi, mod }; // 処理関数

#define N_OPS (sizeof(calcFuncs) / sizeof(calcFuncs[0]))   // 演算子の数

// メイン
int main(void) {
    int i;
    char s1[10], s2[10], op[10]; // 入力文字列（バッファ溢れは考慮せず）
    int num1, num2, ans;

    while (1) {
        printf("2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)\n");
        if (scanf("%s %s %s", s1, op, s2) == 3) {
            num1 = atoi(s1); // オペランドを数値に変換
            num2 = atoi(s2);
            break;
        }
        printf("式が間違っています。\n");
    }

    // 該当する演算子を探す
    for (i = 0; i < N_OPS; i++) {
        if (strcmp(op, opNames[i]) == 0) {  // 演算子が一致したら
            ans = (*calcFuncs[i])(num1, num2); // その関数を呼び出す
            printf("%d %s %d は %d です\n", num1, op, num2, ans);
            return 0;   // ここで終了
        }
    }

    // ここに達するのは、for文が最後まで行って演算子が見つからない時
    printf("%s は定義されてない演算です\n", op);
    return 1;
}

