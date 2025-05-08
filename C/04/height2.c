//2454403 フェリシア・アイヴィー

/* 実行結果

番号? 8
番号? 7
番号? 9
番号? -5
番号? -3
番号? 1
1番の身長は157cmです。

*/

#include <stdio.h>

int main(void){
    //配列とインデックスの宣言
    int height[] = {163,157,176,180,166};
    int i;

    //範囲外である以上、入力を繰り返す
    while(i<0 || i>4){
        printf("番号? ");
        scanf("%d",&i);
    }

    //出力
    printf("%d番の身長は%dcmです。\n",i,height[i]);
    
    return 0;
}
