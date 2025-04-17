//calcSum.c
//2454403 フェリシア・アイヴィー

/*実行結果

123
234
345
456
567
678
789
890
0
合計は4082

*/

#include <stdio.h>

int main(void){
    //合計と数値を宣言
    int sum = 0,num;

    //数値が０でない場合、足し算を繰り返す
    do{
        scanf("%d",&num);
        sum = sum + num;
    }while(num != 0);

    //出力
    printf("合計は%d\n",sum);
    return 0;
}