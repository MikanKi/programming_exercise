//shopping.c
//2454403 フェリシア・アイヴィー

/* 実行結果

手持ちの金額:1530
単価:162
個数:5
買える。おつりは720円。

手持ちの金額:1250 
単価:170
個数:10
買えない。7個までなら買える。

*/

#include <stdio.h>

int main(void){
    int money,price,item;

    //入力
    printf("手持ちの金額:");
    scanf("%d",&money);

    printf("単価:");
    scanf("%d",&price);

    printf("個数:");
    scanf("%d",&item);

    //結果の判断
    if (money/price >= item){
        printf("買える。おつりは%d円。\n",money - (price*item));
    } else {
        printf("買えない。%d個までなら買える。\n",money/price);
    }
    
    return 0;
}
