// inputKai.c
// scanf("%d");で、数字以外が来た時に対応するように改良したもの

#include <stdio.h>

int main(void) {
    int n;

    // 入力処理
    while (1) {  // 無限ループ
        printf("整数を入力してください: ");
        if (scanf("%d", &n) == 1) {  // 1個が正しく変換できたかチェック
            break;  // 正しい入力なので無限ループを抜ける
        } else {
            printf("不正な入力です。もう一度入力してください。\n");
            while (getchar() != '\n')
                ;  // 行末までの入力バッファを全て読み飛ばす
            continue;  // 最初に戻る
        }
    }
    
    // 出力処理
    printf("入力された整数: %d\n", n);
    
    return 0;
}
