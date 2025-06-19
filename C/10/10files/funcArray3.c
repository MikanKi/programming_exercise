// funcArray3.c
// 文字列処理と関数のポインタを使って、3 + 4 のような2項演算を行う
// if文を並べるのではなく、演算子とその処理関数の配列を使って実装する
// 2454403 フェリシア・アイヴィー

/* 実行結果

% ./funcArray3
使い方: ./funcArray3 num1 operator num2

% ./funcArray3 9 max 6
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 max 6 は 9 です

% ./funcArray3 9 min 6
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 min 6 は 6 です

% ./funcArray3 9 + 6  
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 + 6 は 15 です

% ./funcArray3 9 - 6
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 - 6 は 3 です

% ./funcArray3 9 '*' 6
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 * 6 は 54 です

% ./funcArray3 9 / 6  
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 / 6 は 1 です

% ./funcArray3 9 % 6
2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)
9 % 6 は 3 です

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
int main(int argc, char *argv[]) {
    int i;
    char s1[10], s2[10], op[10]; // 入力文字列（バッファ溢れは考慮せず）
    int num1, num2, ans;

    if (argc < 4) {    // 引数が少なければ、使い方を表示して終了
        fprintf(stderr, "使い方: %s num1 operator num2\n", argv[0]);
        exit(1);        // プログラムを終了ステータス=1で終了
    }

    sprintf(s1,"%s",argv[1]);
    sprintf(op,"%s",argv[2]);
    sprintf(s2,"%s",argv[3]);

    while (1) {
        printf("2項演算子の式？ (例: スペースで区切って、 3 + 5 や 3 max 5)\n");
        if (argc == 4) {
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

